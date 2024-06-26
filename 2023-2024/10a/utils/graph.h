#ifndef GRAPH_H
#define GRAPH_H

typedef struct VertexNode
{
    int val;
    int weight;
    struct VertexNode *next;
} VertexNode;

typedef struct Graph
{
    int numVertices;
    VertexNode **adjList;
} Graph;

VertexNode *init_node(int val, int weight);
Graph *init_graph(int numVertices);
void addEdgeDirectional(Graph *graph, int from, int to, int weigth);
void addEdge(Graph *graph, int from, int to, int weigth);
void printGraph(Graph *graph);

#endif