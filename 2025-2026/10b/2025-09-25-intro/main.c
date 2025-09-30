#include <stdlib.h>
#include <stdio.h>

struct list_node_t {
  struct list_node_t *next;
  int value;
};

typedef struct list_node_t list_node_t;

list_node_t* create_node(int value) {
  list_node_t *node = malloc(sizeof(list_node_t));
  node->next = NULL;
  node->value = value;
  return node;
}

void push_front(list_node_t **head, int value) {
  if(head == NULL) {
    return;
  }
  list_node_t *node = create_node(value);
  node->next = *head;
  *head = node;
}
// struct list_node_t * push_front(struct list_node_t *head, int value)

void push_back(list_node_t **head, int value) {
  if(head == NULL) {
    return;
  }
  if(*head == NULL) {
    push_front(head, value);
    return;
  }
  list_node_t *node = create_node(value);
  list_node_t *cur = *head;
  while (cur->next != NULL) {
    cur = cur->next;
  }
  cur->next = node;
}


list_node_t* push_back_v2(list_node_t *head, int value) {
  if(head == NULL) {
    list_node_t *node = create_node(value);
    return node;
  }
  list_node_t *node = create_node(value);
  list_node_t *cur = head;
  while (cur->next != NULL) {
    cur = cur->next;
  }
  cur->next = node;
  return head;
}


int main() {
  // push_front(NULL, 42);
  // push_back(1234, 42);

  list_node_t *head = NULL;
  // push_front(&head, 42);
  push_back(&head, 42);

  printf("%d\n", head->value);
  return 0;
}