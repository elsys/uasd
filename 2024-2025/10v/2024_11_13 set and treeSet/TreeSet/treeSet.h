#ifndef TREESET_T
#define TREESET_T

struct Node {
    struct Node* left;
    struct Node* right;
    int val;
};

typedef struct Node Node;

Node* initTreeSet(int val);

int treeSetContains(Node* set, int val);

Node* treeSetAdd(Node* set, int val);
void treeSetAdd2(Node** set, int val);

void printTreeSet(Node* set);

#endif