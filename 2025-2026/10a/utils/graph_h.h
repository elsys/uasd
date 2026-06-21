#ifndef _GRAPH_H_
#define _GRAPH_H_
#include "hashmap.h"

typedef struct EdgeNode {
    int val;
    int weight;
    struct EdgeNode* next;
} EdgeNode;
 
typedef struct Graph {
    HashMap* adjList;
} Graph;

EdgeNode* init_edgenode(char* val, int weight);
Graph* init_graph();
void addEdgeDirectional(Graph* g, char* start, char* end, int weight);
void addEdge(Graph* g, char* start, char* end, int weight);
void printGraph(Graph* g);

#endif