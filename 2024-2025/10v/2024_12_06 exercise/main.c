#include<stdio.h>
#include<stdlib.h>

struct TreeNode {
    struct TreeNode* left;
    struct TreeNode* right;
    int val;
};

typedef struct TreeNode TreeNode;

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

TreeNode* sortedArrayToBSTHelper(int arr[], int left, int right) {
    if (left > right) {
        return NULL;
    }

    int mid = left + (right - left) / 2;

    TreeNode* node = createTreeNode(arr[mid]);

    node->left = sortedArrayToBSTHelper(arr, left, mid - 1);
    node->right = sortedArrayToBSTHelper(arr, mid + 1, right);

    return node;
}

TreeNode* sortedArrayToBST(int arr[], int size) {
    return sortedArrayToBSTHelper(arr, 0, size - 1);
}

int isSymmetricHelper(TreeNode* left, TreeNode* right) {

    if(!left && !right) {
        return 1;
    }

    if(!left || !right) {
        return 0;
    }

    if(left->val == right->val) {
        return isSymmetricHelper(left->left, right->right) && 
               isSymmetricHelper(left->right, right->left);
    }

    return 0;
}

int isSymmetric(TreeNode* root) {
    if(!root) {
        return 1;
    }
    return isSymmetricHelper(root->left, root->right);
}

int hasPathSum(TreeNode* root, int targetSum) {
    if(!root) {
        return 0;
    }

    targetSum -= root->val;
    if(targetSum == 0 && !root->left && !root->right) {
        return 1;
    }
    return hasPathSum(root->left, targetSum) || hasPathSum(root->right, targetSum);
}

TreeNode* flatten(TreeNode* root) {
    TreeNode* curr = root;
    while(curr) {
        if(curr->left) {
            TreeNode* runner = curr->left;
            while(runner->right) {
                runner = runner->right;
            }
            runner->right = curr->right;
            curr->right = curr->left;
            curr->left = NULL;
        }
        curr = curr->right;
    }
    return root;
}

void printTree(TreeNode* node) {
    if(!node) {
        return;
    }
    printTree(node->left);
    printf("%d ", node->val);
    printTree(node->right);
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

int main() {

    // int arr[] = {1, 2, 3, 4, 5, 6, 7, 7};
    // int size = sizeof(arr) / sizeof(arr[0]);
    // TreeNode* root = sortedArrayToBST(arr, size);

    // printByLevel(root);

    TreeNode* root = createTreeNode(6);
    root->left = createTreeNode(5);
    root->right = createTreeNode(5);
    root->left->left = createTreeNode(1);
    root->left->right = createTreeNode(2);
    root->right->left = createTreeNode(2);
    // root->right->right = createTreeNode(1);

    printf("%d\n", hasPathSum(root, 12));
    printf("%d\n", hasPathSum(root, 11));
}