#include <stdio.h>

int foo();

int main() {
  printf("Hello\n");

  int a = 5;
  int b;

  printf("%d %d\n", a, b);

  // int float double char
  // unsigned int
  // long int / long
  // short int / short
  // unsigned long

  int arr[3];
  int arr2[5] = {1, 2, 3};

  int *p = &a;
  printf(
    "[%p] %p => [%p] %d\n *p=%d\n",
    &p, p, &a, a,
    *p
  );

  printf("%d %d\n", arr[0], *(arr + 0));

  int *arr3 = arr;

  printf("%d %d\n", arr3[0], *(arr3 + 0));

  for(int i = 0; i < 3; i++) {
    printf("%d\n", arr[i]);
    // printf("%d\n", *(arr + i));
  }

  int c = 5;
  int d = c == 5 ? 1 : 0;
  // c == 5 ? print_hello() : print_goodbye();

  foo();

  return 0;
}

int foo() {
  printf("foo");
  return 1;
}

void bar(int a, int *b) {
  a = 10;
  *b = 10;
}

int a = 5;
bar(a, &a)