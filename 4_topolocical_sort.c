#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

int adj_matrix[MAX_NODES][MAX_NODES];
int visited[MAX_NODES];
int sorted_order[MAX_NODES];
int n;

void initialize() {
    int i, j;
    for (i = 0; i < MAX_NODES; i++) {
        visited[i] = 0;
        sorted_order[i] = 0;
        for (j = 0; j < MAX_NODES; j++) {
            adj_matrix[i][j] = 0;
        }
    }
}

void topologicalSortUtil(int v, int* index) {
    visited[v] = 1;

    int i;
    for (i = 0; i < n; i++) {
        if (adj_matrix[v][i] && !visited[i]) {
            topologicalSortUtil(i, index);
        }
    }

    sorted_order[--(*index)] = v;
}

void topologicalSort() {
    int i;
    int index = n;

    for (i = 0; i < n; i++) {
        if (!visited[i]) {
            topologicalSortUtil(i, &index);
        }
    }

    printf("Topological Sort Order: ");
    for (i = 0; i < n; i++) {
        printf("%d ", sorted_order[i]);
    }
    printf("\n");
}

int main() {
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    initialize();

    printf("Enter the adjacency matrix:\n");
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &adj_matrix[i][j]);
        }
    }

    topologicalSort();

    return 0;
}
