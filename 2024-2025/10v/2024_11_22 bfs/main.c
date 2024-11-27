#include<stdio.h>
#include<stdlib.h>

#include "dLinkedList_TreeNode.h"

TreeNode* createTreeNode(int val) {
    TreeNode* newNode = (TreeNode*) malloc(sizeof(TreeNode));
    if(!newNode) {
        exit(1);
    }
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL; 
    return newNode;
}

void printLevel(TreeNode* root, int level) {
    if(!root) {
        return;
    }
    if(level == 1) {
        printf("%d ", root->val);
    }
    printLevel(root->left, level - 1);
    printLevel(root->right, level - 1);
}

int height(TreeNode* root) {
    if(!root) {
        return 0;
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    if(leftHeight > rightHeight) {
        return leftHeight + 1;
    } else {
        return rightHeight + 1;
    }
}

void printByLevel(TreeNode* root) {
    int h = height(root);
    for(int i = 1; i <= h; i++) {
        printLevel(root, i);
        printf("\n");
    }
}

void printByLevelQueue(TreeNode* root) {
    Dlist q = initList();
    pushBack(&q, root);
    while(q.size) {
        TreeNode* curr = q.head->val;
        printf("%d ", curr->val);
        popFront(&q);
        if(curr->left) {
            pushBack(&q, curr->left);
        }
        if(curr->right) {
            pushBack(&q, curr->right);
        }
    }
}


int main() {

    TreeNode* root = createTreeNode(1);
    root->left = createTreeNode(2);
    root->right = createTreeNode(3);
    root->left->left = createTreeNode(4);
    root->left->right = createTreeNode(5);
    root->right->right = createTreeNode(6);
    
    // printf("%d ", height(root));
    // printLevel(root, 3);
    printByLevelQueue(root);
}