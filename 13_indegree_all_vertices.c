#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Function to print the in-degree of all vertices of the graph
void printInDegree(int graph[][MAX_VERTICES], int vertices) {
    int inDegree[MAX_VERTICES] = {0}; // Array to store in-degree of vertices

    // Calculate in-degree for each vertex
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            if (graph[j][i] == 1)
                inDegree[i]++;
        }
    }

    // Print in-degree of each vertex
    printf("Vertex\tIn-Degree\n");
    for (int i = 0; i < vertices; i++) {
        printf("%d\t%d\n", i, inDegree[i]);
    }
}

int main() {
    int vertices, edges;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    int graph[MAX_VERTICES][MAX_VERTICES] = {0}; // Initialize adjacency matrix with 0

    printf("Enter the edges (format: vertex1 vertex2):\n");
    for (int i = 0; i < edges; ++i) {
        int v1, v2;
        scanf("%d %d", &v1, &v2);
        // Mark the edge between v1 and v2 as 1 (assuming it's a directed graph)
        graph[v1][v2] = 1;
    }

    // Print in-degree of all vertices
    printf("In-degree of all vertices:\n");
    printInDegree(graph, vertices);

    return 0;
}
