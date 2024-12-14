#include<stdio.h>
#include<stdlib.h>
#include"vector.h"

vector* init_vector(int initialCapacity) {
    vector* v = (vector*)malloc(sizeof(vector));
    v->arr = (int*)malloc(sizeof(int) * initialCapacity);
    v->size = 0;
    v->capacity = initialCapacity;
    return v;
}

void push(vector* v, int val) {
    if(v->size >= v->capacity) {
        v->capacity *= 2;
        int* tmp = (int*)realloc(v->arr, sizeof(int) * v->capacity);
        if(tmp == NULL) {
            exit(0);
        }
        v->arr = tmp;
    }
    v->arr[v->size] = val;
    v->size++;
}

int pop(vector* v) {
    if(v->size == 0) {
        printf("Can't pop from empty vector\n");
        exit(1);
    }
    int tmp = v->arr[v->size - 1];
    v->size--;
    return tmp;
}

int getAt(vector *v, int i) {
    if (i >= v->size || i < 0) {
        printf("Invalid index for getAt\n");
        exit(1);
    }
    return v->arr[i];
}

void clear_vector(vector* v) {
    v->size = 0;
    free(v->arr);
    v->capacity = 2;
    v->arr = (int*) malloc(v->capacity*sizeof(int));
}

void free_vector(vector* v) {
    free(v->arr);
    free(v);
}

void print_vector(vector* v) {
    for(int i = 0; i < v->size; i++) {
        printf("%d ", v->arr[i]);
    }
    printf("\n");
}