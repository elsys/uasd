#include <stdlib.h>
#include <stdio.h>

struct node_t {
  struct node_t* next;
  struct node_t* prev;
  int value;
};

// Create a new node - allocate memory, point pointers to NULL, set the value
struct node_t* create(int value) {
  struct node_t* new_node = malloc(sizeof(struct node_t));
  new_node->prev = new_node->next = NULL;
  new_node->value = value;
  return new_node;
}

// Add a new node to the end of the list
struct node_t* push_back(struct node_t* head, int value) {
  // The list is empty
  if(head == NULL) return create(value);

  // There's only 1 node
  if(head->next == NULL) {
    struct node_t* new_node = create(value);
    head->next = new_node;
    new_node->prev = head;
  } else {
    // Recursively search for the end of the list
    push_back(head->next, value);
  }

  return head;
}

void print_list(struct node_t* head) {
  // Print all nodes and pointers:
  // address of prev <- address of curr [value of curr] -> address of next
  while(head != NULL) {
    printf(
      "%p <- %p[%d] -> %p\n",
      head->prev,
      head,
      head->value,
      head->next
    );
    head = head->next;
  }
}

// Assume the nodes are consecutive and left is before right
// All pointers must be reassigned in such an order so that we don't lose access to any node
// P | n1-> | L | n2-> | R | n3-> | N
//   | <-p1 |   | <-p2 |   | <-p3 |
void swap_nodes(
  struct node_t* left,
  struct node_t* right
) {
  if(left == NULL || right == NULL) return;

  // P->n1 = R (no prev node if left == head)
  if(left->prev != NULL) left->prev->next = right;
  // L->n2 = N
  left->next = right->next;
  // R->n3 = L
  right->next = left;

  // N->p3 = L (no next node if right == tail)
  // Note: due to the order of the reassigns right->next points to L and left->next points to N
  if(left->next != NULL) left->next->prev = left;
  // R->p2 = P
  right->prev = left->prev;
  // L->p1 = R
  left->prev = right;
}

struct node_t* sort_list(struct node_t* head) {
  // Test the swap function
  /*struct node_t* left = head->next->next->next;
  struct node_t* right = head->next->next->next->next;

  //swap_nodes(head, head->next);
  //head = head->prev;
  swap_nodes(left, right);
  //head = right;*/

  // Improved bubble  sort with non-consecutive node swaps
  /*for(
    struct node_t* left = head;
    left->next != NULL;
    left = left->next
  ) {
    for(
      struct node_t* right = left->next;
      right != NULL;
      right = right->next
    ) {
      printf("%d <> %d\n", left->value, right->value);*/
      /*if(left->value > right->value)  {
        swap_nodes(left, right);
        if(head == left)
          head = right;

        right = left;
        left = right->next;
      }*/
  //  }
  //}

  // Basic bubble sort which always swaps neighbors
  int has_swaps = 1;
  while(has_swaps) {
    has_swaps = 0;

    print_list(head);
    // Iterate from the first node to the second to last
    for(
      struct node_t* left = head;
      left->next != NULL;
      left = left->next
    ) {
      // Right will always be the next neighbor of left
      struct node_t* right = left->next;

      printf("%d <> %d\n", left->value, right->value);
      if(left->value > right->value)  {
        // Swap all the list position of the nodes by swapping all pointers to and from them
        swap_nodes(left, right);
        // Don't forget to update the head if you swap the first node
        if(head == left)
          head = right;

        // The node positions are swapped so we have P <-> R <-> L <-> N
        // We want to reassign right to L  and left to R to maintain correct positions in the iteration
        right = left;
        left = right->prev;
        has_swaps = 1;
      }
    }
  }

  return head;
}

int main() {
  struct node_t* list = create(5);

  push_back(list, 8);
  push_back(list, 3);
  push_back(list, 7);
  push_back(list, -1);

  //print_list(list);
  list = sort_list(list);
  print_list(list);
	return 0;
}
