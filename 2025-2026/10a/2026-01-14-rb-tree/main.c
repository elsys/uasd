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

#define RED 1
#define BLACK 0

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

void right_rotation(Node** root, Node* y) {
    Node* x = y->left;
    Node* t2 = x->right;

    x->right = y;
    y->left = t2;

    x->parent = y->parent;

    if (y->parent == NULL) {
        (*root) = y;
    } else if (y->parent->left == y) {
        y->parent->left = x;
    } else {
        y->parent->right = x;
    }

    y->parent = x;
    if (t2 != NULL) {
        t2->parent = y;
    }
}

void left_rotation(Node** root, Node* x) {
    Node* y = x->right;
    Node* t2 = y->left;

    x->right = t2;
    y->left = x;

    y->parent = x->parent;

    if (x->parent == NULL) {
        (*root) = x;
    } else if (x->parent->left == x) {
        x->parent->left = y;
    } else {
        x->parent->right = y;
    }

    x->parent = y;
    if (t2 != NULL) {
        t2->parent = x;
    }
}

// Red Black Tree
void rb_insert(Node** root, int val) {
    // попълни
    Node* y = NULL;
    Node* x = root;

    while(x != NULL) {
        y = x;

        if (val < x->val) {
            x = x->left;
        } else {
            x = x->right;
        }
    }

    Node* z = init_node(val);
    z->parent = y;
    
    if (*root == NULL) {
        (*root) = z;
    } else if (val < y->val) {
        y->left = z;
    } else {
        y->right = z;
    }

    RBFixUp(root, z);
}

int find_bh(Node* root) {
    Node *it = root;
    int h = 0;
    while (it != NULL) {
        if(it->color == BLACK) {
            h++;
        }
        it = it->right;
    }

    return h;
}

void RBFixUp(Node** root, Node* z) {
    while (z->parent->color == RED) {
        Node* gp = z->parent->parent;
        if (z->parent == gp->left) {
            Node* uncle = gp->right;

            if (uncle->color == RED) {
                z->parent->color = BLACK;
                uncle->color = BLACK;
                gp->color = RED;

                z = gp;
            } else {
                if (z == z->parent->right) {
                    z = z->parent;
                    left_rotation(root, z);
                }
                
                gp->color = RED;
                z->parent->color = BLACK;
                right_rotation(root, gp);
            }
        } else {
            Node* uncle = gp->left;

            if (uncle->color == RED) {
                z->parent->color = BLACK;
                uncle->color = BLACK;
                gp->color = RED;

                z = gp;
            } else {
                if (z == z->parent->left) {
                    z = z->parent;
                    right_rotation(root, z);
                }
                
                gp->color = RED;
                z->parent->color = BLACK;
                left_rotation(root, gp);
            }
        }
    }

    (*root)->color = RED;
}


int main() {
    Node* tree = NULL;

    rb_insert(&tree, 5);

    printf("%d\n", tree->val);
    rb_insert(&tree, 6);
    rb_insert(&tree, 7);

    preorder(tree);


    return 0;
}
