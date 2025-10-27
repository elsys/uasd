#include <stdio.h>
#include <stdbool.h>
#include "../utils/vector.h"

bool binary_search(vector* v, int val) {
    int left = 0;
    int right = v->size - 1;

    while (left <= right) {
        int mid = (left + right) / 2;
        printf("mid - %d, val - %d\n", mid, v->data[mid]);
        if (v->data[mid] == val) {
            return true;
        } else if (v->data[mid] > val) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return false;    
}


int main() {
    vector* v = init_vector();
    push(v, 10);
    push(v, 20);
    push(v, 30);
    push(v, 40);
    push(v, 50);
    push(v, 60);
    push(v, 70);
    push(v, 80);
    push(v, 90);

    print_vector(v);
    if (binary_search(v, 15)) {
        printf("found\n");
    } else {
        printf("not found\n");
    }

    return 1;
}