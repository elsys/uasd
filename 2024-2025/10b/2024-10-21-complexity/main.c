#include <stdio.h>

// void swap(void* a, void* b) {
//     int tmp = *a;
//     *a = *b;
//     *b = tmp;
// }
void bubble_sort(int numbers[], unsigned int count) {
    int hasSwaps = 1; // 1
    printf("asdasd"); // 1
    while(hasSwaps) { // N
        hasSwaps = 0; // 1
        printf("new iteration\n"); // 1
        for(int i = 0; i < count - 1; i++) { // N - 1
            printf("compare %d and %d\n", numbers[i], numbers[i+1]); // 1
            if(numbers[i] > numbers[i+1]) {
                printf("swap %d and %d\n", numbers[i], numbers[i+1]); // 1

                int tmp = numbers[i];
                numbers[i] = numbers[i + 1];
                numbers[i + 1] = tmp;

                // swap(numbers + i, numbers + i + 1);
                // swap(&numbers[i], &numbers[i + 1]);

                hasSwaps = 1;
            }
        }
    }

    // O(2 + N * (N - 1)) => O(N^2 - N + 2) => O(N^2)
}

void selection_sort(int numbers[], unsigned int count) {
    // O(N * (N-1)) N^2 - N N^2
    while(count > 1) { // N
        printf("new iteration\n");
        for(int i = 0; i < count - 1; i++) { // N - 1
            printf("compare %d and %d\n", numbers[i], numbers[i+1]);
            if(numbers[i] > numbers[i+1]) {
                printf("swap %d and %d\n", numbers[i], numbers[i+1]);

                int tmp = numbers[i];
                numbers[i] = numbers[i + 1];
                numbers[i + 1] = tmp;

                // swap(numbers + i, numbers + i + 1);
                // swap(&numbers[i], &numbers[i + 1]);
            }
        }
        count--;
    }
}


int main() {
    int numbers[8] = {8, 3, 7, 2, 4, 6, 5, 1};

    for(int i = 0; i < 8; i++)
        printf("numbers[%d] = %d\n", i, numbers[i]);

    // bubble_sort(numbers, 8);
    selection_sort(numbers, 8);

    for(int i =0; i < 8; i++)
        printf("numbers[%d] = %d\n", i, numbers[i]);

    return 0;
}