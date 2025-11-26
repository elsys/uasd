#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int val;
    struct Node* left;
    struct Node* right;
} Node;

Node* init_node(int val) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->val = val;
    node->left = NULL;
    node->right = NULL;

    return node;
}

void inorder(Node* root) {
    if (root == NULL) {
        return;
    }

    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
}

// O(n)
int treeSum(Node* root) {
    if (root == NULL) {
        return 0;
    }

    return treeSum(root->left) + root->val + treeSum(root->right);
}

// Binary Search Tree
Node* bst_insert(Node* root, int val) {
    if (root == NULL) {
        return init_node(val);
    }

    if (root->val > val) {
        root->left = bst_insert(root->left, val);
    } else {
        root->right = bst_insert(root->right, val);
    }

    return root;
}

Node* min(Node* root) {
    if (root == NULL) {
        return root;
    }

    while(root->left != NULL) {
        root = root->left;
    }

    return root;
}

bool isInTree(Node* root, int val) {
    if (root == NULL) {
        return false;
    }

    if (root->val == val) {
        return true;
    }

    return isInTree(root->right, val) || isInTree(root->left, val);
}


int treeHeight(Node* root) {
    if (root == NULL) {
        return 0;
    }

    int h1 = treeHeight(root->left) + 1;
    int h2 = treeHeight(root->right) + 1;

    return h1 > h2 ? h1 : h2;
}

int main() {
    Node* tree = NULL;
    tree = bst_insert(tree, 2);
    bst_insert(tree, -10);
    bst_insert(tree, 3);
    bst_insert(tree, 0);

    inorder(tree);
    printf("\n");
    printf("%d \n", treeSum(tree));
    printf("%d \n", min(tree)->val);
    printf("%d \n", isInTree(tree, 6));


    return 0;
}