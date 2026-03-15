#include "../utils/graph.h"
#include "../utils/queue.h"
#include <stdlib.h>


int main() {
    Graph* g = init_graph(6);
    Queue* q = init_queue();

    addEdge(g, 0, 1);
    addEdge(g, 0, 3);
    addEdge(g, 1, 4);
    addEdge(g, 2, 5);
    addEdge(g, 2, 4);
    addEdge(g, 3, 1);
    addEdge(g, 4, 3);
    addEdge(g, 5, 5);

    enqueue(q, 0);
    int* visited = (int*)calloc(sizeof(int), g->numVertices);
    int* dist = (int*)calloc(sizeof(int), g->numVertices);
    int* parent = (int*)calloc(sizeof(int), g->numVertices);

    while (q->front != NULL) {
        int current = dequeue(q);
        visited[current] = 1;
        printf("%d ", current);

        EdgeNode* it = g->adjList[current];
        while (it != NULL) {
            if (! visited[it->val]) {
                visited[it->val] = 1;
                dist[it->val] = dist[current] + 1;
                parent[it->val] = current;
                enqueue(q, it->val);
            }
            it = it->next;
        }
    }

    return 0;
}