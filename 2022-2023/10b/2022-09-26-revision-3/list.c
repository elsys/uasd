#include <stdio.h>
#include <stdlib.h>

#include "list.h"

struct list_node_t * create_node(int value) {
  struct list_node_t *new_node = malloc(
    sizeof(struct list_node_t)
  );

  new_node->value = new_value;
  new_node->next = NULL;

  return new_node;
}

void print_list(struct list_node_t *head) {
  while(head != NULL) {
    printf("%d\n", head->value);
    head = head->next;
  }
}

struct list_node_t * push_front(struct list_node_t *head, int new_value) {
  /*struct list_node_t *new_node = malloc(
    sizeof(struct list_node_t)
  );

  new_node->value = new_value;*/
  struct list_node_t *new_node = create_node(new_value);
  new_node->next = head;

  // head = new_node;
  return new_node;
}

struct list_node_t * push_back(struct list_node_t *head, int new_value) {
  /*struct list_node_t *new_node = malloc(
    sizeof(struct list_node_t)
  );

  new_node->value = new_value;
  new_node->next = NULL;*/
  if(head == NULL) return push_front(NULL, new_value);

  struct list_node_t *new_node = create_node(new_value);

  struct list_node_t *tail = head;
  /*while(tail->next != NULL) {
    tail = tail->next;
  }*/
  for(; tail->next != NULL; tail = tail->next);

  tail->next = new_node;

  return head;
}