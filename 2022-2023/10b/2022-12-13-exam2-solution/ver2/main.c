#include <stdlib.h>

#include "priority_queue.h"

int get_random(int min, int max) {
  return rand() % (max - min) + min;
}

void test_queue() {
  struct priority_queue_t* q = init_queue();

  for(int i = 0; i < 100000; i++)
    push_queue(
      q,
      get_random(0, 10000),
      get_random(1, 100)
    );

  for(int i = 0; i < 50000; i++)
   pop_queue(q);

  print_queue(q);
}

int main() {
  test_queue();
  return 0;
}
