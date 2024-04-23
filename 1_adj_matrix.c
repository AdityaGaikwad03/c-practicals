#include <stdio.h>
#define MAX_VERTICES 100

// Function to initialize the adjacency matrix
void initializeGraph(int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES]) {
    for (int i = 0; i < MAX_VERTICES; i++) {
        for (int j = 0; j < MAX_VERTICES; j++) {
            adjacencyMatrix[i][j] = 0;
        }
    }
}

// Function to add an edge to the graph
void addEdge(int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES], int start, int end) {
    adjacencyMatrix[start][end] = 1;
    adjacencyMatrix[end][start] = 1;
}

// Function to display the adjacency matrix
void displayMatrix(int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES], int vertices) {
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            printf("%d ", adjacencyMatrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int vertices, edges;

    // Input the number of vertices
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    if (vertices <= 0 || vertices > MAX_VERTICES) {
        printf("Invalid number of vertices. Exiting...\n");
        return 1;
    }

    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
    initializeGraph(adjacencyMatrix);

    // Input the number of edges
    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    if (edges < 0 || edges > vertices * (vertices - 1) / 2) {
        printf("Invalid number of edges. Exiting...\n");
        return 1;
    }

    // Input edges and construct the adjacency matrix
    for (int i = 0; i < edges; i++) {
        int start, end;
        printf("Enter edge %d (start end): ", i + 1);
        scanf("%d %d", &start, &end);

        // Validate input vertices
        if (start < 0 || start >= vertices || end < 0 || end >= vertices) {
            printf("Invalid vertices. Try again.\n");
            i--;
            continue;
        }

        addEdge(adjacencyMatrix, start, end);
    }

    // Display the adjacency matrix
    displayMatrix(adjacencyMatrix, vertices);

    return 0;
}