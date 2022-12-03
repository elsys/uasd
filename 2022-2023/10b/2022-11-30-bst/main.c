#include <stdio.h>
#include <stdlib.h>

struct node_t {
  int value;
  struct node_t *left;
  struct node_t *right;
};

struct node_t * create_node(int value) {
  struct node_t * new_node = malloc(sizeof(struct node_t));
  new_node->value = value;
  new_node->left = new_node->right = NULL;
  
  return new_node;
}

void add(struct node_t *root, int value) {
  
  //if(root->value > value) {
    // add left
  //  child = root->left;
    /*if(root->left == NULL) {
      root->left = create_node(value);
      return;
    } else {
      add(root->left, value);
    }*/
  //} else if(root->value <  value) {
  //if(root->value <  value) {
    // add right
   // child = &root->right;
    /*if(root->right == NULL) {
      root->right = create_node(value);
      return;
    } else {
      add(root->right, value);
    }*/
 // }
  
  struct node_t ** child = &root->left;
  
  if(root->value < value)
    child = &root->right;
  
  if(*child == NULL)
    *child = create_node(value);
  else
    add(*child, value);
}

void print_dfs(struct node_t* root, int level) {
  if(root == NULL) return;
  
  printf("[%d] %d\n", level, root->value);
  if(root->left != NULL)
    printf("L");
  print_dfs(root->left, level + 1);
  if(root->right != NULL)
    printf("R");
  print_dfs(root->right, level + 1);
}

int main() {
  struct node_t* root = create_node(10);
  add(root, 6);
  add(root, 16);
  add(root, 5);
  
  print_dfs(root, 0);
  return 0;
}
