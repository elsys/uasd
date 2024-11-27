#include<stdio.h>
#include<stdlib.h>
#include "treeSet.h"


TreeNode* initTreeNode(int val) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->val = val;
    return newNode;
}

int treeSetContains(TreeNode* node, int val) {
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


// void treeSetAdd(TreeNode* node, int val) {
//     if(!node) {
//         node = initTreeNode(val);
//         return;
//     }
//     if(node->val == val) {
//         return;
//     } else if(node->val > val) {
//         treeSetAdd(node->left, val);
//     } else {
//         treeSetAdd(node->right, val);
//     }
// }










TreeNode* treeSetAdd(TreeNode* node, int val) {
    if(!node) {
        return initTreeNode(val);
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
void treeSetAdd2(TreeNode** node, int val) { 
    if (!(*node)) {
        *node = initTreeNode(val);
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

unsigned treeSetHeight(TreeNode* node) {
    if(!node) {
        return 0;
    }

    int leftHeight = treeSetHeight(node->left);
    int rightHeight = treeSetHeight(node->right);

    int maxHeight = leftHeight > rightHeight ? leftHeight : rightHeight;
    return maxHeight + 1;
}   

int treeSetMin(TreeNode* node) {
    if(!node->left) {
        return node->val;
    }
    return treeSetMin(node->left);
}

int treeSetMinIter(TreeNode* node) {
    while(node->left) {
        node = node->left;
    }
    return node;
}

int treeSetMaxIter(TreeNode* node) {
    while(node->right) {
        node = node->right;
    }
    return node;
}

void printTreeSet(TreeNode* node) {
    if(!node) {
        return;
    }
    printTreeSet(node->left);
    printf("%d ", node->val);
    printTreeSet(node->right);
}
