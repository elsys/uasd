#include <stdlib.h>
#include <stdio.h>

struct tree_node_t {
  int value;
  struct tree_node_t* left;
  struct tree_node_t* right;
};
typedef struct tree_node_t tree_node_t;

struct set_t {
  tree_node_t* root;
};
typedef struct set_t set_t;

set_t* init_set() {
  set_t *set = malloc(sizeof(set_t));
  set->root = NULL;
  return set;
}

tree_node_t* init_set_node(int value) {
  tree_node_t *node = malloc(sizeof(tree_node_t));
  node->left = node->right = NULL;
  node->value = value;
  return node;
}

// int set_contains(set_t *set, int value) {
//   for(int i = 0; i < set->size; i++)
//     if(set->data[i] == value)
//       return 1;
//   return 0;
// }

void add_recurse(tree_node_t* node, int value) {
  if(node == NULL) {
    tree_node_t* new_node = init_set_node(value);
    node = new_node;
    return;
  }

  if(node->value > value) {
    // left
    add_recurse(node->left, value);
  } else if (node->value < value) {
    // right
    add_recurse(node->right, value);
  }
}

void add(set_t *set, int value) {
  if(set->root == NULL) {
    tree_node_t* new_node = init_set_node(value);
    set->root = new_node;
    return;
  }

  if(set->root->value > value) {
    // left
    add_recurse(set->root->left, value);
  } else if (set->root->value < value) {
    // right
    add_recurse(set->root->right, value);
  }
}

// int is_subset(set_t *big, set_t *small) {
//   for(int i = 0; i < small->size; i++)
//     if(!set_contains(big, small->data[i]))
//       return 0;

//   return 1;
// }

// void print_set(set_t *set) {
//   for(int i = 0; i < set->size; i++)
//     printf("%d ", set->data[i]);
//   printf("\n");
// }

int main() {
  set_t *set1 = init_set();
  add(set1, 1);
  add(set1, 2);
  add(set1, 3);

  set_t *set2 = init_set();
  add(set2, 4);
  add(set2, 2);

  // printf("%d\n", set1->size);
  // print_set(set1);
  // printf("%d\n", set2->size);
  // print_set(set2);

  // printf("%d %d\n", set_contains(set1, 3), set_contains(set1, 4));
  // printf("%d\n", is_subset(set1, set2));
  return 0;
}