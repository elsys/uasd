#include <stdio.h>

void swap(int* left, int* right) {
    int tmp = *left;
    *left = *right;
    *right = tmp;
}

void print_arr(int* arr, int count) {
    for(int i = 0; i < count; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }
}

void siftup(int* arr, int pos) {
    
        printf("Before swap(%d): \n", pos);
        print_arr(arr, 7);
    swap(arr, arr + pos);
    
        printf("After swap(%d): \n", pos);
        print_arr(arr, 7);

    int curr = 0;
    while(1) {
        int left = curr * 2 + 1;
        int right = curr * 2 + 2;
        printf("left=%d right=%d\n", left, right);

        if(left >= pos || right >= pos) return;

        if(arr[curr] < arr[left] && arr[left] > arr[right]) {
            swap(arr + curr, arr + left);
            curr = left;
        } else if(arr[curr] < arr[right]) {
            swap(arr + curr, arr + right);
            curr = right;
        } else {
            return;
        }
    }
}

void heapsort(int* arr, int count) {
    for(int i = count - 1; i > 0; i--) {  
        printf("Before siftup(%d): \n", i);
        print_arr(arr, 7);

        siftup(arr, i);
        
        printf("After siftup(%d): \n", i);
        print_arr(arr, 7);
    }
}

int main() {
    int arr[] = {30, 16, 24, 8, 12, 18, 23};

    puts("Before sort: ");
    print_arr(arr, 7);

    heapsort(arr, 7);

    puts("After sort: ");
    print_arr(arr, 7);

    return 0;
}