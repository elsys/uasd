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

struct node_t* rotate_rr(struct node_t* root) {
    struct node_t* child1 = root->right;
    // struct node_t* child2 = child1->right;

    root->right = child1->left;
    child1->left = root;

    int r_left_count = root->left != NULL ? root->left->child_count + 1 : 0;
    int r_right_count = root->right != NULL ? root->right->child_count + 1 : 0;
    root->child_count = r_left_count + r_right_count;

    int c_left_count = child1->left != NULL ? child1->left->child_count + 1 : 0;
    int c_right_count = child1->right != NULL ? child1->right->child_count + 1 : 0;
    child1->child_count = c_left_count + c_right_count;

    return child1;
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

    int left_count = root->left != NULL ? root->left->child_count + 1 : 0;
    int right_count = root->right != NULL ? root->right->child_count + 1 : 0;
    printf("%d %d %d\n", 
        root->value, 
        root->child_count, 
        right_count - left_count
    );

    if(abs(right_count - left_count) > 1) {
        if(right_count - left_count > 0) {
            // Right
            struct node_t* child = root->right;
            int r_left_count = child->left != NULL ? child->left->child_count + 1 : 0;
            int r_right_count = child->right != NULL ? child->right->child_count + 1 : 0;

            if(r_right_count - r_left_count > 0) {
                printf("Right-Right\n");
                root = rotate_rr(root);
            } else {
                printf("Right-Left\n");
            }
        } else {
            // Left
            printf("Left\n");
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