#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void swap(int* left, int* right) {
    int tmp = *left;
    *left = *right;
    *right = tmp;
}

void insertion_sort(int* arr, int count) {
    for(int i = 1; i < count; i++) {
        int j = i - 1;
        while(arr[i] < arr[j]) {j--;}

        int tmp = arr[i];
        int copyStart = j+1;
        int copyEnd = i-1;

        memmove(
            arr + copyStart, 
            arr + copyStart + 1,
            (copyEnd - copyStart) * sizeof(int)
        );
        arr[j + 1] = tmp;
    }
}

int* create_array(int count) {
    int* arr = malloc(sizeof(int) * count);

    for(int i = 0; i < count; i++)
        arr[i] = random();

    return arr;
}

int main() {
    srand(time(NULL));

    int* list = create_array(5);

    insertion_sort(list, 5);

    for(int i = 0; i < 5; i++) {
        printf("arr[%d] = %d\n", i, list[i]);
    }
}