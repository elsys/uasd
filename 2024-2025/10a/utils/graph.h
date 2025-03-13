#ifndef GRAPH_H
#define GRAPH_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Vertex {
    int val;
    int weight;
    struct Vertex* next;
} Vertex;
/*
0: (2, 10) -> (3, 10) -> (2, 15) 
*/
typedef struct Graph {
    int numVertices;
    Vertex **adjList;
} Graph;

Vertex* init_vertex(int val);

Graph* init_graph(int numVertices);

void addEdgeDirectional(Graph*graph, int from, int to);
void addEdge(Graph* graph, int from, int to);

void printGraph(Graph *graph);


#endif