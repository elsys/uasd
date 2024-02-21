#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct node_t {
    int value;
    struct node_t* left;
    struct node_t* right;
    int child_count;
};


void print_tree(struct node_t* root) {
    if(root == NULL) return;

    print_tree(root->left);
    
    printf("%p value=%d children=%d left=%p right=%p\n", 
        root,
        root->value,
        root->child_count,
        root->left,
        root->right
    );

    print_tree(root->right);
}

struct node_t* rotate_ll(struct node_t* root) {
    struct node_t* child = root->left;
    // struct node_t* grandchild = child->left;

    root->left = child->right;
    child->right = root;

    return child;
}

struct node_t* rotate_rr(struct node_t* root) {
    struct node_t* child = root->right;
    // struct node_t* grandchild = child->right;

    root->right = child->left;
    child->left = root;

    return child;
}

struct node_t* rotate_rl(struct node_t* root) {
    root->left = rotate_rr(root->left);
    root = rotate_ll(root);

    return root;
}

struct node_t* rotate_lr(struct node_t* root) {
    root->right = rotate_ll(root->right);
    root = rotate_rr(root);

    return root;
}


struct node_t* add(struct node_t* root, int value) {
    if(root == NULL) {
        struct node_t* new_node = malloc(sizeof(struct node_t));
        new_node->value = value;
        new_node->left = new_node->right = NULL;
        new_node->child_count = 0;
        
        return new_node;
    }

    if(root->value > value) {
        root->left = add(root->left, value);
    } else if (root->value < value) {
        root->right = add(root->right, value);
    } else {
        printf("New value matche existing value");
    }

    root->child_count++;

    int r_left_count = root->left != NULL ? root->left->child_count + 1 : 0;
    int r_right_count = root->right != NULL ? root->right->child_count + 1 : 0;

    if(abs(r_right_count - r_left_count) > 1) {
        struct node_t* child = NULL;
        struct node_t* grandchild = NULL;

        if(r_right_count > r_left_count) {
            // Right
            child = root->right;
            int c_left_count = child->left != NULL ? child->left->child_count + 1 : 0;
            int c_right_count = child->right != NULL ? child->right->child_count + 1 : 0;

            if(c_right_count > c_left_count) {
                // Right-Right
                root = rotate_rr(root);
            } else {
                // Right-Left
                root = rotate_rl(root);
            }
        } else {
            // Left
            child = root->left;
            int c_left_count = child->left != NULL ? child->left->child_count + 1 : 0;
            int c_right_count = child->right != NULL ? child->right->child_count + 1 : 0;

            if(c_right_count > c_left_count) {
                // Left-Right
                root = rotate_lr(root);
            } else {
                // Left-Left
                root = rotate_ll(root);
            }
        }
    }

    return root;
}

int main() {
    struct node_t* root = add(NULL, 10);

    root = add(root, 20);
    printf("\n" );
    root = add(root, 30);
    printf("\n" );

    // add(root, 40);
    // printf("\n" );
    // add(root, 50);
    // printf("\n" );

    print_tree(root);

    return 0;
}