#include <stdio.h>
#include <stdlib.h>
#include "../utils/graph.h"

void dfsR(Graph* g, int start, int* visited) {
    EdgeNode* it = g->adjList[start];
    visited[start] = 1;
    printf("%d ", start);

    while (it != NULL) {
        if (! visited[it->val]) {
            dfsR(g, it->val, visited);
        }
        it = it->next;
    }
}


void dfs(Graph* g) {
    int* visited = (int*)calloc(sizeof(int), g->numVertices);

    for (int i = 0; i < g->numVertices; i++) {
        if(! visited[i]) {
            dfsR(g, i, visited);
        }
    }

    free(visited);
}

int main() {
    Graph* g = init_graph(6);
    addEdgeDirectional(g, 0, 1);
    addEdgeDirectional(g, 0, 3);
    addEdgeDirectional(g, 1, 4);
    addEdgeDirectional(g, 2, 5);
    addEdgeDirectional(g, 2, 4);
    addEdgeDirectional(g, 3, 1);
    addEdgeDirectional(g, 4, 3);
    addEdgeDirectional(g, 5, 5);

    dfs(g);


    return 0;
}