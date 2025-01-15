#include "tree.h"
#include <stdio.h>
#include <stdlib.h>

//Binary Search Tree
Node* create_node(int val) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;
    node->val = val;
    node->color = RED;

    return node;
}


/*                            
     x                               y
    / \     Right Rotation          /  \
   y   T3   - - - - - - - >        T1   x
  / \       < - - - - - - -            / \
 T1  T2                               T2  T3
*/
void left_rotation(Node **root, Node *x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    y->parent = x->parent;

    if (x->parent == NULL) {
        *root = y;
    } else if (x->parent->left == x) {
        x->parent->left = y;
    } else {
        x->parent->right = y;
    }

    x->parent = y;

    if (T2 != NULL) {
        T2->parent = x;
    }   
}

void right_rotation(Node **root, Node *y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    x->parent = y->parent;

    if (y->parent == NULL) {
        *root = x;
    } else if (y->parent->left == y) {
        y->parent->left = x;
    } else {
        y->parent->right = x;
    }

    y->parent = x;

    if (T2 != NULL) {
        T2->parent = y;
    }    
}

void treeFixup(Node **root, Node *z) {
    while (z->parent != NULL && z->parent->color == RED) {
        //printf("doing fixup after %d\n", z->val);
        Node *gp = z->parent->parent;

        if (gp->left == z->parent) {
            Node *uncle = gp->right;

            if (uncle != NULL && uncle->color == RED) {
                gp->color = RED;
                uncle->color = BLACK;
                z->parent->color = BLACK;

                z = gp;
            } else { 
                if (z->parent->right == z) {
                    left_rotation(root, z->parent);
                    z = z->left;
                }

                right_rotation(root, gp);
                gp->color = RED;
                z->parent->color = BLACK;
            }
        } else {
            Node *uncle = gp->left;

            if (uncle != NULL && uncle->color == RED) {
                gp->color = RED;
                uncle->color = BLACK;
                z->parent->color = BLACK;

                z = gp;
            } else { 
                if (z->parent->left == z) {
                    right_rotation(root, z->parent);
                    z = z->right;
                }

                left_rotation(root, gp);
                gp->color = RED;
                z->parent->color = BLACK;
            }
        }
    }

    (*root)->color = BLACK;
}


// O(h)
void bst_insert(Node** root, int v) {
    if (*root == NULL) {
        *root = create_node(v);
        (*root)->color = BLACK;
        return;
    }
    
    Node* it = *root;
    while (1) {
        if (it->val > v) {
            if (it->left == NULL) {
                it->left = create_node(v);
                it->left->parent = it;
                it = it->left;
                break;
            }

            it = it->left;
        } else {
            if (it->right == NULL) {
                it->right = create_node(v);
                it->right->parent = it;
                it = it->right;
                break;
            }

            it = it->right;
        }
    }

    treeFixup(root, it);
}

// O(n)
void printTree(Node* root) {
    if (root == NULL) {
        return;
    }

    //preorder
    printf("%d(%c) ", root->val, root->color == BLACK ? 'B' : 'R');
    printTree(root->left);
    printTree(root->right);

    //inorder
    // printTree(root->left);
    // printf("%d ", root->val);
    // printTree(root->right);

    //postorder
    // printTree(root->right);
    // printTree(root->left);
    // printf("%d ", root->val);


}

void printTreeInorder(Node* root) {
    if (root == NULL) {
        return;
    }

    //preorder
    // printf("%d(%c) ", root->val, root->color == BLACK ? 'B' : 'R');
    // printTree(root->left);
    // printTree(root->right);

    //inorder
    printTreeInorder(root->left);
    printf("%d(%c) ", root->val, root->color == BLACK ? 'B' : 'R');
    printTreeInorder(root->right);

    //postorder
    // printTree(root->right);
    // printTree(root->left);
    // printf("%d ", root->val);


}

