#include <stdio.h>

void swap(int *a, int *b) {
  int c = *a;
  *a = *b;
  *b = c;
}

void quick_sort(int *arr, unsigned int size) {
  printf("Start: %p Size: %d End: %p\n", 
  arr, size, arr + size - 1);

  // recursion condition
  if(size < 2) return;
  
  // choose pivot
  int pivot_index = size-1; // int is rounded down

  printf("Pivot at %d = %d\n", 
  pivot_index, arr[pivot_index]);
  
  // rearrange around pivot
  for(int i = 0; i < pivot_index; i++) {
    printf("Compare [%d]%d ? [%d]%d\n", 
    i, arr[i], pivot_index, arr[pivot_index]);
    if(arr[i] > arr[pivot_index]) {
      // move to the right
      printf("Swap [%d]%d with [%d]%d\n", 
    i, arr[i], pivot_index, arr[pivot_index]);
    
      swap(arr + i, arr + pivot_index - 1);
      swap(arr + pivot_index-1, arr+pivot_index);
      pivot_index--;
      i--;
      for(int j = 0; j < size; j++)
        printf("[%d] %d ", j, arr[j]);
      puts(""); // printf("\n");
    }
  }

  puts("");
  // call recursively for left half and right half
  printf("Left sort\n");
  quick_sort(arr, pivot_index);
  
  printf("Right sort\n");
  quick_sort(arr + pivot_index + 1, size - pivot_index - 1);
}

int main() {
  int arr[] = {9, 3, 2, 7, 5, 1, 4, 8, 0, 6};
  
  for(int i = 0; i < 10; i++)
    printf("[%d] %d ", i, arr[i]);
  puts("");
    
  quick_sort(arr, 10);

  for(int i = 0; i < 10; i++)
    printf("[%d] %d ", i, arr[i]);
  puts("");

  return 0;
}

