#include <stdio.h>
#include "../utils/vector.h"

int main() {
    vector* v = init_vector();

    push(v, 5);
    push(v, 50);
    push(v, 23);
    push(v, 18);
    push(v, 30);
    push(v, 27);
    push(v, 100);
    push(v, 0);

    //insertion sort
    /*
        Number of operations
        1 + (n-1)*(5) + n*(n+1)
        = 1 + 5n - 5 + n^2 + n 
        = n^2 + 6n - 4
    */
    for (int i = 1; i < v->size; i++) {
        int temp = v->data[i];
        int j = i - 1;
        for (; j >= 0; j--) {
            if (v->data[j] < temp) {
                break;
            }
            v->data[j+1] = v->data[j];
        }

        v->data[j+1] = temp;
    }

    print_vector(v);


    return 0;
}