#include <stdlib.h>
#include <stdio.h>

struct node_t {
    int value;
    struct node_t* left;
    struct node_t* right;
};

struct node_t* add(struct node_t* root, int value) {
    if(root == NULL) {
        struct node_t* new_node = malloc(sizeof(struct node_t));
        new_node->value = value;
        new_node->left = new_node->right = NULL;
        
        return new_node;
    }

    if(root->value > value) {
        root->left = add(root->left, value);
    } else if (root->value < value) {
        root->right = add(root->right, value);
    } else {
        printf("New value matche existing value");
    }

    return root;

    // while(1) {
    //     if(root->value != value) {
    //         if(root->value > value) {
    //             if(root->left == NULL) {
    //                 root->left = new_node;
    //                 break;
    //             } else {
    //                 root = root->left;
    //             }
    //         } else {
    //             if(root->right == NULL) {
    //                 root->right = new_node;
    //                 break;
    //             } else {
    //                 root = root->right;
    //             }
    //         }
    //     }
    // }
}

void print_tree(struct node_t* root) {
    if(root == NULL) return;

    print_tree(root->left);
    
    printf("%d\n", root->value);

    print_tree(root->right);
}

int main() {
    struct node_t* root = add(NULL, 5);
    add(root, 10);
    add(root, 3);
    add(root, 1);
    add(root, 4);

    print_tree(root);

    return 0;
}