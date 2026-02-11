#include <stdio.h>
#include <stdlib.h>
#include "graph_matrix.h"
 
Graph* init_graph(int numVertices) {
    Graph* g = (Graph*)malloc(sizeof(Graph));
    g->numVertices = numVertices;
 
    g->adjMatrix = (int**)malloc(sizeof(int*)*numVertices);
    for (int i = 0; i < numVertices; i++) {
        g->adjMatrix[i] = (int*)calloc(numVertices, sizeof(int));
    }
 
    return g;
}
 
void addEdgeDirectional(Graph* g, int start, int end) {
    g->adjMatrix[start][end] = 1;
}
 
void addEdge(Graph* g, int start, int end) {
    addEdgeDirectional(g, start, end);
    addEdgeDirectional(g, end, start);
}

void printGraph(Graph* g) {
    for (int i = 0; i < g->numVertices; i++) {
        printf("%d: ", i);
        for (int j = 0; j < g->numVertices; j++) {
            if (g->adjMatrix[i][j] == 1) {
                printf("%d,", j);
            }
        }
        printf("\n");
    }
}
