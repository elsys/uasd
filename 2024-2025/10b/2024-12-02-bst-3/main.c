#include <stdlib.h>
#include <stdio.h>

struct tree_node_t {
  int value;
  int child_count;
  struct tree_node_t* left;
  struct tree_node_t* right;
};
typedef struct tree_node_t tree_node_t;

tree_node_t* init_set_node(int value) {
  tree_node_t *node = malloc(sizeof(tree_node_t));
  node->left = node->right = NULL;
  node->value = value;
  node->child_count = 0;
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
      break;
    }
    // right-right
    case 2: {
      tree_node_t* old_root = root;
      tree_node_t* old_right = root->right;
      tree_node_t* old_b = root->right->left;

      root = old_right;
      old_right->left = old_root;
      old_root->right = old_b;
      break;
    }
    // left-right
    case 3: {
      root->left = rotate_nodes(root->left, 2);
      root = rotate_nodes(root, 1);
      break;
    }
    // right-left
    case 4: {
      root->right = rotate_nodes(root->right, 1);
      root = rotate_nodes(root, 2);
      break;
    }
  }

  return root;
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

  root->child_count++;
  int left_children = root->left == NULL ? 0 : root->left->child_count + 1;
  int right_children = root->right == NULL ? 0 : root->right->child_count + 1;
  // if(root->right == NULL)
  //   right_children = 0;
  // else
  //   right_children = root->right->child_count + 1;
  if(left_children > right_children) {
    // left-???
    int left_left_children = root->left->left == NULL ? 0 : root->left->left->child_count + 1;
    int left_right_children = root->left->right == NULL ? 0 : root->left->right->child_count + 1;
    if(left_left_children > left_right_children) {
      // left-left
    } else if(left_left_children < left_right_children) {
      // left-right
    }
  } else if(left_children < right_children) {
    // right-???
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

    printf("%d [%d]\n", curr->value, curr->child_count);

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