#ifndef GRAPH_H_H
#define GRAPH_H_H

#include "hashmap.h"
typedef struct Vertex {
    char* val;
    double weight;
    struct Vertex* next;
} Vertex;
/*
0: (2, 10) -> (3, 10) -> (2, 15) 
*/
typedef struct Graph {
    HashMap* adjList;
} Graph;

Vertex* init_vertex(char* val, double weight);
Graph* init_graph();

void addEdgeDirectional(Graph*graph, char* from, char* to, double weight);
void addEdge(Graph* graph, char* from, char* to, double weight);

void printGraph(Graph *graph);

#endif