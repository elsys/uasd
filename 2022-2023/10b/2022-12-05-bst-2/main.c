#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
  int c = *a;
  *a = *b;
  *b = c;
}

void quick_sort(int *arr, unsigned int size) {
  printf("Start: %p Size: %d End: %p\n", 
  arr, size, arr + size - 1);

  // recursion condition
  if(size < 2) return;
  
  // choose pivot
  int pivot_index = size-1; // int is rounded down

  printf("Pivot at %d = %d\n", 
  pivot_index, arr[pivot_index]);
  
  // rearrange around pivot
  for(int i = 0; i < pivot_index; i++) {
    printf("Compare [%d]%d ? [%d]%d\n", 
    i, arr[i], pivot_index, arr[pivot_index]);
    if(arr[i] > arr[pivot_index]) {
      // move to the right
      printf("Swap [%d]%d with [%d]%d\n", 
    i, arr[i], pivot_index, arr[pivot_index]);
    
      swap(arr + i, arr + pivot_index - 1);
      swap(arr + pivot_index-1, arr+pivot_index);
      pivot_index--;
      i--;
      for(int j = 0; j < size; j++)
        printf("[%d] %d ", j, arr[j]);
      puts(""); // printf("\n");
    }
  }

  puts("");
  // call recursively for left half and right half
  printf("Left sort\n");
  quick_sort(arr, pivot_index);
  
  printf("Right sort\n");
  quick_sort(arr + pivot_index + 1, size - pivot_index - 1);
}


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

struct vector_t {
  int* values;
  int count;
};

void add_to_vector(struct vector_t* vec, int value) {
  vec->values = realloc(
    vec->values, 
    sizeof(int) * (vec->count + 1)
  );
  vec->values[vec->count] = value;
  vec->count++;
}

void gather_values(
  struct node_t* root, 
  struct vector_t* vec
) {
  if(root == NULL) return;
  
  add_to_vector(vec, root->value);
  
  gather_values(root->left, vec);
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
  // find middle and make new root
  // build tree from the rest
  
  // array from all nodes
  struct vector_t* all_values = malloc(sizeof(struct vector_t));
  all_values->values = NULL;
  all_values->count = 0;
  
  gather_values(root, all_values);
  // sort array
  quick_sort(
    all_values->values,
    all_values->count
  );
  
  for(int i = 0; i < all_values->count; i++)
    printf("[%d] %d ", i, all_values->values[i]);
  puts("");
  
  root = generate_tree(
    all_values->values,
    all_values->count
  );

  return root;
}

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
