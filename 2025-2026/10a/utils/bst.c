#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

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
