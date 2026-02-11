 #include <stdio.h>
#include <stdlib.h>
#include "graph.h"

EdgeNode* init_edgenode(int val) {
    EdgeNode* node = (EdgeNode*)malloc(sizeof(EdgeNode));
    node->val = val;
    node->next = NULL;
 
    return node;
}
 
Graph* init_graph(int numVertices) {
    Graph* g = (Graph*)malloc(sizeof(Graph));
    g->numVertices = numVertices;
 
    g->adjList = (EdgeNode**)malloc(sizeof(EdgeNode*)*numVertices);
    for (int i = 0; i < numVertices; i++) {
        g->adjList[i] = NULL;
    }
 
    return g;
}
 
void addEdgeDirectional(Graph* g, int start, int end) {
    EdgeNode* new_node = init_edgenode(end);
 
    new_node->next = g->adjList[start];
    g->adjList[start] = new_node;
}
 
void addEdge(Graph* g, int start, int end) {
    addEdgeDirectional(g, start, end);
    addEdgeDirectional(g, end, start);
}
 
// O(V + E)
void printGraph(Graph* g) {
    for (int i = 0; i < g->numVertices; i++) {
        printf("%d: ", i);
        EdgeNode* it = g->adjList[i];
        while(it != NULL) {
            printf("%d, ", it->val);
            it = it->next;
        }
 
        printf("\n");
    }
}
