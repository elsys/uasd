#include <stdio.h>

void swap(int* a, int* b) {
    *a = *a ^ *b;
    *b = *b ^ *a;
    *a = *a ^ *b;
}

void printArr(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        printf("%d\n", arr[i]);
    }
}

void merge(int arr1[], int size1, int arr2[], int size2, int merged[]) {
    int i = 0, j = 0, k = 0;

    while(i < size1 && j < size2) {
        if(arr1[i] < arr2[j]) {
            merged[k++] = arr1[i++];
        }
        else {
            merged[k++] = arr2[j++];
        }
    }

    while(i < size1) {
        merged[k++] = arr1[i++];
    }

    while(j < size2) {
        merged[k++] = arr2[j++];
    }

}

void mergeSort(int arr[], int size) {
    int mid = size / 2;
    int* left = arr;
    int* right = arr + mid;

    if(size <= 1) {
        return;
    }
    
    mergeSort(left, mid);
    mergeSort(right, size - mid);

    int lIndex = 0, rIndex = 0, i = 0;

    int* tmp = (int*) malloc(sizeof(int)*size);

    while(lIndex < mid && rIndex < size - mid) {
        if(left[lIndex] < right[rIndex]) {
            tmp[i++] = left[lIndex++];
        }
        else {
            tmp[i++] = right[rIndex++];
        }
    }

    while(lIndex < mid) {
        tmp[i++] = left[lIndex++];
    }

    while(rIndex < size - mid) {
        tmp[i++] = right[rIndex++];
    }

    for(i = 0; i < size; i++) {
        arr[i] = tmp[i];
    }

    free(tmp);
}

int main() {
    // int arr[50000];
    // int size = sizeof(arr) / sizeof(arr[0]);
    // for(int i = 0; i < size; i++) {
    //     arr[i] = size - i;
    // }

    // bubbleSort(arr, size);


    int arr1[] = {3};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int arr2[] = {1};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    int merged[10];

    merge(arr1, size1, arr2, size2, merged);

    printArr(merged, size1 + size2);

    // printArr(arr, size);
}
