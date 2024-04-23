#include <stdio.h>
#include <stdbool.h>

#define MAX 10

// Function to initialize the adjacency matrix
void initializeGraph(int graph[MAX][MAX], int vertices) {
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph[i][j] = 0;
        }
    }
}

// Function to add an edge to the graph
void addEdge(int graph[MAX][MAX], int vertices, int start, int end) {
    graph[start][end] = 1;
    graph[end][start] = 1; // For undirected graph
}

// Function to perform DFS traversal
void DFS(int graph[MAX][MAX], int visited[MAX], int start, int vertices) {
    visited[start] = 1;
    printf("%d ", start);

    for (int i = 0; i < vertices; i++) {
        if (graph[start][i] == 1 && visited[i] == 0) {
            DFS(graph, visited, i, vertices);
        }
    }
}

int main() {
    int vertices, edges;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    int graph[MAX][MAX];
    int visited[MAX];

    initializeGraph(graph, vertices);

    printf("Enter the edges (start end): \n");
    for (int i = 0; i < edges; i++) {
        int start, end;
        scanf("%d %d", &start, &end);

        // Validate input vertices
        if (start < 0 || start >= vertices || end < 0 || end >= vertices) {
            printf("Invalid vertices. Try again.\n");
            i--;
            continue;
        }

        addEdge(graph, vertices, start, end);
    }

    // Input the starting vertex for DFS traversal
    int startVertex;
    printf("Enter the starting vertex for DFS traversal: ");
    scanf("%d", &startVertex);

    if (startVertex < 0 || startVertex >= vertices) {
        printf("Invalid starting vertex. Exiting...\n");
        return 1;
    }

    initializeGraph(visited, vertices);

    printf("DFS Traversal Order: ");
    DFS(graph, visited, startVertex, vertices);

    return 0;
}