 #include <stdio.h>
#include <stdlib.h>
#include "graph_h.h"
#include "hashmap.h"

EdgeNode* init_edgenode(char* val, int weight) {
    EdgeNode* node = (EdgeNode*)malloc(sizeof(EdgeNode));
    node->val = val;
    node->weight = weight;
    node->next = NULL;
 
    return node;
}
 
Graph* init_graph() {
    Graph* g = (Graph*)malloc(sizeof(Graph));
    g->adjList = init_hashmap();

    return g;
}
 
void addEdgeDirectional(Graph* g, char* start, char* end, int weight) {
    EdgeNode* new_node = init_edgenode(end, weight);

    EdgeNode* head = (EdgeNode*)get(g->adjList, start);

    if (head == NULL) {
        set(g->adjList, start, new_node);
    } else {
        new_node->next = head;
        set(g->adjList, start, new_node);
    }
}
 
void addEdge(Graph* g, char* start, char* end, int weight) {
    addEdgeDirectional(g, start, end, weight);
    addEdgeDirectional(g, end, start, weight);
}
 
// O(V + E)
void printGraph(Graph* g) {
    // Iterate through all entries in the adjacency list
    for (int i = 0; i < HASH_MAP_SIZE; i++) {
        EntryNode* entry = g->adjList->arr[i];
        while (entry != NULL) {
            printf("%s: ", entry->key);
            EdgeNode* it = (EdgeNode*)entry->val;
            while (it != NULL) {
                printf("%d(%d), ", it->val, it->weight);
                it = it->next;
            }
            printf("\n");
            entry = entry->next;
        }
    }
}
char* charToString(int val) {
    char* str = (char*)malloc(12 * sizeof(char)); // Enough to hold an integer
    sprintf(str, "%d", val);
    return str;
}
