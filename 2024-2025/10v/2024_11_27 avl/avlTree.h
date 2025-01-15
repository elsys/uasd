#ifndef AVLTREE_H
#define AVLTREE_H

struct AVLNode {
    struct AVLNode* left;
    struct AVLNode* right;
    int val;
    int height;
};

typedef struct AVLNode AVLNode;

AVLNode* createNode(int val);
AVLNode* insert(AVLNode* node, int val);
void printInOrder(AVLNode* node);
AVLNode* rotateLeft(AVLNode* node);
AVLNode* rotateRight(AVLNode* node);
void updateHeight(AVLNode* node);

#endif