#include <stdlib.h>

#include "vector.h"

vector_t* init_vector() {
    vector_t* vec = (vector_t*)malloc(sizeof(vector_t));

    vec->count = 0;
    vec->arr = NULL;

    return vec;
}

void push_vector(vector_t* vec, int value) {
    vec->arr = realloc(
        vec->arr,
        sizeof(int) * (vec->count + 1) 
    );
    vec->arr[vec->count++] = value;
}

int vector_get_at(vector_t* vec, unsigned int index) {
    if(vec->count <= index) {
        return -1;
    }

    return vec->arr[index];
}