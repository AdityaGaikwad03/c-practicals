#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node* left;
  struct node* right;
};

struct node* create() {
  struct node* newNode = (struct node*)malloc(sizeof(struct node));
  printf("Enter the value: ");
  scanf("%d", &newNode->data);
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

void insert(struct node** root, struct node* newNode) {
  if (*root == NULL) {
    *root = newNode;
  } else {
    if ((*root)->data > newNode->data) {
      insert(&((*root)->left), newNode);
    } else {
      insert(&((*root)->right), newNode);
    }
  }
}

void preorder(struct node* root) {
  if (root != NULL) {
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
  }
}

int main() {
  struct node* root = NULL;
  int choice, data;

  while (1) {
    printf("\n1. Create\n2. Insert\n3. Preorder\n4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        root = create();
        break;
      case 2:
        printf("Enter the value to insert: ");
        scanf("%d", &data);
        insert(&root, create());
        break;
      case 3:
        printf("Preorder Traversal: ");
        preorder(root);
        printf("\n");
        break;
      case 4:
        exit(0);
      default:
        printf("Invalid choice!\n");
    }
  }

  return 0;
}