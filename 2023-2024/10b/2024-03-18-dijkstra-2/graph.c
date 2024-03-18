#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdio.h>

#include "graph.h"

//
// Internal helpers
//
graph_edge_t* find_edge(graph_node_t* node1, graph_node_t* node2) {
    list_t* curr = node1->edges;
    while(curr != NULL) {
        graph_edge_t* edge = curr->value;
        if(edge->l_node == node2 || edge->r_node == node2) return edge;

        curr = curr->next;
    }

    return NULL;
}

//
// Init and destroy
//
graph_edge_t* init_graph_edge(int weight) {
    graph_edge_t* new_edge = (graph_edge_t*)malloc(sizeof(graph_edge_t));

    new_edge->weight = weight;
    new_edge->l_node = new_edge->r_node = NULL;

    return new_edge;
}

graph_node_t* init_graph_node(char* name) {
    graph_node_t* new_node =
        (graph_node_t*)malloc(sizeof(graph_node_t));

    new_node->name = malloc(strlen(name) + 1);
    strcpy(new_node->name, name);

    new_node->edges = NULL;

    return new_node;
}

graph_t* init_graph() {
    graph_t* new_graph = (graph_t*)malloc(sizeof(graph_t));

    new_graph->size = 0;
    new_graph->nodes = NULL;

    return new_graph;
}

void destroy_graph_edge(graph_edge_t* edge) {
    free(edge);
}

void destroy_graph_node(graph_node_t* node) {
    free(node->name);
    free(node);
}

void destroy_graph(graph_t* graph) {
    while(graph->nodes != NULL) {
        graph_node_t* node = pop_list(&graph->nodes);
        destroy_graph_node(node);
    }
    free(graph);
}


//
// External helpers
//
graph_node_t* find_node_by_name(graph_t* graph, char* name) {
    list_t* curr = graph->nodes;

    while(strcmp(((graph_node_t*)curr->value)->name, name) != 0)
        curr = curr->next;

    return curr->value;
}

void print_graph(graph_t* graph) {
    printf("%d\n", graph->size);

    list_t* curr = graph->nodes;
    while(curr != NULL) {
        printf("%s ", ((graph_node_t*)curr->value)->name);
        curr = curr->next;
    }
    printf("\n");

    list_t* row = graph->nodes;
    while(row != NULL) {
        graph_node_t* outer = (graph_node_t*)row->value;

        list_t* column = graph->nodes;
        while(column != NULL) {
            graph_node_t* inner = (graph_node_t*)column->value;

            if(outer == inner) {
                printf("0 ");
            } else {
                graph_edge_t* edge = find_edge(outer, inner);

                if(edge != NULL)
                    printf("%d ", edge->weight);
                else
                    printf("0 ");
            }

            column = column->next;
        }
        printf("\n");

        row = row->next;
    }
}

//
// Manipulate nodes
//
graph_node_t* add_graph_node(graph_t* graph, char* name) {
    graph_node_t* new_node = init_graph_node(name);

    graph->nodes = push_list(graph->nodes, new_node);
    graph->size++;

    return new_node;
}

void connect_nodes(graph_node_t* node1, graph_node_t* node2, int weight) {
    graph_edge_t* new_edge = init_graph_edge(weight);

    new_edge->l_node = node1;
    new_edge->r_node = node2;

    node1->edges = push_list(node1->edges, new_edge);
    node2->edges = push_list(node2->edges, new_edge);
}
