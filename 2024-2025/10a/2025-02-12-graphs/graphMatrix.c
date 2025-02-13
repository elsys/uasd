#include <stdio.h>
#include <stdlib.h>

typedef struct Graph {
    int numVertices;
    int **adjMatrix;
} Graph;

Graph* init_graph(int numVertices) {
    Graph *graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    graph->adjMatrix = (int**)malloc(numVertices * sizeof(int*));
    for (int i = 0; i < numVertices; i++) {
        graph->adjMatrix[i] = (int*)calloc(numVertices, sizeof(int));
    }

    return graph;
}

void addEdgeDirectional(Graph*graph, int from, int to) {
    graph->adjMatrix[from][to] = 1;
}

void addEdge(Graph* graph, int from, int to) {
    addEdgeDirectional(graph, from, to);
    addEdgeDirectional(graph, to, from);
}

void printGraph(Graph *graph) {
    printf("# ");
    for(int i = 0; i < graph->numVertices; i++) {
        printf("%d ", i);
    }
    printf("\n");
    for (int i = 0; i < graph->numVertices; i++) {
        printf("%d ", i);
        for(int j = 0; j < graph->numVertices; j++) {
            printf("%d ", graph->adjMatrix[i][j]);
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