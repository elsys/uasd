#include <stdio.h>
#include <limits.h>
#include "../utils/graph.h"

int find_min(int* v, int size, int* finished) {
    int min = INT_MAX;
    int minIndex = -1;
    for (int i = 0; i < size; i++) {
        if (!finished[i] && min > v[i]) {
            min = v[i];
            minIndex = i;
        }
    }

    return minIndex;
}

void dijkstra(Graph* g, int start) {
    int *finished = (int*)calloc(g->numVertices, sizeof(int));
    int *dist = (int*)malloc(g->numVertices*sizeof(int));
    int *parents = (int*)malloc(g->numVertices*sizeof(int));

    for (int i = 0; i < g->numVertices; i++) {
        dist[i] = INT_MAX;
        parents[i] = -1;
    }
    dist[start] = 0;

    // with array
    // O(V.V + E) = O(V^2)

    // with priority queue
    // O(V + E).logV
    // Remark: If |E| is at least V^2/logV then no optimization. 

    // with Fibonacci heap
    // O(V.logV + E)
    for (int i = 0; i < g->numVertices; i++) {
        int min = find_min(dist, g->numVertices, finished);
        // extract min logV
        if(min == -1) {
            return;
        }

        finished[min] = 1;

        Vertex *it = g->adjList[min];
        while(it != NULL) {
            int from = min;
            int to = it->val;
            int w = it->weight;

            if (dist[to] > w) {
                updateKey(dist, to, w); // logV
                parents[to] = from;
            }

            it = it->next;
        }
    }

    printf("Min paths parents:\n");
    for(int i = 0; i < g->numVertices; i++) {
        printf("%d: %d, ", i, parents[i]);
    }
    printf("\n");
}

int main() {
    int n = 5;
    Graph *g = init_graph(5);
    addEdgeDirectional(g, 0, 1, 10);
    addEdgeDirectional(g, 0, 3, 5);
    addEdgeDirectional(g, 1, 2, 1);
    addEdgeDirectional(g, 1, 3, 2);
    addEdgeDirectional(g, 3, 2, 9);
    addEdgeDirectional(g, 3, 1, 3);
    addEdgeDirectional(g, 3, 4, 2);
    addEdgeDirectional(g, 2, 4, 4);
    addEdgeDirectional(g, 4, 0, 7);
    addEdgeDirectional(g, 4, 2, 6);

    dijkstra(g, 0);
}