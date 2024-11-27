#include<stdio.h>
#include<stdlib.h>
#include"dLinkedList.h"

void printArr(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

//Вариант 1

int binarySearch(int arr[], int size, int value) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (value < arr[mid]) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
        //всички вътрешни за цикъла операции са с константна времева сложност O(1)
    }
    return left;
} // O(logN) защото на всяка итерация делим възможния брой елементи на 2

void insertionSort(int arr[], int size) {
    for(int i = 1; i < size; i++) { // O(N)
        int value = arr[i];
        if(value < arr[i - 1]){
            int pos = binarySearch(arr, i, value); // O(logN)
            for(int j = i; j > pos; j--) { // O(N)
                arr[j] = arr[j - 1];
            }
            arr[pos] = value;
        } // този блок има цялостна сложност O(N), тъй като O(logN) расте по-бавно като функция

    } // => цялата функция има сложност O(N*N) = O(N^2)
}

// Вариант 2

void swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void cocktailShakerSort(int arr[], int size) {
    for(int i = 0; i < size / 2; i++) { // O(N/2) = O(N) итерации
        int swapped = 0;
        for(int j = i; j < size - i - 1; j++) { // O(N)
            if(arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swapped = 1;
            }
        } // вътрешните операции са константни O(1)
        if(!swapped) {
            break;
        }
        swapped = 0;
        for(int j = size - i - 1; j > i; j--) {
            if(arr[j] < arr[j - 1]){
                swap(&arr[j], &arr[j - 1]);
                swapped = 1;
            }
        }
        if(!swapped) {
            break;
        }// втория цикъл е абсолютно аналогичен на първия
    }
} // цялостната функция тогава е със сложност O(N * (N + N)) = O(2N^2) = O(N^2)

void concat(Dlist* list1, Dlist* list2) {
    if(!list2->size) {
        return;
    }
    if(!list1->size) {
        list1->head = list2->head;
        list1->tail = list2->tail;
        list1->size = list2->size;
    } else {
        list1->tail->next = list2->head;
        list2->head->prev = list1->tail;
        list1->tail = list2->tail;
        list1->size += list2->size;
    }

    list2->head = NULL;
    list2->tail = NULL;
    list2->size = 0;    
}

int main() {
    int arr1[] = {4, 1, 2, 7, 9, 10, 2, 1, 1, 3, 10};
    int arr1sorted[] = {1, 1, 1, 2, 2, 3, 4, 7, 9, 10, 10};
    int size1 = sizeof(arr1sorted) / sizeof(0);

    printf("%d\n", binarySearch(arr1sorted, size1, 11));
    printf("%d\n", binarySearch(arr1sorted, size1, -2));
    printf("Original Array for Variant 1:\n");
    printArr(arr1, size1);
    insertionSort(arr1, size1);
    printf("Sorted Array (Insertion Sort with Binary Search):\n");
    printArr(arr1, size1);

    int arr2[] = {3, 8, 7, 6, 5, 4, 2};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    printf("\nOriginal Array for Variant 2:\n");
    printArr(arr2, size2);
    cocktailShakerSort(arr2, size2);
    printf("Sorted Array (Cocktail Shaker Sort):\n");
    printArr(arr2, size2);

}