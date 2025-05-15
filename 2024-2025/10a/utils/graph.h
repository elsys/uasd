#ifndef GRAPH_H
#define GRAPH_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Vertex {
    int val;
    double weight;
    struct Vertex* next;
} Vertex;
/*
0: (2, 10) -> (3, 10) -> (2, 15) 
*/
typedef struct Graph {
    int numVertices;
    Vertex **adjList;
} Graph;

Vertex* init_vertex(int val, double weight);

Graph* init_graph(int numVertices);

void addEdgeDirectional(Graph*graph, int from, int to, double weight);
void addEdge(Graph* graph, int from, int to, double weight);

void printGraph(Graph *graph);


#endif