#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Queue structure for BFS traversal
struct Queue {
    int front, rear, size;
    unsigned capacity;
    int* array;
};

// Create a queue
struct Queue* createQueue(unsigned capacity) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = (int*)malloc(queue->capacity * sizeof(int));
    return queue;
}

// Queue is full when size becomes equal to the capacity
int isFull(struct Queue* queue) {
    return (queue->size == queue->capacity);
}

// Queue is empty when size is 0
int isEmpty(struct Queue* queue) {
    return (queue->size == 0);
}

// Enqueue an item to the queue
void enqueue(struct Queue* queue, int item) {
    if (isFull(queue))
        return;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size++;
}

// Dequeue an item from the queue
int dequeue(struct Queue* queue) {
    if (isEmpty(queue))
        return -1;
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    return item;
}

// Function to traverse the graph using BFS
void BFS(int graph[][MAX_VERTICES], int vertices, int startVertex) {
    struct Queue* queue = createQueue(vertices);
    int visited[MAX_VERTICES] = {0}; // Array to keep track of visited vertices

    visited[startVertex] = 1;
    enqueue(queue, startVertex);

    while (!isEmpty(queue)) {
        int currentVertex = dequeue(queue);
        printf("%d ", currentVertex);

        // Enqueue adjacent vertices of the dequeued vertex
        for (int i = 0; i < vertices; ++i) {
            if (graph[currentVertex][i] && !visited[i]) {
                visited[i] = 1;
                enqueue(queue, i);
            }
        }
    }

    free(queue->array);
    free(queue);
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
        // Mark the edge between v1 and v2 as 1
        graph[v1][v2] = 1;
        graph[v2][v1] = 1; // For undirected graph
    }

    int startVertex;
    printf("Enter the starting vertex for BFS traversal: ");
    scanf("%d", &startVertex);

    printf("BFS traversal starting from vertex %d: ", startVertex);
    BFS(graph, vertices, startVertex);
    printf("\n");

    return 0;
}
