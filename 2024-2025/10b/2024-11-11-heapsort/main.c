#include <stdio.h>

void swap(int* a, int* b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void print_arr(int* arr, unsigned int count) {
  for(int i = 0; i < count; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

void heapify(int* arr, unsigned int count) {
  // 1. Recursive call for children 2n+1 and 2n+2
  // 2. Stop when no more children
  // 3. Compare parent to children and move the largest to parent
  // 4. Return and let the recursion do the same comparison for the grandparent
}

void siftUp(int* arr, unsigned int pos) {
  swap(arr, arr + pos);
  int parent = 0;
print_arr(arr, pos + 1);
  while(parent < pos) {
    printf("%d %d\n", parent, pos);
    int lChild = parent * 2 + 1;
    int rChild = parent * 2 + 2;

    int max = parent;
    if(lChild < pos && arr[lChild] > arr[max]) max = lChild;
    if(rChild < pos && arr[rChild] > arr[max]) max = rChild;

    if(max == parent) break;

    swap(arr + parent, arr + max);
    parent = max;

    // if(lChild >= pos) lChild = -1;
    // if(arr[parent] < arr[lChild] || arr[parent] < arr[rChild]) {
    //   if(arr[lChild] > arr[rChild]) {
    //     if(lChild >= pos) {
    //       break;
    //     }
    //     swap(arr + parent, arr + lChild);
    //     parent = lChild;
    //   } else {
    //     if(rChild >= pos) {
    //       break;
    //     }
    //     swap(arr + parent, arr + rChild);
    //     parent = rChild;
    //   }
    //   print_arr(arr, pos + 1);
    // } else {
    //   break;
    // }
  }
  print_arr(arr, pos + 1);
}

int main() {
  int arr[] = {7, 3, 4, 1, 6, 5, 8};

  // heapify(arr, 7);

  int arr2[] = {8, 6, 7, 1, 3, 5, 4};
  for(int i = 6; i >= 1; i--) {
    siftUp(arr2, i);
  }

  print_arr(arr2, 7);

  return 0;
}