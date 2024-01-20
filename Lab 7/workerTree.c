#include <stdio.h>
#include <stdlib.h>

struct worker {
    int id;
    char name[20];
};

struct TreeNode {
    struct worker data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new worker node
struct TreeNode* createNode(struct worker data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a worker into the binary tree using level order
struct TreeNode* insertLevelOrder(struct worker workers[], int i, int n) {
    if (i < n) {
        struct TreeNode* temp = createNode(workers[i]);

        // Insert left child
        temp->left = insertLevelOrder(workers, 2 * i + 1, n);

        // Insert right child
        temp->right = insertLevelOrder(workers, 2 * i + 2, n);

        return temp;
    }
    return NULL;
}

// In-order traversal
void inOrderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("ID: %d, Name: %s\n", root->data.id, root->data.name);
        inOrderTraversal(root->right);
    }
}

// Pre-order traversal
void preOrderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        printf("ID: %d, Name: %s\n", root->data.id, root->data.name);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

// Post-order traversal
void postOrderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("ID: %d, Name: %s\n", root->data.id, root->data.name);
    }
}

int main() {
    // Assume workers are already present in some array
    int n;

    // Prompt user for the number of workers
    printf("Enter the number of workers: ");
    scanf("%d", &n);

    struct worker workers[n];

    // Input worker information
    for (int i = 0; i < n; ++i) {
        printf("\nEnter the ID of Worker %d: ", i + 1);
        scanf("%d", &workers[i].id);

        printf("Enter the Name of Worker %d: ", i + 1);
        scanf("%s", workers[i].name);
    }

    // Create a binary tree using level order
    struct TreeNode* root = insertLevelOrder(workers, 0, n);

    // Perform traversals
    printf("\nIn-order Traversal:\n");
    inOrderTraversal(root);

    printf("\n\nPre-order Traversal:\n");
    preOrderTraversal(root);

    printf("\n\nPost-order Traversal:\n");
    postOrderTraversal(root);

    return 0;
}