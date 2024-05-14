#include "../utils/graph.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES_SIZE 100

typedef struct PQNode
{
    int vertex;
    int priority;
} PQNode;

typedef struct PriorityQueue
{
    PQNode *nodes[MAX_NODES_SIZE];
    int size;
} PriorityQueue;

PQNode *createPQNode(int v, int p)
{
    PQNode *newNode = (PQNode *)malloc(sizeof(PQNode));
    newNode->vertex = v;
    newNode->priority = p;
    return newNode;
}

// Function to create a new priority queue
PriorityQueue *createPriorityQueue()
{
    PriorityQueue *pq = (PriorityQueue *)malloc(sizeof(PriorityQueue));
    pq->size = 0;
    return pq;
}

// Function to swap two priority queue nodes
void swap(PQNode **a, PQNode **b)
{
    PQNode *temp = *a;
    *a = *b;
    *b = temp;
}

void siftDown(PriorityQueue *pq, int i)
{
    int swapped = 1;

    while (swapped)
    {
        swapped = 0;
        int smallest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < pq->size && pq->nodes[left] < pq->nodes[smallest])
        {
            smallest = left;
        }
        if (right < pq->size && pq->nodes[right] < pq->nodes[smallest])
        {
            smallest = right;
        }

        if (i != smallest)
        {
            swap(&pq->nodes[i], &pq->nodes[smallest]);
            i = smallest;
            swapped = 1;
        }
    }
}

void insert(PriorityQueue *pq, int v, int p)
{
    PQNode *newNode = createPQNode(v, p);
    pq->nodes[pq->size] = newNode;
    int current = pq->size++;
    int parent = (current - 1) / 2;

    while (current != 0 && pq->nodes[current]->priority < pq->nodes[parent]->priority)
    {
        swap(&pq->nodes[current], &pq->nodes[parent]);
        current = parent;
        parent = (current - 1) / 2;
    }
}

PQNode *removeMin(PriorityQueue *pq)
{
    PQNode *minNode = pq->nodes[0];
    pq->nodes[0] = pq->nodes[pq->size - 1];
    pq->size--;
    siftDown(pq, 0);
    return minNode;
}

void best_first_search(Graph *graph, int start, int end)
{
    PriorityQueue *open = createPriorityQueue();
    int *visited = (int *)malloc(graph->numVertices * sizeof(int));
    for (int i = 0; i < graph->numVertices; i++)
    {
        visited[i] = 0;
    }

    insert(open, start, 0);

    while (open->size != 0)
    {
        PQNode *currentNode = removeMin(open);
        int current = currentNode->vertex;
        visited[current] = 1;

        if (current == end)
        {
            printf("Found path\n");
            return;
        }

        VertexNode *temp = graph->adjList[current];
        while (temp != NULL)
        {
            if (!visited[temp->val])
            {
                insert(open, temp->val, temp->weight);
            }
            temp = temp->next;
        }
    }
}

int main()
{
    Graph *graph = init_graph(6);

    addEdge(graph, 0, 1, 5);
    // addEdge(graph, 0, 2, 3);
    addEdge(graph, 1, 3, 6);
    addEdge(graph, 1, 4, 2);
    addEdge(graph, 2, 5, 7);
    // addEdge(graph, 3, 5, 1);

    printGraph(graph);
    best_first_search(graph, 0, 5);

    return 0;
}
