#include <stdio.h>

void swap(int *a, int *b) {
  int c = *a;
  *a = *b;
  *b = c;
}

void bubble_sort(int *arr, unsigned int size) {
  puts("Bubble sort start");

  int has_swapped = 1;
  while(has_swapped) {
    puts("\nnew iteration");

    has_swapped = 0;
    for(int i = 0; i < size - 1; i++) {
      int j = i + 1;
      printf("compare arr[%d]=%d with arr[%d]=%d\n", i, arr[i], j, arr[j]);

      if(arr[i] > arr[i+1]) {
        printf("swap %d with %d\n", arr[i], arr[j]);

        swap(arr + i, arr + j);
        has_swapped = 1;
      }
    }
  }

  puts("Bubble sort end");
}

void bubble_sort_v2(int *arr, unsigned int size) {
  puts("Bubble sort v2 start");

  for(int i = 0; i < size - 1; i++) {
    for(int j = i + 1; j < size; j++) {
      printf("compare arr[%d]=%d with arr[%d]=%d\n", i, arr[i], j, arr[j]);

      if(arr[i] > arr[j]) {
        printf("swap %d with %d\n", arr[i], arr[j]);

        swap(arr + i, arr + j);
      }
    }
  }

  puts("Bubble sort v2 end");
}

void merge_sort(int *arr, unsigned int size) {
  puts("Merge sort start");
/*for(int i = 0; i < 4; i++) {
    for(int j = i + 1; j < 5; j++) {
      printf("compare %d with %d\n", arr[i], arr[j]);
      if(arr[i] > arr[j]) {
      printf("swap %d with %d\n", arr[i], arr[j]);
        swap(arr + i, arr + j);
      }
    }
  }*/
  /*for(int i = 5; i < 9; i++) {
    for(int j = i + 1; j < 10; j++) {
      printf("compare %d with %d\n", arr[i], arr[j]);
      if(arr[i] > arr[j]) {
      printf("swap %d with %d\n", arr[i], arr[j]);
        swap(arr + i, arr + j);
      }
    }
  }*/

  bubble_sort_v2(arr, size / 2);
  bubble_sort_v2(arr + (size/2), size / 2);

  /*for(int i = 0, j = 5; j < 10;) {
    printf("compare %d with %d\n", arr[i], arr[j]);
    if(arr[i] > arr[j]) {
      printf("swap %d with %d\n", arr[i], arr[j]);
      swap(arr + i, arr + j);
      i++;
    } else {
      j++;
      i = 0;
      //j = 5;
      //i=0;
    }
  }*/
  puts("Merge sort end");
}

int main() {
  int arr[] = {9, 3, 2, 7, 5, 1, 4, 8, 0, 6};

  // bubble sort
  /*int has_swapped = 1;
  while(has_swapped) {
    puts("new iteration");
    has_swapped = 0;

    for(int i = 0; i < 9; i++) {
      printf("compare %d with %d\n", arr[i], arr[i+1]);
      if(arr[i] > arr[i+1]) {
      printf("swap %d with %d\n", arr[i], arr[i+1]);
        int tmp = arr[i];
        arr[i] = arr[i+1];
        arr[i+1] = tmp;
        has_swapped = 1;
      }
    }
  }*/

  /*for(int i = 0; i < 9; i++) {
    for(int j = i + 1; j < 10; j++) {
      printf("compare %d with %d\n", arr[i], arr[j]);
      if(arr[i] > arr[j]) {
      printf("swap %d with %d\n", arr[i], arr[j]);
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
      }
    }
  }*/

  //bubble_sort(arr, 10);
  //bubble_sort_v2(arr);
  //merge_sort(arr, 10);

  for(int i = 0; i < 10; i++)
    printf("[%d] %d\n", i, arr[i]);

	return 0;
}
