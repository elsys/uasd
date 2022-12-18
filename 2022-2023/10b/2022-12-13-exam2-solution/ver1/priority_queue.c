#include <stdio.h>
#include <stdlib.h>

#include "priority_queue.h"

struct priority_queue_t* init_node(
  int value,
  int priority
) {
  struct priority_queue_t* node = malloc(sizeof(struct priority_queue_t));

  node->value = value;
  node->priority = priority;
  node->next = NULL;

  return node;
}

struct priority_queue_t* push(
  struct priority_queue_t* head,
  int value,
  int priority
) {
  // List is empty so just return the new head
  if(head == NULL)
    return init_node(value, priority);

  // The new item should be added to the front and become the new head
  if(head->priority > priority) {
    struct priority_queue_t* new_node = init_node(value, priority);

    new_node->next = head;
    return new_node;
  }

  // FInd where to place the item
  struct priority_queue_t* curr = head;
  while(
    // Either at the end of the list
    curr->next != NULL &&
    // Or in such place that the next item has a higher priority value
    curr->next->priority <= priority
  ) curr = curr->next;

  // Add to the list and return
  struct priority_queue_t* new_node = init_node(value, priority);

  new_node->next = curr->next;
  curr->next = new_node;

  return head;
}

// Remove the first element and return the value
int pop(struct priority_queue_t** head) {
  if((*head) == NULL) return 0;

  int value = (*head)->value;

  (*head) = (*head)->next;

  return value;
}

// Iterate the list and print each item
void print_queue(struct priority_queue_t* head) {
  int i = 0;

  while(head != NULL) {
    printf(
      "[%d] v=%d p=%d\n",
      i++,
      head->value,
      head->priority
    );
    head = head->next;
  }
}
