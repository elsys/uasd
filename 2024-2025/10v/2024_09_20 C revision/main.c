#include <stdio.h>

void swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void swapNoTMP(int* a, int* b) {
    // без този if ако подадем 2 указателя към една и съща памет ще се занулят
    if(a != b) {
        *a = *a ^ *b;
        *b = *a ^ *b;
        *a = *a ^ *b;
    }
}

int sumOneToN(int n) {
    int res = 0;
    for(int i = 1; i <= n; i++) {
        res += i;
    }
    return res;
}

int sumOneToNRec(int n) {
    if(n < 1){
        return 0;
    }
    return n + sumOneToNRec(n-1);
}

int linearSearch(int arr[], int size, int item) {
    for(int i = 0; i < size; i++) {
        if( arr[i] == item) {
            return i;
        }
    }
    return -1;
}

int binarySearch(int arr[], int size, int item) {
    int left = 0;
    int right = size-1;
    while(left<=right) {
        int middle = left + (right - left)/2;
        if(item == arr[middle]) {
            return middle;
        }
        if(item < arr[middle]){
            right = middle-1;
        }
        else {
            left = middle+1;
        }
    }
    return -1;
}

typedef struct Point {
    double x;
    double y;
} Point;

double dist(Point p1, Point p2) {
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    return sqrt(dx * dx + dy * dy);
}

int main()
    
{
}