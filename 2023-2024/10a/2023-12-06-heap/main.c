#include <stdio.h>
#include "../utils/vector.h"

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void siftDown(vector_t *v, int i, int size)
{
    int swapped = 1;

    while (swapped)
    {
        swapped = 0;
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < size && v->arr[left] > v->arr[largest])
        {
            largest = left;
        }
        if (right < size && v->arr[right] > v->arr[largest])
        {
            largest = right;
        }

        if (i != largest)
        {
            swap(&v->arr[i], &v->arr[largest]);
            i = largest;
            swapped = 1;
        }
    }
}

void heapify(vector_t *v)
{
    for (int i = v->size / 2; i >= 0; i--)
    {
        siftDown(v, i, v->size);
    }
}

void heapsort(vector_t *v)
{
    heapify(v);

    for (int i = 0; i < v->size; i++)
    {
        swap(&v->arr[0], &v->arr[v->size - 1 - i]);
        siftDown(v, 0, v->size - i - 1);
    }
}

int main()
{
    vector_t *v = init_vector();
    push_back(v, 20);
    push_back(v, 50);
    push_back(v, 15);
    push_back(v, 8);
    push_back(v, 26);
    push_back(v, 10);
    push_back(v, 16);
    push_back(v, 30);

    printVector(v);
    heapsort(v);
    printVector(v);

    return 0;
}