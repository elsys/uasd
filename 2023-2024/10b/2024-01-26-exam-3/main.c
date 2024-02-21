#include <stdio.h>
#include <stdlib.h>

struct node_t {
    char* name;
    vector* children;

    char var_name;
    char condition;
    int target_value;
};

struct node_t* create_node() {
    struct node_t* new_node = malloc(sizeof(struct node_t));
    new_node->children = init_vector();

    // new_node->name = strtok(step, " ");
    new_node->name = NULL;
    new_node->var_name = 0; // == '\0'
    new_node->condition = 0;
    new_node->target_value = 0;

    return new_node;
}

void populate_node(char* step, struct node_t* node) {
    node->name = strtok(step, " ");

    struct node_t* new_child = create_node();
    new_child->name = ???;
    vector_add(node->children, new_child);
}

struct node_t* find_node(char* name, struct node_t* root) {
    if(strcmp(root->name, name) == 0) return root;

    for(int i =0; i < root->children->size; i++) {
        struct node_t* found = find_node(name, root->children[i])
        if(found != NULL) return found;
    }

    return NULL;
}

struct node_t* add_node(char* step, struct node_t* root) {
    if(root == NULL) {
        struct node_t* new_node = create_node();
        populate_node(step, new_node);
        return new_node;
    }

    char* search_name = ???;
    struct node_t* curr = find_node(search_name, root);
    populate_node(step, curr);

    return root;
}

int main() {
    struct node_t* root = add_node("A x gt 5 B C", NULL);
    return 0;
}