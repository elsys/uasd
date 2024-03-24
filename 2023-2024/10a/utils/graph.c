
#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

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
