#include <stdio.h>
#include <stdlib.h>
#include "../utils/vector.h"

void swap(int* a, int *b) {
    int c = *b;
    *b = *a;
    *a = c;
}

int siftUp(vector*v, int i) {
    int parent = 0;
    if (i % 2 == 1) {
        parent = i / 2;
    } else if (i > 0) {
        parent = i / 2 - 1;
    }

    if (v->arr[parent] < v->arr[i]) {
        swap(&v->arr[parent], &v->arr[i]);
        siftUp(v, parent);
    }
}

int siftDown(vector* v, int i) {
    int left = 2*i + 1;
    int right = 2*i + 2;
    int maxIndex;    

    if (left < v->size) {
        maxIndex = left;
    }
    if (right < v->size && v->arr[right] > v->arr[maxIndex]) {
        maxIndex = right;
    }

    if (v->arr[i] < v->arr[maxIndex]) {
        swap(&v->arr[i], &v->arr[maxIndex]);
        siftDown(v, maxIndex);
    }
}

int extractMax(vector* v) {
    int val = v->arr[0];

    v->arr[0] = v->arr[v->size-1];
    pop(v);
    siftDown(v, 0);

    return val;
}

void insert(vector* v, int val) {
    push(v, val);
    siftUp(v, v->size - 1);
}
void heapify(vector *v) {
    for (int i = 0; i < v->size; i++) {
        siftUp(v, i);
    }
}

int main() {

   return 0; 
}