#include "hashmap.h"
#include "graph_h.h"
#include <stdio.h>
#include <stdlib.h>

Vertex* init_vertex(char* val, double weight) {
    Vertex* vertex = (Vertex*)malloc(sizeof(Vertex));
    vertex->val = val;
    vertex->weight = weight;
    vertex->next = NULL;

    return vertex;
}

Graph* init_graph() {
    Graph *graph = (Graph*)malloc(sizeof(Graph));
    graph->adjList = init_hashmap();

    return graph;
}

void addEdgeDirectional(Graph*graph, char* from, char* to, double weight) {
    Vertex* new_vertex = init_vertex(to, weight);

    new_vertex->next = (Vertex*)get(graph->adjList, from);
    set(graph->adjList, from, new_vertex);
}

void addEdge(Graph* graph, char* from, char* to, double weight) {
    addEdgeDirectional(graph, from, to, weight);
    addEdgeDirectional(graph, to, from, weight);
}

void printGraph(Graph *graph) {
    for (int j = 0; j < HASHMAP_SIZE; j++) {
        EntryNode* entry = graph->adjList->entries[j];

        while(entry != NULL) {
            Vertex* it = (Vertex*)entry->val;
            printf("Neighbors of %s: ", entry->key);
            while (it != NULL)
            {
                printf("%s ", it->val);
                it = it->next;
            }
            printf("\n");

            entry = entry->next;
        }
        
    }
}