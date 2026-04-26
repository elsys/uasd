#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
# include <stdint.h>
#include "../utils/graph.h"
#include "../utils/pqueue.h"


// Implementation with priority queue. A bit different than the one we did in class which 
// was with manual finding of min element
void djikstra(Graph* g, int start) {
    int* distances = (int*)malloc(sizeof(int) * g->numVertices);
    int *parents = (int*)malloc(sizeof(int) * g->numVertices);
    for (int i = 0; i < g->numVertices; i++) {
        distances[i] = INT_MAX;
        parents[i] = -1;
    }
    distances[start] = 0;

    PQueue* pq = init_pq();
    pqInsertInt(pq, start, 0);

    while (pq->size > 0) {
        PQNode* current = deleteMin(pq);
            int currentVertex = (int)(intptr_t)current->data;
            int currentDistance = current->key;

        if (currentDistance > distances[currentVertex]) {
            continue;
        }

        EdgeNode* it = g->adjList[currentVertex];
        while (it != NULL) {
            int neighbor = it->val;
            int weight = it->weight;
            int newDistance = distances[currentVertex] + weight;

            if (newDistance < distances[neighbor]) {
                distances[neighbor] = newDistance;
                parents[neighbor] = currentVertex;
                pqInsertInt(pq, neighbor, newDistance);
            }
            it = it->next;
        }
    }

    // Print distances
    for (int i = 0; i < g->numVertices; i++) {
        printf("Distance from vertex %d to vertex %d: %d\n", start, i, distances[i]);
    }

    free(distances);
    free(parents);
}

// here is how it wa sin class, without priority queue, just to compare
int extractMin(int* distances, int* visited, int numVertices) {
    int minVertex = -1;
    for (int i = 0; i < numVertices; i++) {
        if (!visited[i] && (minVertex == -1 || distances[i] < distances[minVertex])) {
            minVertex = i;
        }
    }
    return minVertex;
}

void djikstraWithoutPQ(Graph* g, int start) {
    int* distances = (int*)malloc(sizeof(int) * g->numVertices);
    int *parents = (int*)malloc(sizeof(int) * g->numVertices);
    int* visited = (int*)calloc(sizeof(int), g->numVertices);
    for (int i = 0; i < g->numVertices; i++) {
        distances[i] = INT_MAX;
        parents[i] = -1;
    }
    distances[start] = 0;

    for (int i = 0; i < g->numVertices; i++) {
        int currentVertex = extractMin(distances, visited, g->numVertices);
        visited[currentVertex] = 1;

        EdgeNode* it = g->adjList[currentVertex];
        while (it != NULL) {
            int neighbor = it->val;
            int weight = it->weight;
            int newDistance = distances[currentVertex] + weight;

            if (newDistance < distances[neighbor]) {
                distances[neighbor] = newDistance;
                parents[neighbor] = currentVertex;
            }
            it = it->next;
        }
    }
    // Print distances
    for (int i = 0; i < g->numVertices; i++) {
        printf("Distance from vertex %d to vertex %d: %d\n", start, i, distances[i]);
    }

    free(distances);
    free(parents);
    free(visited);

}