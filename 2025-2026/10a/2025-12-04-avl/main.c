#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int val;
    int height;
    struct Node* left;
    struct Node* right;
} Node;

Node* init_node(int val) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;

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

void update_height(Node* node) {
    int left_h = node->left == NULL ? 0 : node->left->height;
    int right_h = node->right == NULL ? 0 : node->right->height;

    node->height = (left_h > right_h ? left_h : right_h) + 1;
}

int getHeight(Node* node) {
    if (node == NULL) {
        return 0;
    }
    return node->height;
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

    update_height(y);
    update_height(x);

    return x;
}

Node* left_rotation(Node* x) {
    Node* y = x->right;
    Node* t2 = y->left;

    x->right = t2;
    y->left = x;

    update_height(x);
    update_height(y);

    return y;
}

// Binary Search Tree
Node* bst_insert(Node* root, int val) {
    if (root == NULL) {
        return init_node(val);
    }


    if (root->val > val) {
        root->left = bst_insert(root->left, val);
    } else {
        root->right = bst_insert(root->right, val);
    }

    update_height(root);
    
    int balance = getHeight(root->left) - getHeight(root->right);

    if (balance > 1) {
        // left is hanging
        if (val > root->left->val) {
            root->left = left_rotation(root->left);
        }

        root = right_rotation(root);
    } else if (balance < -1) {
        //right is hanging
        if (val < root->right->val) {
            root->right = right_rotation(root->right);
        }

        root = left_rotation(root);
    }


    return root;
}


/*
    BST:                               AVL
    Search, insert, delete: O(n) -> O(log(n))

    2^n
    n = 200

    Search in AVL: log(2^n) = n
    200 
*/

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

// BFS - Breadth First Search
// DFS - Depth First Search