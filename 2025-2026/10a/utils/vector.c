#include "vector.h"
#include <stdio.h>
#include <stdlib.h>

vector* init_vector() {
    vector* v = (vector*)malloc(sizeof(vector));
    if (v == NULL) {
        exit(1);
    }

    v->capacity = 2;
    v->data = (int*)malloc(sizeof(int)*v->capacity);
    v->size = 0;

    return v;
}

void push(vector* v, int val) {
    if (v->size == v->capacity) {
        v->capacity *= 2;
        v->data = (int*)realloc(v->data, sizeof(int)*v->capacity);
    }
    v->data[v->size] = val;
    v->size++;
}

int pop(vector* v) {
    v->size--;

    if (v->size < v->capacity / 2) {
        v->capacity /= 2;
        v->data = (int*)realloc(v->data, sizeof(int)*v->capacity);
    }

    return v->data[v->size];
}

void pushFront(vector* v, int val) {
    if (v->size == v->capacity) {
        v->capacity *= 2;
        v->data = (int*)realloc(v->data, sizeof(int)*v->capacity);
    }

    for (int i = v->size; i > 0; i--) {
        v->data[i] = v->data[i - 1];
    }

    v->data[0] = val;
    v->size++;
}

int popFront(vector* v) {
    int res = v->data[0];

    for (int i = 0; i < v->size - 1; i++) {
        v->data[i] = v->data[i + 1];
    }
    v->size--;

    return res;
}


void print_vector(vector* v) {
    for (int i = 0; i < v->size; i++) {
        printf("%d ", v->data[i]);
    }
    printf("\n");
}

void free_vector(vector* v) {
    free(v->data);
    free(v);
}