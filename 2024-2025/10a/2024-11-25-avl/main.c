#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main() {
    Node* root = create_node(10);
    // bst_insert(root, 5);
    // bst_insert(root, 1);
    for (int i = 11; i < 20; i++ ) {
        root = bst_insert(root, i);
    }

    printf("Height %d\n", root->height);

    // printTree(root);
    // printf("Height is: %d\n", root->height);
    // root = right_rotation(root);
    // printf("\n");
    // printf("Height is: %d\n", root->height);
    // printTree(root);


    return 0;
}