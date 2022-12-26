#include "bst.h"

int main() {
  struct node_t* root = create_node(10);
  add(root, 6);
  add(root, 16);
  add(root, 5);
  add(root, 2);
  add(root, 4);
  add(root, 12);
  
  print_dfs(root, 0);
  
  root = balance_tree(root);
  print_dfs(root, 0);
  
  return 0;
}
