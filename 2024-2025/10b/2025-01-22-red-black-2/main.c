#include <stdlib.h>
#include <stdio.h>

struct tree_node_t {
  int value;
  int color; // 0 = black, 1 = red
  struct tree_node_t* parent;
  struct tree_node_t* left;
  struct tree_node_t* right;
};
typedef struct tree_node_t tree_node_t;

tree_node_t* init_set_node(int value) {
  tree_node_t *node = malloc(sizeof(tree_node_t));
  node->left = node->right = node->parent = NULL;
  node->value = value;
  node->color = 1;
  return node;
}

tree_node_t* rotate_nodes(tree_node_t* root, int type) {
  switch(type) {
    // left-left
    case 1: {
      // root = root->left;
      // root->left->right = root;
      tree_node_t* old_root = root;
      tree_node_t* old_left = root->left;
      tree_node_t* old_b = root->left->right;

      root = old_left;
      old_left->right = old_root;
      old_root->left = old_b;

      old_left->parent = old_root->parent;
      old_root->parent = old_left;
      break;
    }
    // right-right
    // case 2: {
    //   tree_node_t* old_root = root;
    //   tree_node_t* old_right = root->right;
    //   tree_node_t* old_b = root->right->left;

    //   root = old_right;
    //   old_right->left = old_root;
    //   old_root->right = old_b;
    //   break;
    // }
    // left-right
    // case 3: {
    //   root->left = rotate_nodes(root->left, 2);
    //   root = rotate_nodes(root, 1);
    //   break;
    // }
    // // right-left
    // case 4: {
    //   root->right = rotate_nodes(root->right, 1);
    //   root = rotate_nodes(root, 2);
    //   break;
    // }
  }

  return root;
}

void balance_tree(tree_node_t * current) {
  tree_node_t *parent = current->parent;
  // I3
  if(parent == NULL) return;
  // I1
  if(parent->color == 0) return;

  tree_node_t *grandparent = parent->parent;
  // I4
  if(grandparent == NULL) {
    parent->color = 0;
    return;
  }

  int child_dir = 0;
  if(current == parent->right) child_dir = 1;

  int parent_dir = 0;
  if(parent == grandparent->right) parent_dir = 1;

  tree_node_t *uncle = grandparent->left;
  if(parent_dir == 0) uncle = grandparent->right;

  // I2
  if(parent->color == 1 && uncle->color == 1) {
    parent->color = 0;
    uncle->color = 0;
    grandparent->color = 1;
    balance_tree(grandparent);
    return;
  }

  // I5
  if(child_dir != parent_dir) {
    rotate_nodes(parent, child_dir + 1);
    current = parent;
    parent = grandparent->left;
    if(child_dir == 1) parent = grandparent->right;
    child_dir = parent_dir;
  }

  // I6
  if(child_dir == parent_dir) {
    rotate_nodes(grandparent, parent_dir + 1);

    parent->color = 0;
    grandparent->color = 1;
  }
}

tree_node_t* add(tree_node_t *root, int value) {
  if(root == NULL) {
    tree_node_t* new_node = init_set_node(value);
    return new_node;
  }

  tree_node_t** new_node_pos = NULL;
  int inner_dir = 0;
  if(root->value > value)
    new_node_pos = &root->left;
  else {
    new_node_pos = &root->right;
    inner_dir = 1;
  }

  if(*new_node_pos != NULL) {
    *new_node_pos = add(*new_node_pos, value);
    return root;
  } else {
    tree_node_t* new_node = init_set_node(value);
    new_node->parent = root;
    *new_node_pos = new_node;

    balance_tree(new_node);
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

struct queue_t {
    void* value;
    struct queue_t* next;
};

struct queue_t* create_node(void* value) {
    struct queue_t* new_node = malloc(sizeof(struct queue_t));
    new_node->value = value;
    new_node->next = NULL;

    return new_node;
}

struct queue_t* queue_add(struct queue_t* head, void* value) {
    struct queue_t* new_node = create_node(value);

    if(head == NULL) return new_node;

    struct queue_t* curr = head;
    while(curr->next != NULL) curr = curr->next;

    curr->next = new_node;

    return head;
}

void* queue_remove(struct queue_t** head) {
  void* value = (*head)->value;

  struct queue_t* old_head = *head;
  (*head) = (*head)->next;
  free(old_head);

  return value;
}

void print_tree_bfs(tree_node_t* root) {
  if(root == NULL) return;

  struct queue_t* q = create_node(root);
  // struct queue_t* q = init_queue();
  // queue_add(q, root);

  // while(!queue_empty(q)) {
  while(q != NULL) {
    tree_node_t* curr = queue_remove(&q);

    if(curr == NULL) continue;

    printf("%d [%d]\n", curr->value, curr->color);

    q = queue_add(q, curr->left);
    q = queue_add(q,curr->right);
  }
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
  my_tree = add(my_tree, 21);
  my_tree = add(my_tree, 22);

  // print_tree(my_tree);
  print_tree_bfs(my_tree);

  // printf("%d\n", set1->size);
  // print_set(set1);
  // printf("%d\n", set2->size);
  // print_set(set2);

  // printf("%d %d\n", set_contains(set1, 3), set_contains(set1, 4));
  // printf("%d\n", is_subset(set1, set2));

  // my_tree = add(my_tree, 0);
  // my_tree = add(my_tree, 10);
  // my_tree = add(my_tree, 5);

  // my_tree = rotate_nodes(my_tree, 4);
  // printf("%d\n", my_tree->value);
  // printf("%d\n", my_tree->left->value);
  // printf("%d\n", my_tree->right->value);

  return 0;
}