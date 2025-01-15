#include<stdio.h>
#include<stdlib.h>

typedef enum Color {
    BLACK,
    RED
} Color;

struct Node {
    int val;
    struct Node* left;
    struct Node* right;
    struct Node* parent;
    Color color;
};

typedef struct Node Node;

Node* initNode(int val) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if(!newNode) {
        exit(1);
    }
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent = NULL;
    newNode->val = val;
    newNode->color = RED;
    return newNode;
}

void leftRotation(Node** root, Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;


    if (!x->parent){
        *root = y;
    } else if(x->parent->left == x) {
        x->parent->left = y;
    } else {
        x->parent->right = y;
    }
    y->parent = x->parent;

    x->parent = y;

    x->right = T2;
    y->left = x;

    if(T2) {
        T2->parent = x;
    }
}

/*
     y      RightRotation     x
    / \     ------------->   / \
   x  T3                    T1  y
  / \       <-------------     / \
 T1 T2       LeftRotation     T2 T3
*/

void rightRotation(Node** root, Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    if(!y->parent) {
        *root = x;
    } else if (y->parent->left == y) {
        y->parent->left = x;
    } else {
        y->parent->right = x;
    }

    x->parent = y->parent;
    y->parent = x;

    x->right = y;

    y->left = T2;

    if(T2) {
        T2->parent = y;
    }

}

void treeFixUp(Node** root, Node* node) {
    Node* grandparent = NULL;
    Node* uncle = NULL;
    while(node != (*root) && node->parent && node->parent->color == RED) {
        grandparent = node->parent->parent;
        if(node->parent == grandparent->left) {
            uncle = grandparent->right;
            if(uncle && uncle->color == RED) {
                node->parent->color = BLACK;
                grandparent->color = RED;
                uncle->color = BLACK;

                node = grandparent;
            } else {
                if(node->parent->right == node) {
                    node = node->parent;
                    leftRotation(root, node);
                }
                grandparent->color = RED;
                node->parent->color = BLACK;
                rightRotation(root, grandparent);
            }
        } else {
            uncle = grandparent->left;
            if(uncle && uncle->color == RED) {
                node->parent->color = BLACK;
                grandparent->color = RED;
                uncle->color = BLACK;

                node = grandparent;
            } else {
                if(node->parent->left == node) {
                    node = node->parent;
                    rightRotation(root, node);
                }
                grandparent->color = RED;
                node->parent->color = BLACK;
                leftRotation(root, node);
            }
        }
    }

    (*root)->color = BLACK;
}


void insert(Node**root, int val) {
    Node* newNode = initNode(val);
    Node* current = *root;

    if (!current) {
        newNode->color = BLACK;
        *root = newNode;
        return;
    }

    while(1) {
        if(val < current->val) {
            if(!current->left) {
                break;
            }
            current = current->left;
        } else {
            if(!current->right) {
                break;
            }
            current = current->right;
        }
    }

    if(val < current->val) {
        current->left = newNode;
    } else {
        current->right = newNode;
    }
    newNode->parent = current;

    treeFixUp(root, newNode);
}