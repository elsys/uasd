#include <stdio.h>
#include "../utils/vector.h"

int main()
{
    vector_t *v = init_vector();
    push_back(v, 1);
    push_back(v, 1);
    push_back(v, -15);
    push_back(v, 2);
    push_back(v, -7);
    push_back(v, 165);
    push_back(v, 5);
    push_back(v, 10);

    InsertionSort(v);
    printVector(v);

    return 0;
}