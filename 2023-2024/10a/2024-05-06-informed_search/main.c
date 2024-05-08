#include "../utils/graph.h"
#include <stdlib.h>
#include <stdbool.h>

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

void swap(PQNode *a, PQNode *b)
{
    PQNode temp = *a;
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
    swap(&pq->arr[0], &pq->arr[pq->size - 1]);
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
    PQNode *newNode = createPQNode(data, key);
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

bool best_first_search(Graph *g, int start, int end)
{
    int *visited = (int *)calloc(g->numVertices, sizeof(int));
    float *dist = (float *)calloc(g->numVertices, sizeof(float));
    PQueue *pq = init_pq();
    pqInsert(pq, start, 0);
    visited[start] = 1;
    dist[start] = 0;

    while (pq->size > 0)
    {
        PQNode *current = deleteMin(pq);
        int vertex = current->data;

        if (vertex == end)
        {
            return true;
        }

        VertexNode *v_node = g->adjList[vertex];
        while (v_node != NULL)
        {
            if (!visited[v_node->val])
            {
                dist[v_node->val] = dist[vertex] + v_node->weight;
                float g = dist[v_node->val]; // Djikstra
                float h = v_node->weight;    // Best first
                float f = h;                 // A*

                pqInsert(pq, v_node, f);
                visited[v_node->val] = 1;
            }

            v_node = v_node->next;
        }
    }

    return false;
}
