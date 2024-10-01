
#include "pqueue.h"
#include <stdlib.h>

PQueue *init_pq()
{
    PQueue *pq = (PQueue *)malloc(sizeof(PQueue));
    pq->size = 0;
    return pq;
}

PQNode *createPQNode(void *data, int key)
{
    PQNode *newNode = (PQNode *)malloc(sizeof(PQNode));
    newNode->data = data;
    newNode->key = key;
    return newNode;
}

void swap(PQNode **a, PQNode **b)
{
    PQNode *temp = *a;
    *a = *b;
    *b = temp;
}

void siftDown(PQueue *pq, int i)
{
    int swapped = 1;

    while (swapped)
    {
        swapped = 0;
        int smallest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < pq->size && pq->arr[left]->key < pq->arr[smallest]->key)
        {
            smallest = left;
        }
        if (right < pq->size && pq->arr[right]->key < pq->arr[smallest]->key)
        {
            smallest = right;
        }

        if (i != smallest)
        {
            swap(&pq->arr[i], &pq->arr[smallest]);
            i = smallest;
            swapped = 1;
        }
    }
}

PQNode *deleteMin(PQueue *pq)
{
    PQNode *res = pq->arr[0];
    pq->arr[0] = pq->arr[pq->size - 1];
    pq->size--;
    siftDown(pq, 0);

    return res;
}

PQNode *init_pq_node(void *data, float key)
{
    PQNode *pq = (PQNode *)malloc(sizeof(PQNode));
    pq->data = data;
    pq->key = key;

    return pq;
}

void pqInsert(PQueue *pq, void *data, float key)
{
    PQNode *newNode = init_pq_node(data, key);
    pq->arr[pq->size] = newNode;
    int current = pq->size++;
    int parent = (current - 1) / 2;

    while (current != 0 && pq->arr[current]->key < pq->arr[parent]->key)
    {
        swap(&pq->arr[current], &pq->arr[parent]);
        current = parent;
        parent = (current - 1) / 2;
    }
}