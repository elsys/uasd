#include <stdio.h>
#include <stdlib.h>

typedef struct Vertex {
    int val;
    struct Vertex* next;
} Vertex;

typedef struct Graph {
    int numVertices;
    Vertex **adjList;
} Graph;

Vertex* init_vertex(int val) {
    Vertex* vertex = (Vertex*)malloc(sizeof(Vertex));
    vertex->val = val;
    vertex->next = NULL;

    return vertex;
}

Graph* init_graph(int numVertices) {
    Graph *graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    graph->adjList = (Vertex**)calloc(numVertices, sizeof(Vertex*));

    return graph;
}

void addEdgeDirectional(Graph*graph, int from, int to) {
    Vertex* new_vertex = init_vertex(to);
    new_vertex->next = graph->adjList[from];
    graph->adjList[from] = new_vertex;
}

void addEdge(Graph* graph, int from, int to) {
    addEdgeDirectional(graph, from, to);
    addEdgeDirectional(graph, to, from);
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

int main() {
    Graph* g = init_graph(5);
    addEdgeDirectional(g,0,1);
    addEdge(g,0,2);
    addEdge(g,0,4);
    addEdge(g,3,4);
    addEdge(g,2,1);
    addEdge(g,2,3);

    printGraph(g);

    return 0;
}