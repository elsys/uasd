#ifndef BST_H
#define BST_H

typedef struct Node {
    int val;
    struct Node* left;
    struct Node* right;
} Node;

Node* init_node(int val);
void inorder(Node* root);
Node* bst_insert(Node* root, int val);

#endif