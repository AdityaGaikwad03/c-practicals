#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the adjacency list
struct Node {
    int vertex;
    struct Node* next;
};

// Structure to represent the adjacency list
struct AdjList {
    struct Node* head;
};

// Function to create a new node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Function to create an adjacency list
struct AdjList* createAdjList(int vertices) {
    struct AdjList* adjList = (struct AdjList*)malloc(vertices * sizeof(struct AdjList));
    if (adjList == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    for (int i = 0; i < vertices; ++i) {
        adjList[i].head = NULL;
    }
    return adjList;
}

// Function to add an edge to the adjacency list
void addEdge(struct AdjList* adjList, int src, int dest) {
    // Add an edge from src to dest
    struct Node* newNode = createNode(dest);
    newNode->next = adjList[src].head;
    adjList[src].head = newNode;

    // For undirected graph, add an edge from dest to src as well
    newNode = createNode(src);
    newNode->next = adjList[dest].head;
    adjList[dest].head = newNode;
}

// Function to display the adjacency list
void displayAdjList(struct AdjList* adjList, int vertices) {
    for (int i = 0; i < vertices; ++i) {
        struct Node* temp = adjList[i].head;
        printf("Adjacency list of vertex %d:\n", i);
        while (temp) {
            printf(" -> %d", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    int vertices, edges;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    struct AdjList* adjList = createAdjList(vertices);

    printf("Enter the edges (format: source destination):\n");
    for (int i = 0; i < edges; ++i) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        addEdge(adjList, src, dest);
    }

    // Display the adjacency list
    displayAdjList(adjList, vertices);

    // Free dynamically allocated memory
    for (int i = 0; i < vertices; ++i) {
        struct Node* current = adjList[i].head;
        while (current) {
            struct Node* next = current->next;
            free(current);
            current = next;
        }
    }
    free(adjList);

    return 0;
}
