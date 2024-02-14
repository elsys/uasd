#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int val;
    struct Node *next;
} Node;

typedef struct Graph
{
    int numVertices;
    Node **adjList;
} Graph;

Node *init_node(int val)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->val = val;
    node->next = NULL;

    return node;
}

Graph *init_graph(int numVertices)
{
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    graph->adjList = (Node **)malloc(numVertices * sizeof(Node *));

    return graph;
}

void addEdgeDirectional(Graph *graph, int from, int to)
{
    if (from < 0 || from >= graph->numVertices || to < 0 || to >= graph->numVertices)
    {
        printf("Invalid from or to\n");
        return;
    }

    Node *newNode = init_node(to);

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
        Node *current = graph->adjList[i];
        printf("Neighbours of %d:\n", i);
        while (current != NULL)
        {
            printf("%d ", current->val);
            current = current->next;
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