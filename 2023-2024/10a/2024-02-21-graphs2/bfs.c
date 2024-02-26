#include <stdio.h>
#include <stdlib.h>
#include "../utils/dlist.h"

#define VERTICES_N 10

typedef struct VertexNode
{
    int val;
    struct VertexNode *next;
} VertexNode;

typedef struct Graph
{
    int numVertices;
    VertexNode **adjList;
} Graph;

VertexNode *init_node(int val)
{
    VertexNode *node = (VertexNode *)malloc(sizeof(VertexNode));
    node->val = val;
    node->next = NULL;

    return node;
}

Graph *init_graph(int numVertices)
{
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    graph->adjList = (VertexNode **)calloc(numVertices, sizeof(VertexNode *));

    return graph;
}

void addEdgeDirectional(Graph *graph, int from, int to)
{
    if (from < 0 || from >= graph->numVertices || to < 0 || to >= graph->numVertices)
    {
        printf("Invalid from or to\n");
        return;
    }

    VertexNode *newNode = init_node(to);

    newNode->next = graph->adjList[from];
    graph->adjList[from] = newNode;
}

void addEdge(Graph *graph, int from, int to)
{
    addEdgeDirectional(graph, from, to);
    addEdgeDirectional(graph, to, from);
}

void printGraph(Graph *graph)
{
    for (int i = 0; i < graph->numVertices; i++)
    {
        VertexNode *current = graph->adjList[i];
        printf("Neighbours of %d:\n", i);
        while (current != NULL)
        {
            printf("%d ", current->val);
            current = current->next;
        }
        printf("\n");
    }
}

void BFS(Graph *G)
{
    DList *queue = init_dlist();
    insertBegin(queue, 0);

    int *visited = (int *)calloc(G->numVertices, G->numVertices * sizeof(int));
    int *parents = (int *)calloc(G->numVertices, G->numVertices * sizeof(int));
    int *dist = (int *)calloc(G->numVertices, G->numVertices * sizeof(int));

    visited[0] = 1;

    while (queue->head != NULL)
    {
        int current = pop(queue);
        printf("%d ", current);
        VertexNode *currentNode = G->adjList[current];

        while (currentNode != NULL)
        {
            if (!visited[currentNode->val])
            {
                insertBegin(queue, currentNode->val);
                parents[currentNode->val] = current;
                dist[currentNode->val] = dist[current] + 1;
                visited[currentNode->val] = 1;
            }
            currentNode = currentNode->next;
        }
    }

    for (int i = 0; i < G->numVertices; i++)
    {
        printf("Parent of %d: %d at dist %d\n", i, parents[i], dist[i]);
    }
}

int main()
{
    Graph *graph = init_graph(VERTICES_N);
    addEdge(graph, 0, 2);
    addEdge(graph, 2, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 5);
    addEdge(graph, 5, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 6, 5);
    addEdge(graph, 7, 6);
    addEdge(graph, 8, 6);
    addEdge(graph, 8, 9);

    BFS(graph);

    return 0;
}