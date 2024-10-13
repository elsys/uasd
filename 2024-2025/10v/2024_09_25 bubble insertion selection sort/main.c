#include <stdio.h>

void swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void bubbleSortBAD(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                swap(arr + j, arr + j + 1);
            }
        }
    }
}

void bubbleSort(int arr[], int size) {
    int swapped = 0;
    for(int i = 0; i < size - 1; i++) {
        swapped = 0;
        for(int j = 0; j < size - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                swap(arr + j, arr + j + 1);
                swapped = 1;
            }
        }
        if(!swapped) {
            break;
        }
    }
}

void insertionSort(int arr[], int size) {
	for (int i = 1; i < size; i++) {
		int currentElement = arr[i];
		int currentIndex = i - 1;
		while (currentIndex >= 0 && arr[currentIndex] > currentElement) {
			arr[currentIndex + 1] = arr[currentIndex];
			currentIndex--;
		}
		arr[currentIndex + 1] = currentElement;
	}
}

void selectionSort(int arr[], int n) {
    int i, j, minIdx, temp;
    for (i = 0; i < n-1; i++) {
        minIdx = i;
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        temp = arr[minIdx];
        arr[minIdx] = arr[i];
        arr[i] = temp;
    }
}

void printArr(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[50000];
    
    for (int i = 0; i < 50000; i++) {
        arr[i] = 50000 - i;
    }

    int size = sizeof(arr) / sizeof(arr[0]);
    // printArr(arr, size);
    selectionSort(arr, size);
    printArr(arr, size);

    // printf("%d\n", 1<<5);
}