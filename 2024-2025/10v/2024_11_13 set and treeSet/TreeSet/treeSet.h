#ifndef TREESET_T
#define TREESET_T

struct TreeNode {
    struct TreeNode* left;
    struct TreeNode* right;
    int val;
};

typedef struct TreeNode TreeNode;

TreeNode* initTreeTreeNode(int val);

int treeSetContains(TreeNode* set, int val);

TreeNode* treeSetAdd(TreeNode* set, int val);
void treeSetAdd2(TreeNode** set, int val);

unsigned treeSetHeight(TreeNode* set);

void printTreeSet(TreeNode* set);

#endif