#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};


struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}


struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

struct Node* findNode(struct Node* root, int val) {
    if (root == NULL || root->data == val) {
        return root;
    }
    if (val < root->data) {
        return findNode(root->left, val);
    } else {
        return findNode(root->right, val);
    }
}


void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    int n, data, val;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        root = insert(root, data);
    }

    printf("Enter the value to find: ");
    scanf("%d", &val);

    struct Node* subtree = findNode(root, val);
    if (subtree != NULL) {
        printf("Subtree rooted at node with value %d (inorder traversal): ", val);
        inorder(subtree);
        printf("\n");
    } else {
        printf("Node with value %d not found in the tree.\n", val);
    }

    return 0;
}
