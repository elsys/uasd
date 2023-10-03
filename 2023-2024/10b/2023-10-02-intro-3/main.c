#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int* left, int* right) {
    int tmp = *left;
    *left = *right;
    *right = tmp;
}

void bubble_sort_1(int* arr, int count) {
    while(1) {
        int has_swapped = 0;

        for(int i = 0; i < count - 1; i++) {
            if(arr[i] > arr[i+1]) {
                has_swapped = 1;
                // arr[1] === *(arr + i)
                swap(arr + i, arr + i + 1);
                // int tmp = arr[i];
                // arr[i] = arr[i+1];
                // arr[i+1] = tmp;
            }
        }

        if(!has_swapped)
            break;
    }
}

void bubble_sort_2(int* arr, int count) {
    for(int i = 0; i < count - 1; i++) {
        for(int j = i + 1; j < count; j++) {
            if(arr[i] > arr[j]) {
                swap(arr + i, arr + j);
            }
        }
    }
}

int* create_array(int count) {
    int* arr = malloc(sizeof(int) * count);

    for(int i = 0; i < count; i++)
        arr[i] = random();

    return arr;
}

void bubble_sort_list_2(list_t* list, int count) {
    
    // for(int i = 0; i < count - 1; i++) {
    //     for(int j = i + 1; j < count; j++) {
    //         if(arr[i] > arr[j]) {
    //             swap(arr + i, arr + j);
    //         }
    //     }
    // }
}

int main() {
    srand(time(NULL));

    int* arr = create_array(50000);

    bubble_sort_2(arr, 50000);

    for(int i = 0; i < 50000; i++)
        printf("arr[%d] = %d\n", i, arr[i]);

    return 0;
}