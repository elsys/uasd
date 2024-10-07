#include <stdio.h>

void quick_sort(int numbers[], unsigned int count) {
  int anchor = 0;

  for(int i = anchor + 1; i < count; i++) {
    if(numbers[i] < numbers[anchor]) {
      // a b c A x d z
      int tmp = numbers[i]; // tmp == d
      for(int j = i - 1; j >= anchor; j--)
        numbers[j + 1] = numbers[j];
      // a b c A A x z
      numbers[anchor] = tmp; // A => d
      // a b c d A x z
      anchor++;
    }
  }
}

int main() {
    int numbers[8] = {6, 8, 3, 7, 2, 4, 5, 1};

    for(int i = 0; i < 8; i++)
        printf("numbers[%d] = %d\n", i, numbers[i]);

    quick_sort(numbers, 8);

    puts("");
    for(int i =0; i < 8; i++)
        printf("numbers[%d] = %d\n", i, numbers[i]);

  return 0;
}