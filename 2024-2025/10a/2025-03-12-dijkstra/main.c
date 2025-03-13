#include <stdio.h>
#include <limits.h>
#include "../utils/graph.h"

int find_min(int* v, int size) {
    int min = INT_MAX;
    for (int i = 0; i < size; i++) {
        if (min < v[i]) {
            min = v[i];
        }
    }

    return min;
}

void dijkstra(Graph* g) {
    int *finished = (int*)calloc(g->numVertices, sizeof(int));
    int *dist = (int*)malloc(g->numVertices*sizeof(int));

    for (int i = 0; i < g->numVertices; i++) {
        dist[i] = INT_MAX;
    }
    dist[0] = 0;

    for (int i = 0; i < g->numVertices; i++) {
        int min = find_min(dist, g->numVertices);
        finished[min] = 1;

        Vertex *it = g->adjList[min];
        while(it != NULL) {
            int from = min;
            int to = it->val;
            int w = it->weight;

            if (dist[to] > dist[from] + w) {
                dist[to] = dist[from] + w;
            }

            it = it->next;
        }
    }
}

int main() {

}