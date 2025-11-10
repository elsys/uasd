#include <stdio.h>
#include <stdlib.h>

struct node_t {
  int value;
  struct node_t* left;
  struct node_t* right;
};
typedef struct node_t node_t;

node_t* node_create(int value) {
  node_t* n = (node_t*)malloc(sizeof(node_t));
  n->value = value;
  n->left = NULL;
  n->right = NULL;
  return n;
}

struct bst_t {
  node_t* root;
  int size;
};
typedef struct bst_t bst_t;

bst_t* bst_create() {
  bst_t* s = (bst_t*)malloc(sizeof(bst_t));
  s->root = NULL;
  s->size = 0;
  return s;
}

node_t* bst_push_internal(node_t* root, int value) {
  if(root == NULL) {
    return node_create(value);
  }

  if(value < root->value) {
    root->left = bst_push_internal(root->left, value);
  } else if(value > root->value) {
    root->right = bst_push_internal(root->right, value);
  }
  return root;
}

void bst_push(bst_t* s, int value) {
  s->root = bst_push_internal(s->root, value);
  s->size++;
}

void bst_print_dfs(node_t* root) {
  if(root == NULL) {
    return;
  }

  bst_print_dfs(root->left);
  printf("%d ", root->value);
  bst_print_dfs(root->right);
}

struct queue_node_t {
  node_t* tree_node;
  struct queue_node_t* next;
};

typedef struct queue_node_t queue_node_t;

struct queue_t {
  queue_node_t* front;
  queue_node_t* back;
};

typedef struct queue_t queue_t;

queue_t* queue_create() {
  queue_t* q = (queue_t*)malloc(sizeof(queue_t));
  q->front = NULL;
  q->back = NULL;
  return q;
}

int queue_is_empty(queue_t* q) {
  return q->front == NULL;
}

void queue_enqueue(queue_t* q, node_t* tree_node) {
  queue_node_t* new_node = (queue_node_t*)malloc(sizeof(queue_node_t));
  new_node->tree_node = tree_node;
  new_node->next = NULL;

  if(q->back != NULL) {
    q->back->next = new_node;
  }
  q->back = new_node;

  if(q->front == NULL) {
    q->front = new_node;
  }
}

node_t* queue_dequeue(queue_t* q) {
  if(queue_is_empty(q)) {
    return NULL;
  }

  queue_node_t* front_node = q->front;
  node_t* tree_node = front_node->tree_node;
  q->front = front_node->next;

  if(q->front == NULL) {
    q->back = NULL;
  }

  free(front_node);
  return tree_node;
}

void bst_print_bfs(node_t* root) {
  if(root == NULL) {
    return;
  }

  queue_t* q = queue_create();
  queue_t* temp = queue_create();
  queue_enqueue(q, root);
  while(!queue_is_empty(q)) {
    node_t* current = queue_dequeue(q);

    if(current == NULL) {
      printf("N ");
      continue;
    }

    printf("%d ", current->value);

    queue_enqueue(temp, current->left);
    queue_enqueue(temp, current->right);

    if(queue_is_empty(q)) {
      queue_t* swap = q;
      q = temp;
      temp = swap;
      printf("\n");
    }
  }
}

int main() {
  bst_t* s = bst_create();
  bst_push(s, 10);
  bst_push(s, 4);
  bst_push(s, 2);
  bst_push(s, 6);
  bst_push(s, 5);
  bst_push(s, 15);
  bst_push(s, 12);
  // for(int i = 0; i < 10; i++) {
  //   bst_push(s, i);
  // }

  // bst_print_dfs(s->root);
  bst_print_bfs(s->root);

  return 0;
}