#ifndef TREE_H
#define TREE_H

enum Color {
    RED,
    BLACK
} typedef Color;

struct Node {
    int val;
    Color color;
    struct Node* left;
    struct Node* right;
    struct Node* parent;
} typedef Node;

Node* create_node(int);
void bst_insert(Node**, int);
void printTree(Node*);
void left_rotation(Node**, Node *x);
void right_rotation(Node**, Node *y);
void printTreeInorder(Node* root);
#endif