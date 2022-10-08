#include <stdio.h>

void swap(int *a, int *b) {
  int c = *a;
  *a = *b;
  *b = c;
}

void quick_sort(int *arr, unsigned int size) {
  // recursion condition
  // choose pivot
  int pivot_index = size/2; // int is rounded down

  // rearrange around pivot
  for(int i = 0; i < pivot_index; i++) {
    if(arr[i] > arr[pivot_index]) {
      // move to the right
      swap(arr + i, arr + pivot_index - 1);
      swap(arr + pivot_index-1, arr+pivot_index);
      pivot_index--;
      i--;
    }
  }

  // call recursively for left half and right half
}

int main() {
  int arr[] = {9, 3, 2, 7, 5, 1, 4, 8, 0, 6};

  //quick_sort(arr, 10);

  for(int i = 0; i < 10; i++)
    printf("[%d] %d\n", i, arr[i]);

	return 0;
}
