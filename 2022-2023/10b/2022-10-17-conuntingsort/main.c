#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void counting_sort(int* arr, unsigned int size) {
  //int min = 0;
  //int max = 10;
  
  int min = arr[0];
  int max = arr[0];
  for(int i = 1; i < size; i++) {
    if(arr[i] > max) max = arr[i];
    if(arr[i] < min) min = arr[i];
  }
  printf("min=%d, max=%d\n", min, max);
  
  int counter_count = abs(min) + abs(max) + 1;
  int* counters = calloc(counter_count, sizeof(int));
  //malloc(sizeof(int) * (max + 1));
  //memset(counters, 0, sizeof(int) * (max + 1);
  
  for(int i = 0; i < size; i++)
    counters[arr[i] - min]++;
  //-3 - (-3) =  -3 + 3 = 0
  //3 - (3) = 3 - 3 = 0
  
  int j = 0;
  for(int i = 0; i < max; i++)
    for(int k = 0; k < counters[i]; k++)
      arr[j++] = i + min;
  //0 + (-3) = -3
  //0 + (3) = 3
}

int main() {
  int arr[] = {6, 3, -2, 7, 3, 4, 4, 8, 3, 6};
  
  for(int i = 0; i < 10; i++)
    printf("[%d] %d ", i, arr[i]);
  puts("");
    
  counting_sort(arr, 10);

  for(int i = 0; i < 10; i++)
    printf("[%d] %d ", i, arr[i]);
  puts("");

  return 0;
}

