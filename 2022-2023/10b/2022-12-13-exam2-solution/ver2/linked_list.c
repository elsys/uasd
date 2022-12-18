#include <stdlib.h>

#include "linked_list.h"

struct list_node_t* init_list_node(
  int value
) {
  struct list_node_t* node = malloc(sizeof(struct list_node_t));

  node->value = value;
  node->next = node->tail = NULL;

  return node;
}

struct list_node_t* push_list(
  struct list_node_t* head,
  int value
) {
  struct list_node_t* new_node = init_list_node(value);

  // If the list is empty create a new head and point tail to itself
  if(head == NULL) {
    new_node->tail = new_node;
    return new_node;
  }

  // Add to the end of the list
  struct list_node_t* curr = head->tail;

  curr->next = new_node;
  head->tail = curr->next;

  return head;
}

int pop_list(struct list_node_t** head) {
  // Helper var for mbette readability
  struct list_node_t* head_ref = *head;

  if(head_ref == NULL) return 0;

  int value = head_ref->value;

  // Ensure the next tail pointer points to the correct tail
  if(head_ref->next != NULL)
    head_ref->next->tail = head_ref->tail;

  // Redirect the original head pointer to the next item
  (*head) = head_ref->next;

  return value;
}