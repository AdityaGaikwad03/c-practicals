#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to heapify a subtree rooted at index 'root'
void heapify(int arr[], int n, int root) {
    int largest = root; // Initialize largest as root
    int left = 2 * root + 1; // Left child
    int right = 2 * root + 2; // Right child

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not root
    if (largest != root) {
        swap(&arr[root], &arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

// Main function to perform Heap Sort
void heapSort(int arr[], int n) {
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        swap(&arr[0], &arr[i]);

        // Call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int* arr = (int*)malloc(n * sizeof(int));

    // Seed for random number generation
    srand(time(NULL));

    // Generate random elements
    printf("Randomly generated elements: ");
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100; // Generating random numbers between 0 and 99
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Perform Heap Sort
    heapSort(arr, n);

    // Print sorted elements
    printf("Sorted elements using Heap Sort: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr); // Free dynamically allocated memory

    return 0;
}
