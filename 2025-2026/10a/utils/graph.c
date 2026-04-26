 #include <stdio.h>
#include <stdlib.h>
#include "graph.h"

EdgeNode* init_edgenode(int val, int weight) {
    EdgeNode* node = (EdgeNode*)malloc(sizeof(EdgeNode));
    node->val = val;
    node->weight = weight;
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
 
void addEdgeDirectional(Graph* g, int start, int end, int weight) {
    EdgeNode* new_node = init_edgenode(end, weight);
 
    new_node->next = g->adjList[start];
    g->adjList[start] = new_node;
}
 
void addEdge(Graph* g, int start, int end, int weight) {
    addEdgeDirectional(g, start, end, weight);
    addEdgeDirectional(g, end, start, weight);
}
 
// O(V + E)
void printGraph(Graph* g) {
    for (int i = 0; i < g->numVertices; i++) {
        printf("%d: ", i);
        EdgeNode* it = g->adjList[i];
        while(it != NULL) {
            printf("%d(%d), ", it->val, it->weight);
            it = it->next;
        }
 
        printf("\n");
    }
}
