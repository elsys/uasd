#include <stdio.h>
#include <stdlib.h>
#include "../utils/dlist.h"

#define VERTICES_N 10

typedef struct Graph
{
    int numVertices;
    int **adjMatrix;
} Graph;

Graph *init_graph(int numVertices)
{
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    graph->adjMatrix = (int **)malloc(numVertices * sizeof(int *));

    for (int i = 0; i < numVertices; i++)
    {
        graph->adjMatrix[i] = (int *)calloc(numVertices, sizeof(int));
    }

    return graph;
}

void addEdgeDirectional(Graph *graph, int from, int to)
{
    if (from < 0 || from >= graph->numVertices || to < 0 || to >= graph->numVertices)
    {
        printf("Invalid from or to\n");
        return;
    }

    graph->adjMatrix[from][to] = 1;
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
        for (int j = 0; j < graph->numVertices; j++)
        {
            printf("%d ", graph->adjMatrix[i][j]);
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
        for (int i = 0; i < G->numVertices; i++)
        {
            if (G->adjMatrix[current][i] && !visited[i])
            {
                insertBegin(queue, i);
                parents[i] = current;
                dist[i] = dist[current] + 1;
                visited[i] = 1;
            }
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