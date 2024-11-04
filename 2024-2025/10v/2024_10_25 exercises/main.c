#include <stdio.h>
#include <stdlib.h>

#define MIN_ITEMS_MERGE 6

void swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int binarySearchFirst(int* arr, int size, int n) {
    int left = 0;
    int right = size - 1;
    int result = -1;

    while(left < right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == n) {
            result = mid; 
            left = mid + 1;
        } else if (arr[mid] > n) {
            right = mid - 1; 
        } else {
            left = mid + 1;
        }
    }
    return result;
}

void printArr(int* arr, int size) {
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertionSort(int* arr, int size) {
    for(int i = 1; i < size; i++) {
        int val = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > val) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = val;
    }
}

void mergeSort(int* arr, int size) {
    if(size < MIN_ITEMS_MERGE) {
        insertionSort(arr, size);
        return;
    }
    int* left = arr;
    int mid = size/2;
    int* right = arr + mid;

    mergeSort(left, mid);
    mergeSort(right, size - mid);

    int* tmp = (int*) malloc(sizeof(int) * size);
    
    int lIndex = 0, rIndex = 0, i = 0;
    while(lIndex < mid && rIndex < size-mid) {
        if(left[lIndex] < right[rIndex]) {
            tmp[i++] = left[lIndex++];
        } else {
            tmp[i++] = right[rIndex++];
        }
    }

    while(lIndex < mid) {
        tmp[i++] = left[lIndex++];
    }

    while(rIndex < size - mid) {
        tmp[i++] = right[rIndex++];
    }

    for(int i = 0; i < size; i++) {
        arr[i] = tmp[i];
    }
    free(tmp);
}

int main() {
    // int arr[] = {1,2,3,4,5,5,5,5,6,7,8,9,10};
    // int size = sizeof(arr) / sizeof(arr[0]);

    // printf("%d\n", binarySearchFirst(arr, size, 5));

    int arr[] = {10, 8 , 7, 20, 6, 90, 34, 23, 18,};
    int size = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, size);
    printArr(arr, size);
}