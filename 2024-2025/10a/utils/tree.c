#include "tree.h"
#include <stdio.h>
#include <stdlib.h>

//Binary Search Tree
Node* create_node(int val) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->left = NULL;
    node->right = NULL;
    node->val = val;

    return node;
}

// O(h)
Node* bst_insert(Node* root, int v) {
    if (root == NULL) {
        return create_node(v);
    }
    
    if (root->val >= v) {
        root->left = bst_insert(root->left, v);
    }
    else {
        root->right = bst_insert(root->right, v);
    }

    return root;
}


// O(n)
void printTree(Node* root) {
    if (root == NULL) {
        return;
    }

    //preorder
    // printf("%d ", root->val);
    // printTree(root->left);
    // printTree(root->right);

    //inorder
    printTree(root->left);
    printf("%d ", root->val);
    printTree(root->right);

    //postorder
    // printTree(root->right);
    // printTree(root->left);
    // printf("%d ", root->val);


}