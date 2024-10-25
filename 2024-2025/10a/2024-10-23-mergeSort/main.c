#include "../utils/vector.h"

void merge(vector*v, int l, int r, int mid) {
    vector* v1 = init_vector(2);
    vector* v2 = init_vector(2);

    // n / 2
    for (int i = l; i <= mid; i++) {
        push(v1, v->arr[i]);
    }
    // n / 2
    for (int i = mid + 1; i <= r; i++) {
        push(v2, v->arr[i]);
    }
    // N

    int i1 = 0;
    int i2 = 0;
    int k = 0;
    // N1 + N2
    while (i1 < v1->size && i2 < v2->size) {
        //printf("%d %d\n", i1, i2);
        if (v1->arr[i1] < v2->arr[i2]) {
            v->arr[l + k] = v1->arr[i1];
            i1++;
        } else {
            v->arr[l + k] = v2->arr[i2];
            i2++;
        }
        k++;
    }

    while (i1 < v1->size) {
        v->arr[l + k] = v1->arr[i1];
        i1++;
        k++;
    }

    while (i2 < v2->size) {
        v->arr[l + k] = v2->arr[i2];
        i2++;
        k++;
    }

    free_vector(v1);
    free_vector(v2);
}

void mergeSortR(vector* v, int l, int r) {
    if (l >= r) {
        return;
    }

    int mid = (l + r) / 2;

    mergeSortR(v, l, mid);
    mergeSortR(v, mid + 1, r); 

    merge(v, l, r, mid);
}

void mergeSort(vector *v) {
    mergeSortR(v, 0, v->size - 1);
}

int main() {
    vector* v = init_vector(2);
    push(v, 10);
    push(v, 50);
    push(v, 30);
    push(v, 20);
    push(v, 25);
    push(v, 35);
    push(v, -100);
    push(v, -10);
    push(v, 70);
    push(v, 30);
    push(v, 60);
    push(v, 250);
    push(v, 39);
    push(v, -100);

    mergeSort(v);
    print_vector(v);

    return 0;
}