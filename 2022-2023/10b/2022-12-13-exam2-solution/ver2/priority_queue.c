#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"
#include "priority_queue.h"

struct priority_queue_t* init_queue() {
  struct priority_queue_t* q = malloc(sizeof(struct priority_queue_t));

  q->size = 0;
  q->subqueues = NULL;

  return q;
}

void push_queue(
  struct priority_queue_t* q,
  int value,
  int priority
) {
  priority++;

  if(q->size < priority) {
    q->subqueues = realloc(
      q->subqueues,
      sizeof(struct list_node_t*) * priority
    );
    for(int i = q->size; i < priority; i++)
      q->subqueues[i] = NULL;
    q->size = priority;
  }

  q->subqueues[priority - 1] = push_list(
    q->subqueues[priority - 1],
    value
  );
}

// Notice the 3 different solutions to the same problem - find a sublist, pop, update the sublist and potentially point to NULL if empty

int pop_queue(struct priority_queue_t* q) {
  // The entire queue is empty
  if(q->size == 0) return 0;

  struct list_node_t* sublist = NULL;
  // We want to remember the index of the found sublist
  int list_index = 0;

  // Solution 1 - okay
  // Find the first sublist that contains any items
  for(; list_index < q->size; list_index++)
    if(q->subqueues[list_index] != NULL) {
      sublist = q->subqueues[list_index];
      // Break on the first non-NULL sublist
      break;
    }

  // Solution 2 - same result, less syntax
  // while(sublist == NULL) {
  //   sublist = q->subqueues[list_index++];
  // }
  // list_index--;

  int value = pop_list(&sublist);
  // Update the sublist in the queue
  q->subqueues[list_index] = sublist;



  // Solution 3 - shortest and simplest code
  // // More optimal alternative that uses pointers to edit the sublist directly without a helper var
  // // Pointer to the first item in the dynamic array
  // struct list_node_t** sublist = q->subqueues;
  // // By incrementing the pointer it moves to the next item in the array
  // while((*sublist) == NULL) sublist++;

  // // pop_list expects a double pointer and we already have that
  // // because sublist points directly inside the dynamic array
  // int value = pop_list(sublist);

  return value;
}

void print_queue(struct priority_queue_t* q) {
  int i = 0;

  for(
    int priority = 0;
    priority < q->size;
    priority++
  ) {
    struct list_node_t* subqueue = q->subqueues[priority];

    while(subqueue != NULL) {
      printf(
        "[%d] v=%d p=%d\n",
        i++,
        subqueue->value,
        priority
      );
      subqueue = subqueue->next;
    }
  }
}