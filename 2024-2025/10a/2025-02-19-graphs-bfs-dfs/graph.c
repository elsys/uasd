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

void dfsR(Graph *g, int start, int* visited, int* dist, int* parent) {
    visited[start] = 1;
    printf("%d ", start);
    Vertex *it = g->adjList[start];

    while (it != NULL) {
        if (!visited[it->val]) {
            dist[it->val] = dist[start] + 1;
            parent[it->val] = start;
            dfsR(g, it->val, visited, dist, parent);
        }
        it = it->next;
    }
}

void dfs(Graph *g) {
    int *visited = (int*)calloc(sizeof(int),g->numVertices);
    int *dist = (int*)calloc(sizeof(int), g->numVertices);
    int *parent = (int*)malloc(sizeof(int)*g->numVertices);

    int numIslands = 0;
    for (int i = 0; i < g->numVertices; i++) {
        if (!visited[i]) {
            numIslands++;
            parent[i] = -1;
            dfsR(g, i, visited, dist, parent);    
        }
    }

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

void bfs(Graph*g) {
    int *visited = (int*)calloc(sizeof(int),g->numVertices);
    int *dist = (int*)calloc(sizeof(int), g->numVertices);
    int *parent = (int*)malloc(sizeof(int)*g->numVertices);
    parent[0] = -1;
    visited[0] = 1;

    Queue* queue = init_queue();
    enqueue(queue, 0);
    printf("0 ");

    while(queue->front != NULL) {
        int current = dequeue(queue);
    
        Vertex *it = g->adjList[current];

        while (it != NULL) {
            if (!visited[it->val]) {
                printf("%d ", it->val);
                dist[it->val] = dist[current] + 1;
                parent[it->val] = current;
                visited[it->val] = 1;
                enqueue(queue, it->val);
            }
            it = it->next;
        }
    }

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
    Graph* g = init_graph(5);
    addEdgeDirectional(g,0,1);
    addEdge(g,0,2);
    addEdge(g,0,4);
    addEdge(g,3,4);
    addEdge(g,2,1);
    addEdge(g,2,3);

    bfs(g);
    printf("\n\n");
    dfs(g);
    printf("\n");


    return 0;
}