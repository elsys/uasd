//#include <stdio.h>
#include <stdlib.h>

#include "list.h"

int main() {
  /*struct list_node_t n1 = {5, NULL};
  struct list_node_t n2;
  n2.value = 7;
  n2.next = NULL;

  //printf("%d\n", n1.value);

  struct list_node_t n3 = {18, NULL};

  n1.next = &n2;
  n2.next = &n3;

  print_list(&n1);*/

  struct list_node_t *list = NULL;

  list = push_back(list, 10);
  list = push_back(list, 15);
  list = push_back(list, 20);

  print_list(list);

  return 0;
}