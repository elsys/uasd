#ifndef TREE_H
#define TREE_H

struct Node {
    int val;
    struct Node* left;
    struct Node* right;
    int height;
} typedef Node;

Node* create_node(int);
Node* bst_insert(Node*, int);
void printTree(Node*);
Node* left_rotation(Node *x);
Node* right_rotation(Node *y);
#endif