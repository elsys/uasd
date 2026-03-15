#include "../utils/graph.h"
#include <stdlib.h>

int detectCycleR(Graph* g, int start, int* visited, int* currentPath) {
    if (visited[start]) {
        return 0;
    }

    EdgeNode* it = g->adjList[start];
    visited[start] = 1;
    currentPath[start] = 1;
    printf("%d ", start);

    while (it != NULL) {
        if (currentPath[it->val]) {
            printf("Cycle detected\n");
            return 1;
        }

        int result = detectCycleR(g, it->val, visited, currentPath);
        if (result) {
            return 1;
        }
        it = it->next;
    }

    currentPath[start] = 0;
    return 0; 
}


int detectCycle(Graph* g) {
    int* visited = (int*)calloc(sizeof(int), g->numVertices);
    int* currentPath = (int*)calloc(sizeof(int), g->numVertices);

    for (int i = 0; i < g->numVertices; i++) {
        if(! visited[i]) {
            if (detectCycleR(g, i, visited, currentPath)) {
                free(visited);
                free(currentPath);
                return 1;
            }
        }
    }

    free(visited);
    free(currentPath);
    return 0;
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