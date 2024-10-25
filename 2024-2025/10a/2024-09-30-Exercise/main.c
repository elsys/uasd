#include <stdio.h>
#include "vector.h"


void selectionSort(vector *v) {
    // swaps = N
    // N
    for (int i = 0; i < v->size - 1; i++) {
        int minIndex = i;

        // N + (N - 1) + (N - 2) + ..... + 3 + 2 + 1
        // (N+1)*N/2 = (N^2 + N) / 2
        for (int j = i; j < v->size; j++) {
            if (v->arr[j] < v->arr[minIndex]) {
                //min = v->arr[j];
                minIndex = j;
            }
        }

        int tmp = v->arr[i];
        v->arr[i] = v->arr[minIndex];
        v->arr[minIndex] = tmp;
    }
}
                //   10          20
vector* merge(vector*v1, vector* v2) {
    vector* merged = init_vector(v1->size + v2->size);

    int i1 = 0;
    int i2 = 0;

    // N1 + N2
    while (i1 < v1->size && i2 < v2->size) {
        //printf("%d %d\n", i1, i2);
        if (v1->arr[i1] < v2->arr[i2]) {
            push(merged, v1->arr[i1]);
            i1++;
        } else {
            push(merged, v2->arr[i2]);
            i2++;
        }
    }

    while (i1 < v1->size) {
        push(merged, v1->arr[i1]);
        i1++;
    }

    while (i2 < v2->size) {
        push(merged, v2->arr[i2]);
        i2++;
    }


    return merged;
}

int vectorSumR(vector* v, int size, int acc) {
    if (size == 0) {
        return acc;
    }
    

    // tail recursion , опашкова рекурсия
    return vectorSumR(v, size - 1, acc + v->arr[size -1]);
          // 5 + sum[]
}

int vectorSum(vector *v) {
    return vectorSumR(v, v->size, 0);
}

int main() {
    vector* v = init_vector(5);
    push(v, 10);
    push(v, 4);
    push(v, 3);
    push(v, 2);
    push(v, 1);

    vector* v1 = init_vector(5);
    push(v1, -2);
    push(v1, -4);
    push(v1, -1);
    push(v1, -3);
    push(v1, -5);


    selectionSort (v);
    selectionSort(v1);
    print_vector(v);

    vector* merged = merge(v, v1);
    print_vector(merged);

    printf("sum: %d\n", vectorSum(merged));
}