#include <stdio.h>
#include <stdlib.h>

#define MAX_EDGES 100

// Structure to represent an edge in the graph
struct Edge {
    int src, dest, weight;
};

// Structure to represent a subset for union-find
struct Subset {
    int parent;
    int rank;
};

// Function to create a new subset
struct Subset* createSubset(int parent, int rank) {
    struct Subset* subset = (struct Subset*)malloc(sizeof(struct Subset));
    if (subset == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    subset->parent = parent;
    subset->rank = rank;
    return subset;
}

// Function to find the set of an element 'i' (uses path compression technique)
int find(struct Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

// Function to perform union of two sets of x and y (uses union by rank)
void Union(struct Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    // Attach the smaller rank tree under the root of the higher rank tree
    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

// Comparison function to sort edges by weight
int compare(const void* a, const void* b) {
    struct Edge* edge1 = (struct Edge*)a;
    struct Edge* edge2 = (struct Edge*)b;
    return edge1->weight - edge2->weight;
}

// Function to implement Kruskal's algorithm
void KruskalMST(struct Edge edges[], int vertices, int edgesCount) {
    struct Edge resultMST[vertices]; // Array to store the resultant MST
    int resultIndex = 0; // Index used for resultMST[]

    // Sort all the edges in non-decreasing order of their weight
    qsort(edges, edgesCount, sizeof(edges[0]), compare);

    // Allocate memory for creating subsets
    struct Subset* subsets = (struct Subset*)malloc(vertices * sizeof(struct Subset));
    if (subsets == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    // Create subsets with single elements
    for (int v = 0; v < vertices; ++v)
        subsets[v] = *createSubset(v, 0);

    // Index used to pick the next edge
    int i = 0;

    // Number of edges to be taken is equal to vertices - 1
    while (resultIndex < vertices - 1 && i < edgesCount) {
        // Pick the smallest edge
        struct Edge nextEdge = edges[i++];

        int x = find(subsets, nextEdge.src);
        int y = find(subsets, nextEdge.dest);

        // If including this edge doesn't cause cycle, include it in resultMST and increment the index of resultMST for next edge
        if (x != y) {
            resultMST[resultIndex++] = nextEdge;
            Union(subsets, x, y);
        }
    }

    // Print the edges of resultMST to construct the MST
    printf("Edges of Minimum Spanning Tree:\n");
    for (int i = 0; i < resultIndex; ++i) {
        printf("%d -- %d  weight: %d\n", resultMST[i].src, resultMST[i].dest, resultMST[i].weight);
    }

    free(subsets);
}

int main() {
    int vertices, edgesCount;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    printf("Enter the number of edges: ");
    scanf("%d", &edgesCount);

    struct Edge edges[MAX_EDGES];

    printf("Enter the edges (source destination weight):\n");
    for (int i = 0; i < edgesCount; ++i) {
        scanf("%d %d %d", &edges[i].src, &edges[i].dest, &edges[i].weight);
    }

    // Apply Kruskal's algorithm to find MST
    KruskalMST(edges, vertices, edgesCount);

    return 0;
}
