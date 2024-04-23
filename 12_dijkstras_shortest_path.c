#include <stdio.h>
#include <limits.h>

#define MAX_VERTICES 100

// Function to find the vertex with minimum distance value, from the set of vertices not yet included in shortest path tree
int minDistance(int dist[], int visited[], int vertices) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < vertices; v++)
        if (visited[v] == 0 && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

// Function to print the distance array
void printSolution(int dist[], int vertices, int src) {
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < vertices; i++)
        printf("%d \t\t %d\n", i, dist[i]);
}

// Function that implements Dijkstra's single source shortest path algorithm for a graph represented using adjacency cost matrix
void dijkstra(int graph[MAX_VERTICES][MAX_VERTICES], int src, int vertices) {
    int dist[MAX_VERTICES]; // The output array. dist[i] will hold the shortest distance from src to i

    int visited[MAX_VERTICES] = {0}; // visited[i] will be true if vertex i is included in shortest path tree or shortest distance from src to i is finalized

    // Initialize all distances as INFINITE and visited[] as false
    for (int i = 0; i < vertices; i++)
        dist[i] = INT_MAX;

    // Distance of source vertex from itself is always 0
    dist[src] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < vertices - 1; count++) {
        // Pick the minimum distance vertex from the set of vertices not yet processed.
        int u = minDistance(dist, visited, vertices);

        // Mark the picked vertex as processed
        visited[u] = 1;

        // Update dist value of the adjacent vertices of the picked vertex.
        for (int v = 0; v < vertices; v++)

            // Update dist[v] only if is not in visited, there is an edge from u to v, and total weight of path from src to v through u is smaller than current value of dist[v]
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    // Print the constructed distance array
    printSolution(dist, vertices, src);
}

int main() {
    int vertices, src;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    int graph[MAX_VERTICES][MAX_VERTICES];

    printf("Enter the adjacency cost matrix:\n");
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the source vertex: ");
    scanf("%d", &src);

    dijkstra(graph, src, vertices);

    return 0;
}
