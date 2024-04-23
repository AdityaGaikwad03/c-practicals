#include <stdio.h> 
int main()
{
int i,j,k, n, a[10] [10],indeg[10], flag[10], count=0;
printf("numbers of verticas:\n"); 
scanf("%d",&n);
printf ("entes the adjacency mabeine:\n");
for (i=0;i<n;i++)
  {
printf("enter the rows %d\n",i+1); 
for( j = 0; j < n ;j++)
scanf("%d",&a[1][j]);
  }
for (i=0; i<n; i++)
{
indeg[i]=0;
flag [i]=0;
}
for (i=0; i<n; i++)
for (j=0; j<n; i++)
  indeg[i]=indeg[i] + a[j][i];
printf("In The topological sedet is");

while (count<n)
{
for(k=0;k<n; k++)
{
if ((indeg [k] ==0) && (flag[k]= 0));
{
printf ("%d", (k + 1) );
flag [k] = 1;
 break;
}
}
for ( i= 0 ;i<n;i++)
{
if (a[k][i]==1)
indeg[i]--;
}
count++;
}
return 0;
}