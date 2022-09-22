#include <stdlib.h>
#include <stdio.h>

#include "../2022-09-21-revision-2/functions.h"

int main() {
  printf("%d\n", foo());
  bar();

  char *a = (char*)malloc(4 * sizeof(char));
  int *b = (int*)a;

  for(int i = 0; i < 4; i++) {
    a[i] = 'a' + i;
    printf("%d -> %c\n", i, a[i]);
  }

  printf("%d\n", *b);

  a = realloc(a, 10 * sizeof(char));

  a = calloc(5, sizeof(char));

  free(a);
  a = NULL;

  return 0;
}