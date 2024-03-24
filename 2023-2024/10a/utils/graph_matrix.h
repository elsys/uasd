#ifndef GRAPH_MATRIX_H
#define GRAPH_MATRIX_H

typedef struct Graph
{
    int numVertices;
    int **adjMatrix;
} Graph;

Graph *init_graph(int numVertices);
void addEdgeDirectional(Graph *graph, int from, int to);
void addEdge(Graph *graph, int from, int to);
void printGraph(Graph *graph);

#endif