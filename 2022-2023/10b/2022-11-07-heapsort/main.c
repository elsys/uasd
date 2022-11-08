#include <stdio.h>

void print_arr(int* arr, unsigned int count) {
  for(int i = 0; i < count; i++)
    printf("%d ", arr[i]);
  puts("");
}

void swap(int* a, int* b) {
  int c = *a;
  *a = *b;
  *b = c;
}

// Reverse the logic from siftUp to arrange the items in a heap
// Example:
//  3  2  1  4 [5] <- start from the last index, 4. the value is 5
//  3 [5] 1  4  2  <- the parent item is at index 1. swap 5 and 2
// [5] 3  1  4  2  <- the new index of 5 is 1. the parent item is at index 0. swap 5 and 3
//  5  3  1 [4] 2  <- continue to the next index, 3. the value is 4. the parent item is at index 1. swap 4 and 3
//  5 [4] 1  3  2  <- the new index of 4 is 1. the parent item is at index 0. 4 is less than 5 so no need to swap
//  5  4 [1] 3  2  <- continue to index 2. the value is 1. the parent is at index 0. no need to swap
//  5 [4] 1  3  2  <- continue to index 1. the value is 4. the parent is at index 0. no need to swap
// [5] 4  1  3  2  <- continue to index 0. stop the iteration
void heapify(int* arr, unsigned int count) {
  // Orde all items starting from the back
  for(int i = count - 1; i >= 0; i--) {
    int moving_pos = i;
    // Reverse the formula x = 2i+1 to get X, the index of the parent item. Items can have 2 children, but always 1 parent
    int parent_pos = (i - 1) / 2;

    // Unlike siftUp items here are moving from the back to the start
    while(moving_pos > 0) {
      if(arr[parent_pos] < arr[moving_pos]) {
        // Move the bigger item forward and the smaller one back
        swap(
          arr + parent_pos,
          arr + moving_pos
        );
        moving_pos = parent_pos;
        parent_pos = (moving_pos - 1) / 2;
      } else break;
    }
    printf("after moving %d\n", i);
    print_arr(arr, count);
  }
}

// Move the biggest item of the heap to the back, freeze it and then ensure a correct heap
// Example:
// First call to siftUp:
//  5  4  1  3  [2] <- start from the last index, 4. the value is 2
// [2] 4  1  3  {5} <- swap with the first item and freeze index 4
//  4 [2] 1  3  {5} <- the new index of 2 is 0. compare with the child items at indices 1 and 2. the bigger child is 4 and it's bigger than 2 so swap them
//  4  3  1 [2] {5} <- the new index of 2 is 1. compare with the child indices 3 and 4. index 4 is frozen so ignore it. 3 is bigger than 2 so swap them
// Second call to siftUp:
//  4  3  1 [2] {5} <- index 4 is already frozen so we start at index 3
// [2] 3  1 {4} {5} <- swap with the first item and freeze index 3
//  3 [2] 1 {4} {5} <- the new index of 2 is 0. compare with the child indices 0 and 1. swap with 3
//  3 [2] 1 {4} {5} <- the new index of 2 is 1. compare the child indices 3 and 4. both are already frozen so stop
void siftUp(int* arr, unsigned int pos) {
  // Swap the last item (one of the smallest) with the first one (always teh biggest)
  swap(arr, arr + pos);

  // Push the new first item down the heap until the heap condition is satisfied: arr[i] > arr[2i+1] and arr[i] > arr[2i+2]
  int moving_index = 0;
  // Repeat while there are existing items to compare with
  while(2 * moving_index + 1 < pos) {
    int first_child = 2 * moving_index + 1; // 2i+1
    int second_child = 2 * moving_index + 2; // 2i+2
    // Fallabck if we only have 2 items in the heap and 2i+2 doesn't exist
    if(second_child >= pos)
      second_child = first_child;

    // Find the bigger child
    int biggest_child = first_child;
    if(arr[first_child] < arr[second_child])
      biggest_child = second_child;

    if(arr[moving_index] < arr[biggest_child]) {
      // The child is bigger so swap. The child goes up the heap and the current item goes down
      swap(
          arr + moving_index,
          arr + biggest_child
        );
        moving_index = biggest_child;
    // If there isn't anything to swap with the item is in place and we can stop
    } else break;

    /*if(arr[moving_index] < arr[first_child]) {
      if(arr[first_child] < arr[second_child]){
        swap(
          arr + moving_index,
          arr + second_child
        );
        moving_index = second_child;
      } else {
        swap(
          arr + moving_index,
          arr + first_child
        );
        moving_index = first_child;
      }
    } else if(arr[moving_index] < arr[second_child]){
      swap(arr + moving_index, arr + second_child);
      moving_index = second_child;
    } else break;*/
  }
}

void heapsort(int* arr, unsigned int count) {
  puts("Before heapify");
  print_arr(arr, count);
  heapify(arr, count);

  puts("before siftUp");
  print_arr(arr, count);
  for(int i = count - 1; i >= 0; i--) {
    siftUp(arr, i);
    printf("after siftUp %d\n", i);
    print_arr(arr, count);
  }
}

int main() {
  //int values[] = {25, 20, 24, 18, 2, 5, 3, 12};
  int values[] = {18, 3, 20, 24, 25, 5, 12, 2};
  heapsort(values, 8);
  print_arr(values, 8);
  return 0;
}
