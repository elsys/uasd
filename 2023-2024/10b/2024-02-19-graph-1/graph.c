#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdio.h>

#include "graph.h"

graph_node_t* init_graph_node(char* name) {
    graph_node_t* new_node = 
        (graph_node_t*)malloc(sizeof(graph_node_t));

    new_node->name = malloc(strlen(name));
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

void connect_nodes(graph_node_t* node1, graph_node_t* node2) {
    if(node1->edges == NULL) {
        node1->edges = init_list();
        node1->edges->value = node2;
    } else {
        push_list(node1->edges, node2);
    }

    if(node2->edges == NULL) {
        node2->edges = init_list();
        node2->edges->value = node1;
    } else {
        push_list(node2->edges, node1);
    }
}

graph_node_t* find_node_by_name(graph_t* graph, char* name) {
    list_t* curr = graph->nodes;

    while(strcmp(((graph_node_t*)curr->value)->name, name) != 0) 
        curr = curr->next;

    return curr->value;
}

graph_node_t* add_graph_node(graph_t* graph, char* name) {
    graph_node_t* new_node = init_graph_node(name);

    if(graph->nodes == NULL) {
        graph->nodes = init_list();
        graph->nodes->value = new_node;
    } else {
        push_list(graph->nodes, new_node);
    }
    graph->size++;

    return new_node;
}

int is_node_connected(graph_node_t* node1, graph_node_t* node2) {
    list_t* curr = node1->edges;
    while(curr != NULL) {
        if(curr->value == node2) return 1;

        curr = curr->next;
    }

    return 0;
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

            if(is_node_connected(outer, inner))
                printf("1 ");
            else 
                printf("0 ");

            column = column->next;
        }
        printf("\n");

        row = row->next;
    }
}

graph_t* init_graph_from_strings(char* lines[]) {
    graph_t* new_graph = init_graph();

    int node_count = atoi(lines[0]);
    for(int i = 0; i < node_count; i++) {
        char buffer[100];
        sscanf(lines[1], "%s", buffer);

        add_graph_node(new_graph, buffer);
    }

    return new_graph;
}