#pragma once

#include "list.h"

struct graph_node_t {
    char* name;
    list_t* edges;
};

struct graph_t {
    int size;
    list_t* nodes;
};

typedef struct graph_node_t graph_node_t;
typedef struct graph_t graph_t;

graph_node_t* init_graph_node(char* name);
graph_t* init_graph();

void connect_nodes(graph_node_t* node1, graph_node_t* node2);

graph_node_t* find_node_by_name(graph_t* graph, char* name);

graph_node_t* add_graph_node(graph_t* graph, char* name);

void print_graph(graph_t* graph);

graph_t* init_graph_from_strings(char* lines[]);


struct tree_t {
    struct list_t* children;
    void* value;
};

typedef struct tree_t tree_t;

tree_t* graph_span_tree(graph_t* graph, char* name);