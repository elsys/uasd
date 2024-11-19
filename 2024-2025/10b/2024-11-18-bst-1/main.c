#include <stdlib.h>
#include <stdio.h>

struct tree_node_t {
  int value;
  struct tree_node_t* left;
  struct tree_node_t* right;
};
typedef struct tree_node_t tree_node_t;

tree_node_t* init_set_node(int value) {
  tree_node_t *node = malloc(sizeof(tree_node_t));
  node->left = node->right = NULL;
  node->value = value;
  return node;
}

tree_node_t* add(tree_node_t *root, int value) {
  if(root == NULL) {
    tree_node_t* new_node = init_set_node(value);
    return new_node;
  }

  if(root->value > value) {
    // left
    root->left = add(root->left, value);
  } else if (root->value < value) {
    // right
    root->right = add(root->right, value);
  }

  return root;
}

void print_tree(tree_node_t* root) {
  if(root == NULL) {
    return;
  }

  printf("%p %d %p %p\n", root, root->value, root->left, root->right);

  print_tree(root->left);
  printf("%d\n", root->value);
  print_tree(root->right);
}

int main() {
  tree_node_t *my_tree = NULL;
  my_tree = add(my_tree, 10);
  my_tree = add(my_tree, 6);
  my_tree = add(my_tree, 7);
  my_tree = add(my_tree, 3);
  my_tree = add(my_tree, 15);
  my_tree = add(my_tree, 13);
  my_tree = add(my_tree, 20);

  print_tree(my_tree);

  // printf("%d\n", set1->size);
  // print_set(set1);
  // printf("%d\n", set2->size);
  // print_set(set2);

  // printf("%d %d\n", set_contains(set1, 3), set_contains(set1, 4));
  // printf("%d\n", is_subset(set1, set2));
  return 0;
}