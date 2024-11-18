#ifndef TREE_H
#define TREE_H

struct Node {
    int val;
    struct Node* left;
    struct Node* right;
} typedef Node;

Node* create_node(int);
Node* bst_insert(Node*, int);
void printTree(Node*);

#endif