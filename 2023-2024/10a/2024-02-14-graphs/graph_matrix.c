#include <stdio.h>
#include <stdlib.h>

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

// Make graph with adj matrix
// or
// BFS or DFS

int main()
{
    Graph *graph = init_graph(4);
    addEdge(graph, 1, 2);
    addEdgeDirectional(graph, 2, 4);
    addEdgeDirectional(graph, 3, 4);
    addEdgeDirectional(graph, 2, 3);
    addEdgeDirectional(graph, 1, 3);
    addEdgeDirectional(graph, 1, 1);

    printGraph(graph);

    return 0;
}