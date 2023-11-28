#include <stdlib.h>
#include <stdio.h>

#include "queue.h"

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

void print_bfs(struct node_t* root) {
    if(root == NULL) return;

    queue_t* q = init_queue();
    queue_t* next = init_queue();

    queue_push(q, root);

    while(!queue_empty(next) || !queue_empty(q)) {
        while(!queue_empty(q)) {
            struct node_t* curr = queue_pop(q);
            printf("%d ", curr->value);

            if(curr->left != NULL)
                queue_push(next, curr->left);
            if(curr->right != NULL)
                queue_push(next, curr->right);
        }

        printf("\n");
        queue_t* tmp = q;
        q = next;
        next = tmp;
    }
}

struct node_t* arrange_tree(struct node_t** nodes, int count) {
    struct node_t* root = nodes[count/2];
    
    root->left = arrange_tree(nodes, count/2);
    root->right = arrange_tree(nodes + count/2, count/2);

    return root;
}

void gather_nodes(struct node_t* root, struct node_t*** nodes, int* count) {
    // struct node_t* nodes = malloc(???);

    if(root->left != NULL)
        gather_nodes(root->left, nodes, count);

    *nodes = realloc(*nodes, sizeof(struct node_t*) * (*count + 1));
    (*nodes)[*count] = root;
    (*count)++;

    if(root->right != NULL)
        gather_nodes(root->right, nodes, count);

    // return nodes;
}

struct node_t* balance_tree(struct node_t* root) {
    struct node_t** nodes = NULL;
    int count = 0;

    gather_nodes(root,&nodes,  &count);

    return arrange_tree(nodes, count);
}

int main() {
    struct node_t* root = add(NULL, 10);

    add(root, 6);
    add(root, 15);

    add(root, 4);
    add(root, 8);
    add(root, 25);

    add(root, 7);
    add(root, 23);
    add(root, 30);

    // print_tree(root);

    print_bfs(root);

    root = balance_tree(root);
    print_bfs(root);

    return 0;
}