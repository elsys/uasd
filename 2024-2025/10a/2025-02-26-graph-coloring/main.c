#include <stdio.h>
#include <stdlib.h>
#include "../utils/queue.h"

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

int dfsR(Graph *g, int start, int* colors) {
    Vertex *it = g->adjList[start];
    int prevColor = colors[start];
    int newColor = prevColor == '1' ? '2' : '1';
    
    while (it != NULL) {
        if (!colors[it->val]) {
            colors[it->val] = newColor;
            if(!dfsR(g, it->val, colors)) {
                return 0;
            }
        } else if (colors[it->val] != newColor) {
            return 0;
        }
        it = it->next;
    }

    return 1;
}

int dfs(Graph *g) {
    int *colors = (int*)calloc(sizeof(int),g->numVertices);

    int isBipartite = 1;
    for (int i = 0; i < g->numVertices; i++) {
        if (!colors[i]) {
            isBipartite = dfsR(g, i, colors);    
        }
    }

    return isBipartite;
}

int main() {
    Graph* g = init_graph(5);
    addEdge(g,0,1);
    addEdge(g,0,2);
    addEdge(g,0,4);
    addEdge(g,3,4);
    //addEdge(g,2,1);
    addEdge(g,2,3);
;
    if(dfs(g)) {
        printf("IsBipartite\n");
    } else {
        printf("Not Bipartite\n");
    }
    printf("\n");


    return 0;
}