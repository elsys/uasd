#include <stdio.h>

void mergesort(int arr[], int size) {
  printf("mergesort with arr=%p and size=%d\n", arr, size);
  if(size < 2) {
    printf("base case reached with size=%d\n", size);
    return;
  }

  int mid = size / 2;
  printf("mid=%d\n", mid);
  mergesort(arr, mid);
  mergesort(arr + mid, size - mid);
  // arr[mid] === *(arr + mid)
  int temp[size];
  int left = 0, right = mid, k = 0;

  while(left < mid && right < size) {
    printf("comparing arr[%d]=%d and arr[%d]=%d\n", left, arr[left], right, arr[right]);
    if(arr[left] < arr[right]) {
      temp[k++] = arr[left++];
    } else {
      temp[k++] = arr[right++];
    }
  }
  printf("left=%d, right=%d, k=%d\n", left, right, k);
  while(left < mid) {
    printf("copying arr[%d]=%d to temp[%d]\n", left, arr[left], k);
    temp[k++] = arr[left++];
  }
  while(right < size) {
    printf("copying arr[%d]=%d to temp[%d]\n", right, arr[right], k);
    temp[k++] = arr[right++];
  }

  for(int i = 0; i < k; i++) {
    arr[i] = temp[i];
  }

  printf("merged array with size=%d\n", size);
}

int main() {
  int arr[] = {5, 3, 8, 6, 2, 7, 4, 1};
  int size = sizeof(arr) / sizeof(arr[0]);
  mergesort(arr, size);
  for(int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
  return 0;
}