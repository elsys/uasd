#include <stdlib.h>
#include <stdio.h>

#include "queue.h"

struct node_t {
    int value;
    struct node_t* left;
    struct node_t* right;
};


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


int get_branch_size(struct node_t* root) {
    if(root == NULL) return 0;

    int left = get_branch_size(root->left);
    int right = get_branch_size(root->right);

    return left + right + 1;
}

int get_branch_difference(struct node_t* root) {
    int left = get_branch_size(root->left);
    int right = get_branch_size(root->right);

    return left - right;
}

struct node_t* rotate_nodes(struct node_t* root) {
  puts("Perform Left-Left rotation");
  print_bfs(root);

  struct node_t* tmp = root;
  root = root->left;
  tmp->left = NULL;
  root->right = tmp;

  return root;
}

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

    if(get_branch_difference(root) > 1) {
        printf("node %d needs to balance aafter adding %d\n", root->value, value);
        root = rotate_nodes(root);
    }

    return root;
}

int main() {
    struct node_t* root = add(NULL, 10);

    add(root, 8);
    add(root, 20);

    add(root, 4);
    add(root, 15);

    add(root, 2);
    add(root, 3);
    
    // add(root, 1);

    print_bfs(root);

    printf("%d\n", get_branch_difference(root));

    return 0;
}