#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TABLE_SIZE 10

// Structure to represent a hash table entry
struct HashEntry {
    int key;
    int data;
};

// Hash table
struct HashTable {
    struct HashEntry* array[TABLE_SIZE];
};

// Function to create a new hash table entry
struct HashEntry* createHashEntry(int key, int data) {
    struct HashEntry* newEntry = (struct HashEntry*)malloc(sizeof(struct HashEntry));
    if (newEntry == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newEntry->key = key;
    newEntry->data = data;
    return newEntry;
}

// Hash function to calculate the index for a given key
int hash(int key) {
    return key % TABLE_SIZE;
}

// Function to insert a key-value pair into the hash table
void insert(struct HashTable* table, int key, int data) {
    int index = hash(key);
    while (table->array[index] != NULL && table->array[index]->key != -1) {
        index = (index + 1) % TABLE_SIZE; // Linear probing
    }
    table->array[index] = createHashEntry(key, data);
}

// Function to search for a key in the hash table
bool search(struct HashTable* table, int key) {
    int index = hash(key);
    int originalIndex = index;
    while (table->array[index] != NULL) {
        if (table->array[index]->key == key)
            return true;
        index = (index + 1) % TABLE_SIZE; // Linear probing
        if (index == originalIndex) // If we've completed a full loop
            break;
    }
    return false;
}

// Function to display the hash table
void display(struct HashTable* table) {
    printf("Hash Table:\n");
    printf("Index\tKey\tData\n");
    for (int i = 0; i < TABLE_SIZE; ++i) {
        if (table->array[i] != NULL) {
            printf("%d\t%d\t%d\n", i, table->array[i]->key, table->array[i]->data);
        } else {
            printf("%d\t---\t---\n", i);
        }
    }
}

int main() {
    struct HashTable* table = (struct HashTable*)malloc(sizeof(struct HashTable));
    if (table == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    // Initialize hash table with NULL entries
    for (int i = 0; i < TABLE_SIZE; ++i) {
        table->array[i] = NULL;
    }

    int choice;
    int key, data;
    bool found;

    do {
        printf("\nHash Table Operations:\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key and data to insert: ");
                scanf("%d %d", &key, &data);
                insert(table, key, data);
                break;
            case 2:
                printf("Enter key to search: ");
                scanf("%d", &key);
                found = search(table, key);
                if (found)
                    printf("Key %d found in the hash table.\n", key);
                else
                    printf("Key %d not found in the hash table.\n", key);
                break;
            case 3:
                display(table);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    } while (choice != 4);

    // Free dynamically allocated memory
    for (int i = 0; i < TABLE_SIZE; ++i) {
        free(table->array[i]);
    }
    free(table);

    return 0;
}
