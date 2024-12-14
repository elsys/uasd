#include<stdio.h>
#include<stdlib.h>
#include"vector.h"

void swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void siftUp(vector* v, int i) {
    if(i <= 0) {
        return;
    }
    int parent = (i - 1) / 2;
    if (v->arr[parent] < v->arr[i]) {
        swap(&v->arr[parent], &v->arr[i]);
        siftUp(v, parent);
    }
}

void siftDown(vector* v, int i) {
    int left = 2*i + 1;
    int right = 2*i + 2;
    int maxIndex;

    if (left >= v->size) {
        return;
    }

    

    if (right < v->size && v->arr[right] > v->arr[left]) {
        maxIndex = right;
    } else {
        maxIndex = left;
    }

    if (v->arr[i] < v->arr[maxIndex]) {
        swap(&v->arr[i], &v->arr[maxIndex]);
        siftDown(v, maxIndex);
    }
}

int heap_pop(vector* v) {
    if(!v->size) {
        printf("Can't pop empty heap");
        exit(1);
    }
    int val = v->arr[0];
    v->arr[0] = pop(v);
    siftDown(v, 0);
    return val;
}

void heap_insert(vector* v, int val) {
    push(v, val);
    siftUp(v, v->size-1);
}

int main() {
    vector* v = init_vector(8);
    heap_insert(v, 1);
    heap_insert(v, 3);
    heap_insert(v, 8);
    heap_insert(v, 6);
    heap_insert(v, 3);
    heap_insert(v, 7);
    heap_insert(v, 10);
    heap_insert(v, 1);
    
    while (v->size){
        printf("%d ", heap_pop(v));
    }
}