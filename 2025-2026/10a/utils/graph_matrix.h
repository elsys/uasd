#ifndef _GRAPH_MATRIX_H_
#define _GRAPH_MATRIX_H_

typedef struct Graph {
    int numVertices;
    int** adjMatrix;
} Graph;

Graph* init_graph(int numVertices);
void addEdgeDirectional(Graph* g, int start, int end);
void addEdge(Graph* g, int start, int end);
void printGraph(Graph* g);

#endif
