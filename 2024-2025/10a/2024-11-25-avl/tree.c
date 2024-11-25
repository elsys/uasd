#include "tree.h"
#include <stdio.h>
#include <stdlib.h>

//Binary Search Tree
Node* create_node(int val) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->left = NULL;
    node->right = NULL;
    node->val = val;
    node->height = 1;

    return node;
}

int get_height(Node* node) {
    if (node == NULL) {
        return 0;
    }
    return node->height;
}

int max(int a, int b) {
    return a > b ? a : b;
}

void update_height(Node* node) {
    node->height = 1 + max(get_height(node->left), get_height(node->right));
}

Node* left_rotation(Node *x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    update_height(y);
    update_height(x);

    return y;    
}

Node* right_rotation(Node *y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    update_height(y);
    update_height(x);

    return x;    
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

    update_height(root);

    int balance = get_height(root->left) - get_height(root->right);

    if (balance > 1) {
        if (v > root->left->val) {
            root->left = left_rotation(root->left);
        }
        
        return right_rotation(root);
    } else if (balance < -1) {
        if (v < root->right->val) {
            root->right = right_rotation(root->right);
        }
        
        return left_rotation(root);
    }

    return root;
}


// O(n)
void printTree(Node* root) {
    if (root == NULL) {
        return;
    }

    //preorder
    printf("%d ", root->val);
    printTree(root->left);
    printTree(root->right);

    //inorder
    // printTree(root->left);
    // printf("%d ", root->val);
    // printTree(root->right);

    //postorder
    // printTree(root->right);
    // printTree(root->left);
    // printf("%d ", root->val);


}