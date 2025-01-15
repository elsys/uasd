#include <stdio.h>
#include "tree.h"

int main() {
    Node* root = NULL;
    bst_insert(&root, 5);
    bst_insert(&root, 10);
    bst_insert(&root, 20);
    bst_insert(&root, 0);
    bst_insert(&root, 16);
    bst_insert(&root, 7);
    bst_insert(&root, 30);
    bst_insert(&root, -10);
    bst_insert(&root, 100);

    printTree(root);
    printf("\n");
    printTreeInorder(root);

    return 0;
}