#ifndef GRAPH_H
#define GRAPH_H
#include "hash.h"

typedef struct VertexNode
{
    char *val;
    double weight;
    struct VertexNode *next;
} VertexNode;

typedef struct Graph
{
    HashMap *adjList;
} Graph;

VertexNode *init_node(char *val, double weight);
Graph *init_graph();
void addEdgeDirectional(Graph *graph, char *from, char *to, double weight);
void addEdge(Graph *graph, char *from, char *to, double weight);
void printGraph(Graph *graph);

#endif