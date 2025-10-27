#include <stdio.h>
#include <stdlib.h>

void merge(int* arr, int left, int mid, int right) {
    int size = right - left + 1;
    int *temp = (int*)malloc(size*sizeof(int));
    int i = left;
    int j = mid + 1;
    int k = 0;

    // n
    while (i <= mid && j <= right) {
        if (arr[i] < arr[j]) {
            temp[k] = arr[i];
            i++;
	    k++;
        } else {
            temp[k] = arr[j];
	    j++;
	    k++;
        }
    }

    while (i <= mid) {
        temp[k] = arr[i];
        i++;
	k++;
    }

    while (j <= right) {
    	temp[k] = arr[j];
	j++;
	k++;
    }

    // n
    for (int h = 0; h < size; h++) {
    	arr[left + h] = temp[h];
    }

    free(temp);
}

void MergeSort(int *arr, int left, int right) {
  if (left >= right) {
    return;
  }
  int mid = (left + right) / 2;

  MergeSort(arr, left, mid);
  MergeSort(arr, mid + 1, right);


  printf("%d %d %d\n", left, right, mid);
    for(int i = 0; i < 8;i++) {
	printf("%d ", arr[i]);
    }
    printf("\n");
  merge(arr, left, mid, right);
    for(int i = 0; i < 8;i++) {
	printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {10, 5, 7, 1, 30, 100, 25, 37};
    MergeSort(arr, 0, 7);

    for(int i = 0; i < 8;i++) {
	printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
