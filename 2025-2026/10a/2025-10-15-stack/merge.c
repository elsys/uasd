#include <stdio.h>
#include "../utils/vector.h"

vector* merge(vector* v1, vector* v2) {
    int i = 0;
    int j = 0;
    vector* res = init_vector();

    while (i < v1->size && j < v2->size) {
        if (v1->data[i] < v2->data[j]) {
            push(res, v1->data[i]);
            i++;
        } else {
            push(res, v2->data[j]);
            j++;
        }
    }

    while (i < v1->size) {
        push(res, v1->data[i]);
        i++;
    }

    while (j < v2->size) {
        push(res, v2->data[j]);
        j++;
    }

    return res;
}

int main() {
    vector* v1 = init_vector();
    vector* v2 = init_vector();

    push(v1, 10);
    push(v1, 20);
    push(v1, 25);
    push(v1, 30);
    push(v1, 31);

    push(v2, 5);
    push(v2, 6);
    push(v2, 17);
    push(v2, 28);

    vector* res = merge(v1, v2);
    print_vector(res);

    return 0;
}