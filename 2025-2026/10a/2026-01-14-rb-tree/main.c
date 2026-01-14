#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int val;
    int color; // 0 - black, 1 = red
    struct Node* left;
    struct Node* right;
    struct Node* parent;
} Node;

Node* init_node(int val) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;
    node->color = 1;

    return node;
}

void preorder(Node* root) {
    if (root == NULL) {
        return;
    }

    printf("%d ", root->val);
    preorder(root->left);
    preorder(root->right);
}

/*                                        
          y                                  x
        /  \        Right Rotation         /  \ 
       x   T3      - - - - - - - - - >    T1   y
     /   \           <- - - - - - - - -      /   \
    T1  T2         Left Rotation             T2  T3
*/
Node* right_rotation(Node* y) {
    Node* x = y->left;
    Node* t2 = x->right;

    x->right = y;
    y->left = t2;

    x->parent = y->parent;
    y->parent = x;
    if (t2 != NULL) {
        t2->parent = y;
    }

    return x;
}

Node* left_rotation(Node* x) {
    Node* y = x->right;
    Node* t2 = y->left;

    x->right = t2;
    y->left = x;

    y->parent = x->parent;
    x->parent = y;
    if (t2 != NULL) {
        t2->parent = x;
    }

    return y;
}

// Red Black Tree
Node* rb_insert(Node* root, int val) {
    // попълни


    return root;
}


int main() {
    Node* tree = init_node(0);
    // bst_insert(tree, 1);
    // bst_insert(tree, 2);
    for(int i = 1; i < 16; i++) {
        tree = bst_insert(tree, i);
    }

    printf("H: %d\n", tree->height);
    preorder(tree);


    return 0;
}
