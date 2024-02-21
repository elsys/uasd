#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct node_t {
    int value;
    int color;
    struct node_t* left;
    struct node_t* right;
    struct node_t* parent;
};


void print_tree(struct node_t* root) {
    if(root == NULL) return;
    
    printf("%p value=%d color=%d paren=%p left=%p right=%p\n", 
        root,
        root->value,
        root->color,
        root->parent,
        root->left,
        root->right
    );

    print_tree(root->left);
    print_tree(root->right);
}

// struct node_t* rotate_ll(struct node_t* root) {
//     struct node_t* child = root->left;
//     // struct node_t* grandchild = child->left;

//     root->left = child->right;
//     child->right = root;

//     return child;
// }

// struct node_t* rotate_rr(struct node_t* root) {
//     struct node_t* child = root->right;
//     // struct node_t* grandchild = child->right;

//     root->right = child->left;
//     child->left = root;

//     return child;
// }

// struct node_t* rotate_rl(struct node_t* root) {
//     root->left = rotate_rr(root->left);
//     root = rotate_ll(root);

//     return root;
// }

// struct node_t* rotate_lr(struct node_t* root) {
//     root->right = rotate_ll(root->right);
//     root = rotate_rr(root);

//     return root;
// }

#define BLACK 0
#define RED 1

struct node_t* add(struct node_t* root, int value) {
    if(root == NULL) {
        struct node_t* new_node = malloc(sizeof(struct node_t));
        new_node->value = value;
        new_node->color = BLACK;
        new_node->left = new_node->right = new_node->parent = NULL;
        
        return new_node;
    }

    struct node_t* N = NULL;

    if(root->value > value) {
        N = root->left = add(root->left, value);
        root->left->parent = root;
        root->left->color = RED;
    } else if (root->value < value) {
        N = root->right = add(root->right, value);
        root->right->parent = root;
        root->right->color = RED;
    } else {
        printf("New value matche existing value");
    }

    struct node_t* P = root;
    struct node_t* G = P->parent;
    if(G != NULL) {
        struct node_t* U = P == G->left ? G->right : G->left;

        // Case 1
        if(P->color == BLACK) return root;

        // Case 2
        do{
            P->color = BLACK;
            U->color = BLACK;
            G->color = RED;
            N = G;
            P = N->parent;
            G = P->parent;
            U = P == G->left ? G->right : G->left;
        } while(P != NULL);
    }
    // Case 3/4
    N->color = BLACK;

    if(
        N->color == RED && 
        P->color == RED && 
        U->color == BLACK && 
        G->color == BLACK
    ) {
        // Case 5
        if(
            N == P->right
        ) {
            P->right = N->left;
            P->right->parent = P;

            N->left = P;
            P->parent = N;
            N->parent = G;
            G->left = N;

            P = N;
            N = P->left;
        }
        // Case 6
        if(
            N == P->left
        ) {
            G->left = P->right;
            G->left->parent = G;

            P->right = G;
            P->parent = G->parent;
            G->parent = P;
        }
    }




    return root;
}

int main() {
    struct node_t* root = add(NULL, 20);

    root = add(root, 10);
    // printf("\n" );
    root = add(root, 30);
    // printf("\n" );

    add(root, 5);
    // printf("\n" );
    // add(root, 50);
    // printf("\n" );

    print_tree(root);

    return 0;
}