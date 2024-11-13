#include<stdio.h>
#include<stdlib.h>
#include "treeSet.h"


Node* initTreeSet(int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->val = val;
    return newNode;
}

int treeSetContains(Node* node, int val) {
    if (!node) {
        return 0;
    }
    if (node->val == val) {
        return 1;
    } else if (node->val > val) {
        return treeSetContains(node->left, val);
    } else {
        return treeSetContains(node->right, val);
    }
}

// Така както го бях написал в час

Node* treeSetAdd(Node* node, int val) {
    if(!node) {
        return initTreeSet(val);
    }
    if(node->val == val) {
        return node;
    } else if(node->val > val) {
        node->left = treeSetAdd(node->left, val);
    } else {
        node->right = treeSetAdd(node->right, val);
    }
    return node;
}

// ИЛИ
// (тва е доста объркващо)
// Използва двоен указател понеже иначе взимаме само копие на указателя и като го променяме не правим нищо
void treeSetAdd2(Node** node, int val) { 
    if (!(*node)) {
        *node = initTreeSet(val);
        return;
    }
    if ((*node)->val == val) {
        return;
    } else if ((*node)->val > val) {
        treeSetAdd2(&((*node)->left), val);
    } else {
        treeSetAdd2(&((*node)->right), val);
    }
}

void printTreeSet(Node* node) {
    if(!node) {
        return;
    }
    printTreeSet(node->left);
    printf("%d ", node->val);
    printTreeSet(node->right);
}