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


int isCycleR(Graph *g, int start, int* visited, int* dist, int* parent) {
    visited[start] = 1;
    printf("%d ", start);
    Vertex *it = g->adjList[start];

    while (it != NULL) {
        if (!visited[it->val]) {
            dist[it->val] = dist[start] + 1;
            parent[it->val] = start;
            // insert
            if(isCycleR(g, it->val, visited, dist, parent)) {
                return 1;
            }
            // pop
        } else {
            int i = start;
            while(parent[i] != -1) {
                if (parent[i] == it->val) {
                    return 1;
                }
                i = parent[i];
            }
        }
        it = it->next;
    }

    return 0;
}

int isCycle(Graph *g) {
    int *visited = (int*)calloc(sizeof(int),g->numVertices);
    int *dist = (int*)calloc(sizeof(int), g->numVertices);
    int *parent = (int*)malloc(sizeof(int)*g->numVertices);

    int numIslands = 0;
    for (int i = 0; i < g->numVertices; i++) {
        if (!visited[i]) {
            numIslands++;
            parent[i] = -1;
            if (isCycleR(g, i, visited, dist, parent)) {
                return 1;
            }   
        }
    }

    free(visited);
    free(dist);
    free(parent);

    return 0;

    printf("\nDistances:\n");
    for (int i = 0; i < g->numVertices; i++) {
        printf("%d ", dist[i]);
    }
    printf("\n");
    printf("Parents:\n");
    for (int i = 0; i < g->numVertices; i++) {
        printf("%d ", parent[i]);
    }

}


int main() {
    Graph* g = init_graph(4);

    addEdgeDirectional(g, 0, 1);
    addEdgeDirectional(g, 1, 2);
    addEdgeDirectional(g, 2, 3);
    addEdgeDirectional(g, 3, 0);

    if (isCycle(g)) {
        printf("has cycle");
    } else {
        printf("no cycle");
    }

    return 0;
}