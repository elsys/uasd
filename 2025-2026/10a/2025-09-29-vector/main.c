#include <stdio.h>
#include <stdbool.h>
#include "vector.h"

int main() {
    vector* v = init_vector();

    push(v, 1);
    push(v, 2);
    push(v, 3);
    push(v, 4);
    push(v, 5);
    
    print_vector(v);
    printf("%d \n", pop(v));
    print_vector(v);
    pop(v);
    pop(v);
    pop(v);
    
    print_vector(v);
    push(v, 10);
    push(v, 20);
    print_vector(v);

    pushFront(v, 5);
    print_vector(v);
    printf("at front %d\n", popFront(v));
    print_vector(v);

    free_vector(v);

    //BubbleSort
    vector* v2 = init_vector();
    push(v2, 10);
    push(v2, 15);
    push(v2, 6);
    push(v2, 2);
    push(v2, 20);
    push(v2, 25);
    push(v2, 30);

    for (int j = 0; j < v2->size - 1; j++) {
        bool hasSwapped = false;
        for (int i = 0; i < v2->size - 1 - j; i++) {
            if (v2->data[i] > v2->data[i + 1]) {
                int c = v2->data[i];
                v2->data[i] = v2->data[i + 1];
                v2->data[i+1] = c;
                hasSwapped = true;
            }
        }

        if (!hasSwapped) {
            break;
        }
    }

    print_vector(v2);


    return 0;
}