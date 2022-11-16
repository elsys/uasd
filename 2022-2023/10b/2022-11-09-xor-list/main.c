#include <stdio.h>
#include <stdlib.h>

struct node_t {
  int value;
  void* pointer;
};

void print_list(struct node_t* head) {
  struct node_t* prev = NULL;
  
  while(head != NULL) {
    printf("%d\n", head->value);
    struct node_t* tmp = head;
    head = (long)head->pointer ^ (long)prev;
    //prev = (long)prev ^ (long)head;
    prev = tmp;
  }
}

struct node_t* add_to_front(struct node_t* head, int value) {
  struct node_t* new_node = malloc(sizeof(struct node_t));
  new_node->value = value;
  
  if(head != NULL) {
    new_node->pointer = head;
    head->pointer = (long)new_node ^ (long)head->pointer;
  } else {
    new_node->pointer = NULL;
  }
  
  return new_node;
}

struct node_t* add_to_back(struct node_t* head, int value) {
  if(head == NULL) return add_to_front(head, value);
  
  struct node_t* prev = NULL;
  
  while(head->pointer != prev) {
    struct node_t* tmp = head;
    head = (long)head->pointer ^ (long)prev;
    prev = tmp;
  }
  
  struct node_t* new_node = malloc(sizeof(struct node_t));
  new_node->value = value;
  
  new_node->pointer = head;
  head->pointer = (long)new_node ^ (long)head->pointer;
}

int main() {
  /*int a = 5;
  int b = 6;
  int c = a ^ b;
  
  printf("%d %d %d\n", a, b, c);*/
  
  struct node_t n1 = {1, NULL};
  struct node_t n2 = {2, NULL};
  struct node_t n3 = {3, NULL};
  
  n1.pointer = (long)NULL ^ (long)&n2; // == &n2
  n2.pointer = (long)&n1 ^ (long)&n3;
  n3.pointer = (long)&n2 ^ (long)NULL; // == &n2
  
  //printf("%p %p\n", &n1, n1.pointer);
  //printf("%p %p\n", &n2, n2.pointer);
  //printf("%p %p\n", &n3, n3.pointer);
  
  struct node_t* list = add_to_front(NULL, 1);
  list = add_to_front(list, 2);
  list = add_to_front(list, 3);
  list = add_to_front(list, 4);
  add_to_back(list, 0);
  add_to_back(list, -1);
  
  print_list(list);

  return 0;
}
