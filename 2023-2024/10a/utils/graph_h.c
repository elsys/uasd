
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graph_h.h"

VertexNode *init_node(char *val, double weight)
{
    VertexNode *node = (VertexNode *)malloc(sizeof(VertexNode));
    node->val = strdup(val);
    node->next = NULL;
    node->weight = weight;

    return node;
}

Graph *init_graph()
{
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->adjList = init_hash_map();

    return graph;
}

void addEdgeDirectional(Graph *graph, char *from, char *to, double weight)
{
    VertexNode *newNode = init_node(to, weight);

    newNode->next = get(graph->adjList, from);
    set(graph->adjList, from, newNode);
}

void addEdge(Graph *graph, char *from, char *to, double weight)
{
    addEdgeDirectional(graph, from, to, weight);
    addEdgeDirectional(graph, to, from, weight);
}

// char* strdup(char* str) {
//     char* new_str = (char*)malloc(strlen(str) + 1);
//     strcpy(new_str, str);
//     return new_str;
// }

void printGraph(Graph *graph)
{
    for (int i = 0; i < HASH_SIZE; i++)
    {
        EntryNode *current = graph->adjList->array[i];
        if (current == NULL)
        {
            continue;
        }

        while (current != NULL)
        {
            VertexNode *currentNode = (VertexNode *)current->val;
            printf("Neighbours of %s:\n", current->key);
            while (currentNode != NULL)
            {
                printf("%s(%f) ", currentNode->val, currentNode->weight);
                currentNode = currentNode->next;
            }
            current = current->next;
            printf("\n");
        }
    }
}
