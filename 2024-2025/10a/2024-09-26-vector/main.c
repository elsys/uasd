#include "vector.h"
#include <stdio.h>

int main() {
    vector* v = init_vector(2);

    push(v, 10);
    push(v, 3);
    printf("cap: %d\n", v->capacity);

    push(v, 5);
    push(v, 6);
    push(v, -5);

    printf("cap: %d\n", v->capacity);
    print_vector(v);

    // Bubble sort 
    //  [-5, 3, 4, 5, 10]

    int iterations = 0;
    for (int j = 0; j < v->size; j++) {
        int hasSwapped = 0;
        iterations++;

        for (int i = 0; i < v->size - 1 - j; i++) {
            if (v->arr[i] > v->arr[i + 1]) {
                int tmp = v->arr[i];
                v->arr[i] = v->arr[i + 1];
                v->arr[i + 1] = tmp;

                hasSwapped = 1;
            }
        }

        if (!hasSwapped) {
            break;
        }
    }

    printf("iterations %d\n", iterations);
    print_vector(v);

    free_vector(v);
}