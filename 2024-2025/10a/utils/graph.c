#include <stdio.h>
#include <stdlib.h>
#include "graph.h"


Vertex* init_vertex(int val, int weight) {
    Vertex* vertex = (Vertex*)malloc(sizeof(Vertex));
    vertex->val = val;
    vertex->weight = weight;
    vertex->next = NULL;

    return vertex;
}

Graph* init_graph(int numVertices) {
    Graph *graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    graph->adjList = (Vertex**)calloc(numVertices, sizeof(Vertex*));

    return graph;
}

void addEdgeDirectional(Graph*graph, int from, int to, int weight) {
    Vertex* new_vertex = init_vertex(to, weight);
    new_vertex->next = graph->adjList[from];
    graph->adjList[from] = new_vertex;
}

void addEdge(Graph* graph, int from, int to, int weight) {
    addEdgeDirectional(graph, from, to, weight);
    addEdgeDirectional(graph, to, from, weight);
}

void printGraph(Graph *graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        Vertex* it = graph->adjList[i];
        printf("Neighbors of %d: ", i);
        while (it != NULL)
        {
            printf("%d ", it->val);
            it = it->next;
        }
        printf("\n");
    }
}