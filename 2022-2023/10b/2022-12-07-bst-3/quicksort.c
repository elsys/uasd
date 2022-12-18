void swap(int *a, int *b) {
  int c = *a;
  *a = *b;
  *b = c;
}

void quick_sort(int *arr, unsigned int size) {
  if(size < 2) return;
  
  int pivot_index = size-1;
  
  for(int i = 0; i < pivot_index; i++) {
    if(arr[i] > arr[pivot_index]) {
      swap(arr + i, arr + pivot_index - 1);
      swap(arr + pivot_index-1, arr+pivot_index);
      pivot_index--;
      i--;
    }
  }
  quick_sort(arr, pivot_index);
 
  quick_sort(arr + pivot_index + 1, size - pivot_index - 1);
}
