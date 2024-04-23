#include <stdio.h>
#include <stdlib.h>

// Binary Search Tree (BST) Node Structure
struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Function to create a new BST node
struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a new node into BST
struct TreeNode* insert(struct TreeNode* root, int data) {
    if (root == NULL)
        return createNode(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    return root;
}

// Function to find the maximum height of a BST
int maxHeight(struct TreeNode* root) {
    if (root == NULL)
        return 0;
    else {
        int leftHeight = maxHeight(root->left);
        int rightHeight = maxHeight(root->right);
        return (leftHeight > rightHeight) ? (leftHeight + 1) : (rightHeight + 1);
    }
}

// Function to print nodes at a given level
void printLevel(struct TreeNode* root, int level) {
    if (root == NULL)
        return;
    if (level == 1)
        printf("%d ", root->data);
    else if (level > 1) {
        printLevel(root->left, level - 1);
        printLevel(root->right, level - 1);
    }
}

// Function to count nodes at each level and print them
void printLevelOrder(struct TreeNode* root) {
    int h = maxHeight(root);
    for (int i = 1; i <= h; i++) {
        printf("Level %d: ", i);
        printLevel(root, i);
        printf("\n");
    }
}

int main() {
    struct TreeNode* root = NULL;
    int data;
    char choice;

    // Accept data from the user to build the BST
    do {
        printf("Enter data to insert into BST: ");
        scanf("%d", &data);
        root = insert(root, data);
        printf("Do you want to insert another node? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    // Display nodes at each level and count of nodes at each level
    printf("Nodes at each level:\n");
    printLevelOrder(root);

    return 0;
}
