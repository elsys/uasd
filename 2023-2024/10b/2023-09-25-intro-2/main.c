#include <stdio.h>

#include "vector.h"

int main() {
    vector_t* vec = init_vector();

    for(int i = 0; i < 10; i++) {
        push_vector(vec, i);
    }

    for(int i = 0; i < vec->count; i++) {
        printf("vec[%d] = %d\n", i, vec->arr[i]);
    }

    return 0;
}