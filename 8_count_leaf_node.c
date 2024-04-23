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

// Function to count total nodes in BST
int countNodes(struct TreeNode* root) {
    if (root == NULL)
        return 0;
    else
        return 1 + countNodes(root->left) + countNodes(root->right);
}

// Function to count total leaf nodes in BST
int countLeaf(struct TreeNode* root) {
    if (root == NULL)
        return 0;
    else if (root->left == NULL && root->right == NULL)
        return 1;
    else
        return countLeaf(root->left) + countLeaf(root->right);
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

    // Count total nodes and total leaf nodes
    int totalNodes = countNodes(root);
    int totalLeafNodes = countLeaf(root);

    // Display results
    printf("Total nodes in the BST: %d\n", totalNodes);
    printf("Total leaf nodes in the BST: %d\n", totalLeafNodes);

    return 0;
}
