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
    printf("In-Degree of all vertices:\n");
    for (int i = 0; i < vertices; i++) {
        printf("Vertex %d: %d\n", i, inDegree[i]);
    }
}

// Function to print the out-degree of all vertices of the graph
void printOutDegree(int graph[][MAX_VERTICES], int vertices) {
    int outDegree[MAX_VERTICES] = {0}; // Array to store out-degree of vertices

    // Calculate out-degree for each vertex
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            if (graph[i][j] == 1)
                outDegree[i]++;
        }
    }

    // Print out-degree of each vertex
    printf("\nOut-Degree of all vertices:\n");
    for (int i = 0; i < vertices; i++) {
        printf("Vertex %d: %d\n", i, outDegree[i]);
    }
}

// Function to print the total degree (in-degree + out-degree) of all vertices of the graph
void printTotalDegree(int graph[][MAX_VERTICES], int vertices) {
    int totalDegree[MAX_VERTICES] = {0}; // Array to store total degree of vertices

    // Calculate total degree for each vertex
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            if (graph[i][j] == 1)
                totalDegree[i]++;
            if (graph[j][i] == 1)
                totalDegree[i]++;
        }
    }

    // Print total degree of each vertex
    printf("\nTotal Degree of all vertices:\n");
    for (int i = 0; i < vertices; i++) {
        printf("Vertex %d: %d\n", i, totalDegree[i]);
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

    // Print in-degree, out-degree, and total degree of all vertices
    printInDegree(graph, vertices);
    printOutDegree(graph, vertices);
    printTotalDegree(graph, vertices);

    return 0;
}
