
#ifndef PQUEUE_H
#define PQUEUE_H

// should be dynamic but to make it a bit easier for us
#define MAX_PQ_NODES 1000

typedef struct PQNode
{
    float key;
    void *data;
} PQNode;

typedef struct PQueue
{
    PQNode *arr[MAX_PQ_NODES];
    int size;
} PQueue;

PQueue *init_pq();
PQNode *createPQNode(void *data, float key);
void swap(PQNode **a, PQNode **b);
void siftDown(PQueue *pq, int i);
PQNode *deleteMin(PQueue *pq);
PQNode *init_pq_node(void *data, float key);

// In order to use this priority queue with arbitrary structues I've defiend it with void* data,
// However mostly we will be using it with integers, so the helper functions pqInsertInt
// and pq DeleteMinInt can be used. For example when working with graphs and we know that
// pq elements will be vertex indeces.
void pqInsert(PQueue *pq, void *data, float key);
void pqInsertInt(PQueue *pq, int data, float key);
int pqDeleteMinInt(PQueue *pq);

#endif