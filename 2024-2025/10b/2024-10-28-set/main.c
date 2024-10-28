#include <stdlib.h>
#include <stdio.h>

struct set_t {
  int size;
  int *data;
};
typedef struct set_t set_t;

set_t* init_set() {
  set_t *set = malloc(sizeof(set_t));
  set->size = 0;
  set->data = NULL;
  return set;
}

int set_contains(set_t *set, int value) {
  for(int i = 0; i < set->size; i++)
    if(set->data[i] == value)
      return 1;
  return 0;
}

void add(set_t *set, int value) {
  // for(int i = 0; i < set->size; i++)
  //   if(set->data[i] == value)
  //     return;
  if(set_contains(set, value))
    return;

  set->size++;
  // set->size *= 2;
  set->data = realloc(set->data, set->size * sizeof(int));
  set->data[set->size - 1] = value;
}

int is_subset(set_t *big, set_t *small) {
  for(int i = 0; i < small->size; i++)
    if(!set_contains(big, small->data[i]))
      return 0;

  return 1;
}

void print_set(set_t *set) {
  for(int i = 0; i < set->size; i++)
    printf("%d ", set->data[i]);
  printf("\n");
}

int main() {
  set_t *set1 = init_set();
  add(set1, 1);
  add(set1, 2);
  add(set1, 3);

  set_t *set2 = init_set();
  add(set2, 4);
  add(set2, 2);

  printf("%d\n", set1->size);
  print_set(set1);
  printf("%d\n", set2->size);
  print_set(set2);

  printf("%d %d\n", set_contains(set1, 3), set_contains(set1, 4));
  printf("%d\n", is_subset(set1, set2));
  return 0;
}