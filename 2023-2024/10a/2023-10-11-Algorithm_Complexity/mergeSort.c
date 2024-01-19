#include <stdio.h>
#include <stdlib.h>
#include "../utils/vector.c"

void Merge(vector_t *v, int start, int middle, int end)
{
    vector_t *v1 = init_vector();
    vector_t *v2 = init_vector();

    for (int i = start; i <= middle; i++)
    {
        push_back(v1, getAt(v, i));
    }
    for (int i = middle + 1; i <= end; i++)
    {
        push_back(v2, getAt(v, i));
    }

    int index1 = 0;
    int index2 = 0;
    int k = start;

    while (index1 < getSize(v1) && index2 < getSize(v2))
    {
        if (getAt(v1, index1) < getAt(v2, index2))
        {
            v->arr[k] = getAt(v1, index1);
            index1++;
        }
        else
        {
            v->arr[k] = getAt(v2, index2);
            index2++;
        }
        k++;
    }

    while (index1 < getSize(v1))
    {
        v->arr[k] = getAt(v1, index1);
        index1++;
        k++;
    }

    while (index2 < getSize(v2))
    {
        v->arr[k] = getAt(v2, index2);
        index2++;
        k++;
    }
}

void MergeStep(vector_t *v, int start, int end)
{
    if (start < end)
    {
        int middle = start + (end - start) / 2;

        // printf("Merging from %d to %d", start, end);
        MergeStep(v, start, middle);
        MergeStep(v, middle + 1, end);

        Merge(v, start, middle, end);
    }
}

vector_t *Merge2(vector_t *v1, vector_t *v2)
{
    vector_t *result = init_vector();
    int index1 = 0;
    int index2 = 0;

    while (index1 < getSize(v1) && index2 < getSize(v2))
    {
        if (getAt(v1, index1) < getAt(v2, index2))
        {
            push_back(result, getAt(v1, index1));
            index1++;
        }
        else
        {
            push_back(result, getAt(v2, index2));
            index2++;
        }
    }

    while (index1 < getSize(v1))
    {
        push_back(result, getAt(v1, index1));
        index1++;
    }

    while (index2 < getSize(v2))
    {
        push_back(result, getAt(v2, index2));
        index2++;
    }

    return result;
}

void MergeStep2(vector_t *v)
{
    if (getSize(v) > 1)
    {
        int middle = getSize(v) / 2;

        vector_t *v1 = init_vector();
        vector_t *v2 = init_vector();

        for (int i = 0; i < middle; i++)
        {
            push_back(v1, getAt(v, i));
        }
        for (int i = middle; i < getSize(v); i++)
        {
            push_back(v2, getAt(v, i));
        }

        MergeStep2(v1);
        MergeStep2(v2);

        printf("Merging ");
        printVector(v1);
        printVector(v2);
        printf("Result:");
        v = Merge2(v1, v2);
        printVector(v);
    }
}

void MergeSort(vector_t *v)
{
    // MergeStep(v, 0, getSize(v) - 1);
    MergeStep2(v);
}

int main()
{
    vector_t *v = init_vector();
    push_back(v, 4);
    push_back(v, 3);
    push_back(v, 4);
    push_back(v, 6);
    push_back(v, 0);
    push_back(v, 10);
    push_back(v, 8);
    push_back(v, -8);

    MergeSort(v);

    printVector(v);
}