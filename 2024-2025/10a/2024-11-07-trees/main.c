#include "tree.h"

int main() {
    Node* root = create_node(10);
    bst_insert(root, 5);
    bst_insert(root, 15);
    bst_insert(root, 30);
    bst_insert(root, 0);
    bst_insert(root, 4);
    bst_insert(root, 26);

    
    printTree(root);

    return 0;
}