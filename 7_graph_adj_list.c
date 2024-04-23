#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of vertices
#define MAX_VERTICES 100

// Define the structure for an adjacency list node
struct AdjListNode {
    int dest;
    struct AdjListNode* next;
};

// Define the structure for an adjacency list
struct AdjList {
    struct AdjListNode* head;
};

// Define the structure for a graph
struct Graph {
    int V;
    struct AdjList* array;
};

// Function to create a new adjacency list node
struct AdjListNode* newAdjListNode(int dest) {
    struct AdjListNode* newNode = (struct AdjListNode*) malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph of V vertices
struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->V = V;
    graph->array = (struct AdjList*) malloc(V * sizeof(struct AdjList));
    int i;
    for (i = 0; i < V; ++i)
        graph->array[i].head = NULL;
    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    // Add an edge from src to dest.  A new node is added to the adjacency
    // list of src.  The node is added at the begining
    struct AdjListNode* newNode = newAdjListNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
}

// Function to print the adjacency list representation of the graph
void printGraph(struct Graph* graph) {
    int v;
    for (v = 0; v < graph->V; ++v) {
        struct AdjListNode* pCrawl = graph->array[v].head;
        printf("\n Adjacency list of vertex %d\n head ", v);
        while (pCrawl) {
            printf("-> %d", pCrawl->dest);
            pCrawl = pCrawl->next;
        }
        printf("\n");
    }
}

int main() {
    // Input the number of vertices and edges
    int V, E;
    printf("Enter the number of vertices: ");
    scanf("%d", &V);
    printf("Enter the number of edges: ");
    scanf("%d", &E);

    // Create a graph of V vertices
    struct Graph* graph = createGraph(V);

    // Read the edge list and add edges to the graph
    int i, src, dest;
    for (i = 0; i < E; ++i) {
        printf("Enter edge %d (source and destination): ", i);
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    // Print the adjacency list representation of the graph
    printGraph(graph);

    return 0;
}