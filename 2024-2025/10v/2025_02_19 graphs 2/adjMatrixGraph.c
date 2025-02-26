#include<stdio.h>
#include<stdlib.h>

typedef struct Graph {
    int vertexCount;
    int** adjMatrix;
} Graph;

Graph* initGraph(int vertexCount) {
    Graph* graph = (Graph*) malloc(sizeof(Graph));
    graph->vertexCount = vertexCount;
    graph->adjMatrix = (int**) malloc(sizeof(int*) * vertexCount);

    for(int i = 0; i < vertexCount; i++) {
        graph->adjMatrix[i] = (int*) calloc(vertexCount, sizeof(int));
    }

    return graph;
}

void printGraph(Graph* graph) {
    printf("# ");
    for(int i = 0; i < graph->vertexCount; i++) {
        printf("%d ", i);
    }
    printf("\n");
    for(int i = 0; i < graph->vertexCount; i++) {
        printf("%d ", i);
        for(int j = 0; j < graph->vertexCount; j++) {
            printf("%d ", graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

void addEdgeDirectional(Graph* graph, int from, int to) {
    graph->adjMatrix[from][to] = 1;
}

void addEdge(Graph* graph, int vertex1, int vertex2) {
    addEdgeDirectional(graph, vertex1, vertex2);
    addEdgeDirectional(graph, vertex2, vertex1);
}

int hasEdge(Graph* graph, int from, int to) {
    return graph->adjMatrix[from][to];
}

int getInDegree(Graph* graph, int vertex) {
    int count = 0;
    for(int i = 0; i < graph->vertexCount; i++) {
        count += graph->adjMatrix[i][vertex];
    }
    return count;
}

int getOutDegree(Graph* graph, int vertex) {
    int count = 0;
    for(int i = 0; i < graph->vertexCount; i++) {
        count += graph->adjMatrix[vertex][i];
    }
    return count;
}

int main() {
    Graph* graph = initGraph(6);
    addEdgeDirectional(graph, 0, 5);
    addEdgeDirectional(graph, 4, 0);
    addEdge(graph, 0, 3);
    addEdge(graph, 4, 3);
    addEdge(graph, 1, 5);
    addEdge(graph, 4, 1);
    addEdge(graph, 4, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 5, 2);
    addEdge(graph, 0, 1);

    printGraph(graph);

    int testNode = 4;
    printf("%d in:%d\n", testNode, getInDegree(graph, testNode));
    printf("%d in:%d\n", testNode, getOutDegree(graph, testNode));
}