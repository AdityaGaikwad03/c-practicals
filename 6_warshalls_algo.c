#include<stdio.h>

void floydWarshall(int graph[][10], int n)
{
   int dist[10][10], i, j, k;

   // Initialize the solution matrix same as input graph matrix.
   for (i = 0; i < n; i++)
   for (j = 0; j < n; j++)
   dist[i][j] = graph[i][j];

   // Pick all vertices as source one by one
   for (k = 0; k < n; k++)
   {
      // Pick all vertices as destination for the
      // above picked source
      for (i = 0; i < n; i++)
      {
         // Pick all vertices as source one by one
         for (j = 0; j < n; j++)
         {
            // If vertex k is on the shortest path from
            // i to j, then update the value of dist[i][j]
            if (dist[i][k] + dist[k][j] < dist[i][j])
            dist[i][j] = dist[i][k] + dist[k][j];
         }
      }
   }

   // Print the shortest distance matrix
   printSolution(dist, n);
}

// A utility function to print the solution
printSolution(int dist[][10], int n)
{
   int i, j;
   printf("Following matrix shows the shortest distances"
          " between every pair of vertices \n");
   for (i = 0; i < n; i++)
   {
      for (j = 0; j < n; j++)
      {
         if (dist[i][j] == 999)
            printf("%7s", "INF");
         else
            printf("%7d", dist[i][j]);
      }
      printf("\n");
   }
}

int main()
{
   int n, i, j, graph[10][10];

   printf("Enter the number of vertices: ");
   scanf("%d", &n);

   printf("Enter the adjacency matrix:\n");
   for (i = 0; i < n; i++)
      for (j = 0; j < n; j++)
         scanf("%d", &graph[i][j]);

   floydWarshall(graph, n);

   return 0;
}