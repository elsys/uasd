#include <stdio.h>

int bubble_sort(int arr[], int n) {
  int changes = 1;
  while(changes == 1) {
    // printf("New pass through the array\n");
    changes = 0;
    for(int i = 0; i < n-1; i++) {
      printf("Comparing %d and %d\n", arr[i], arr[i+1]);
      if(arr[i] > arr[i+1]) {
        printf("Swapping %d and %d\n", arr[i], arr[i+1]);
        int temp = arr[i];
        arr[i] = arr[i+1];
        arr[i+1] = temp;

        // printf("It has changes now\n");
        changes = 1;
      }
    }
  }
}



int insertion_sort(int arr[], int n) {
  for(; n > 1; n--) {
    for(int i = 0; i < n-1; i++) {
      printf("Comparing %d and %d\n", arr[i], arr[i+1]);
      if(arr[i] > arr[i+1]) {
        printf("Swapping %d and %d\n", arr[i], arr[i+1]);
        int temp = arr[i];
        arr[i] = arr[i+1];
        arr[i+1] = temp;
      }
    }
  }
}



int main() {
  int arr[] = {5, 3, 8, 4, 2};
  int n = sizeof(arr)/sizeof(arr[0]);

  for(int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
  insertion_sort(arr, n);

  for(int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  return 0;
}