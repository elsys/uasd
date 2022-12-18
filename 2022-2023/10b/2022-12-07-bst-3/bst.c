#include <stdio.h>
#include <stdlib.h>

#include "bst.h"
#include "quicksort.h"
#include "vector.h"

struct node_t * create_node(int value) {
  struct node_t * new_node = malloc(sizeof(struct node_t));
  new_node->value = value;
  new_node->left = new_node->right = NULL;
  
  return new_node;
}

void add(struct node_t *root, int value) {  
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
  
  if(root->left != NULL)
    printf("L");
  print_dfs(root->left, level + 1);
  
  printf("[%d] %d\n", level, root->value);

  if(root->right != NULL)
    printf("R");
  print_dfs(root->right, level + 1);
}

void gather_values(
  struct node_t* root, 
  struct vector_t* vec
) {
  if(root == NULL) return;
  
  gather_values(root->left, vec);
  add_to_vector(vec, root->value);
  gather_values(root->right, vec);
}

struct node_t* generate_tree(int* values, int count) {
  if(count == 0) return NULL;
  if(count == 1) return create_node(values[0]);
  
  int pivot = count/2;
  struct node_t* root = create_node(
    values[pivot]
  );
  
  root->left = generate_tree(values, pivot);
  root->right = generate_tree(
    values + pivot + 1, 
    count - pivot - 1
  );
  
  return root;
}

struct node_t* balance_tree(struct node_t* root) {
  struct vector_t* all_values = malloc(sizeof(struct vector_t));
  all_values->values = NULL;
  all_values->count = 0;
  
  gather_values(root, all_values);
  for(int i = 0; i < all_values->count; i++)
    printf("values[%d]=%d\n", i, all_values->values[i]);
  /*quick_sort(
    all_values->values,
    all_values->count
  );*/
  
  for(int i = 0; i < all_values->count; i++)
    printf("[%d] %d ", i, all_values->values[i]);
  puts("");
  
  root = generate_tree(
    all_values->values,
    all_values->count
  );

  return root;
}
