#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASHMAP_SIZE 16

typedef struct EntryNode {
    char* key;
    void* val;
    struct EntryNode* next;
} EntryNode;

typedef struct HashMap {
    EntryNode** entries;
} HashMap;


EntryNode* init_entry(char* key, void* val) {
    EntryNode* entry = (EntryNode*)malloc(sizeof(EntryNode));
    entry->key = strdup(key);
    entry->val = val;
    entry->next = NULL;

    return entry;
}

HashMap* init_hashmap() {
    HashMap* hashmap = (HashMap*)malloc(sizeof(HashMap));
    hashmap->entries = (EntryNode**)calloc(HASHMAP_SIZE, sizeof(EntryNode*));

    return hashmap;
}

int hash(char* key) {
    int sum = 0;
    for (int i = 0; i < strlen(key); i++) {
        sum += key[i];
    }

    return sum % HASHMAP_SIZE;
}

void* get(HashMap* hashmap, char* key) {
    int index = hash(key);

    EntryNode* it = hashmap->entries[index];
    while(it != NULL) {
        if (!strcmp(it->key, key)) {
            return it->val;
        }
        it = it->next;
    }

    return NULL;
}

void set(HashMap* hashmap, char* key, void* val) {
    int index = hash(key);

    EntryNode* entry = init_entry(key, val);
    EntryNode* it = hashmap->entries[index];

    while(it != NULL) {
        if (!strcmp(it->key, key)) {
            it->val = val;
            return;
        }

        it = it->next;
    }

    entry->next = hashmap->entries[index];
    hashmap->entries[index] = entry;
}


typedef struct Vertex {
    char* val;
    double weight;
    struct Vertex* next;
} Vertex;
/*
0: (2, 10) -> (3, 10) -> (2, 15) 
*/
typedef struct Graph {
    HashMap* adjList;
} Graph;

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

int main() {
    Graph* g = init_graph();
    addEdge(g, "Sofia", "London", 1);
    addEdge(g, "Sofia", "Plovdiv", 1);

    printGraph(g);

    return 0;
}