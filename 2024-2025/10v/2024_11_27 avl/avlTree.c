#include<stdio.h>
#include<stdlib.h>
#include "avlTree.h"

AVLNode* createNode(int val) {
    AVLNode* newNode = (AVLNode*) malloc(sizeof(AVLNode));
    if(!newNode) {
        exit(1);
    }

    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1;
    return newNode;
}


int getHeight(AVLNode* node) {
    if(!node) {
        return 0;
    }
    return node->height;
}

AVLNode* insert(AVLNode* node, int val) {
    if(!node) {
        return createNode(val);
    }

    if(val < node->val) {
        node->left = insert(node->left, val);
    } else if(val > node->val) {
        node->right = insert(node->right, val);
    } else {
        return node;
    }

    updateHeight(node);

    int balanceFactor = getHeight(node->left) - getHeight(node->right); 

    if(balanceFactor > 1 && node->left && val < node->left->val) {
        return rotateRight(node);
    }
    if(balanceFactor > 1 && node->left && val > node->left->val) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }
    if(balanceFactor < -1 && node->right && val < node->right->val) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }
    if(balanceFactor < -1 && node->right && val > node->right->val) {
        return rotateLeft(node);
    }

    return node;
}

int max(int a, int b) {
    return a > b ? a : b;
}

void updateHeight(AVLNode* node) {
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
}

void printInOrder(AVLNode* node) {
    if(!node) {
        return;
    }

    printInOrder(node->left);
    printf("%d ", node->val);
    printInOrder(node->right);
}

AVLNode* rotateLeft(AVLNode* y) {
    AVLNode* x = y->right;
    AVLNode* T2 = x->left;

    x->left = y;
    y->right = T2;

    updateHeight(x);
    updateHeight(y);

    return x;
}

AVLNode* rotateRight(AVLNode* y) {
    AVLNode* x = y->left;
    AVLNode* T2 = x->right;

    x->right = y;
    y->left = T2;

    updateHeight(x);
    updateHeight(y);

    return x;
}
