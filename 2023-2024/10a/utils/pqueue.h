
#ifndef PQUEUE_H
#define PQUEUE_H

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
PQNode *createPQNode(void *data, int key);
void swap(PQNode **a, PQNode **b);
void siftDown(PQueue *pq, int i);
PQNode *deleteMin(PQueue *pq);
PQNode *init_pq_node(void *data, float key);
void pqInsert(PQueue *pq, void *data, float key);

#endif