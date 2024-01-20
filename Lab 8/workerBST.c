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

// Function to insert a worker into the BST
struct TreeNode* insert(struct TreeNode* root, struct worker data) {
    if (root == NULL)
        return createNode(data);

    if (data.id < root->data.id)
        root->left = insert(root->left, data);
    else if (data.id > root->data.id)
        root->right = insert(root->right, data);

    return root;
}

// Function to perform in-order traversal
void inOrderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("[ID: %d, Name: %s]\n", root->data.id, root->data.name);
        inOrderTraversal(root->right);
    }
}

// Function to perform pre-order traversal
void preOrderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        printf("[ID: %d, Name: %s]\n", root->data.id, root->data.name);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

// Function to perform post-order traversal
void postOrderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("[ID: %d, Name: %s]\n", root->data.id, root->data.name);
    }
}

// Function to search for a worker in the BST
struct TreeNode* search(struct TreeNode* root, int id) {
    if (root == NULL || root->data.id == id)
        return root;

    if (id < root->data.id)
        return search(root->left, id);

    return search(root->right, id);
}

// Function to find the node with the minimum value in a BST
struct TreeNode* findMin(struct TreeNode* node) {
    while (node->left != NULL)
        node = node->left;

    return node;
}

// Function to delete a worker from the BST
struct TreeNode* deleteNode(struct TreeNode* root, int id) {
    if (root == NULL)
        return root;

    if (id < root->data.id)
        root->left = deleteNode(root->left, id);
    else if (id > root->data.id)
        root->right = deleteNode(root->right, id);
    else {
        if (root->left == NULL) {
            struct TreeNode* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct TreeNode* temp = root->left;
            free(root);
            return temp;
        }

        struct TreeNode* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data.id);
    }
    return root;
}

// Function to calculate the height of the BST
int height(struct TreeNode* root) {
    if (root == NULL)
        return 0;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

int main() {
    struct TreeNode* root = NULL;
    int choice, id;
    struct worker data;

    do {
        printf("\n+---------- Menu ------------+\n");
        printf("| 1. Insert Worker           |\n");
        printf("| 2. Delete Worker           |\n");
        printf("| 3. Search Worker           |\n");
        printf("| 4. Calculate Height of BST |\n");
        printf("| 5. In-order Traversal      |\n");
        printf("| 6. Pre-order Traversal     |\n");
        printf("| 7. Post-order Traversal    |\n");
        printf("| 8. Exit                    |\n");
        printf("+----------------------------+\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
            	{
				
                printf("Enter worker ID: ");
                scanf("%d", &data.id);
                printf("Enter worker name: ");
                scanf("%s", data.name);
                root = insert(root, data);
                break;
            }

            case 2:
            	{
				
                printf("Enter worker ID to delete: ");
                scanf("%d", &id);
                root = deleteNode(root, id);
                break;
            }

            case 3:
            	{
				
                printf("Enter worker ID to search: ");
                scanf("%d", &id);
                struct TreeNode* result = search(root, id);
                if (result != NULL)
                    printf("Worker Found! ID: %d, Name: %s\n", result->data.id, result->data.name);
                else
                    printf("Worker Not Found!\n");
                break;
            }

            case 4:
                {
				printf("Height of the BST: %d\n", height(root));
                break;
            }

            case 5:
            	{
				
                printf("In-order Traversal (ID based):\n");
                inOrderTraversal(root);
                break;
            }

            case 6:
            	{
				
                printf("Pre-order Traversal (ID based):\n");
                preOrderTraversal(root);
                break;
            }

            case 7:
            	{
				
                printf("Post-order Traversal (ID based):\n");
                postOrderTraversal(root);
                break;
}
            case 8:
            	{
				
                printf("Exiting the program.\n");
                break;
                
				}

            default:
            	{
				
                printf("Invalid choice. Please enter a valid option.\n");
        }}

    } while (choice != 8);

    return 0;
}
