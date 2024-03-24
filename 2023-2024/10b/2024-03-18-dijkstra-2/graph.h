#pragma once

#include "list.h"

typedef struct graph_edge_t graph_edge_t;
typedef struct graph_node_t graph_node_t;
typedef struct graph_t graph_t;

struct graph_edge_t {
    int weight;
    graph_node_t* l_node;
    graph_node_t* r_node;
};

struct graph_node_t {
    char* name;
    list_t* edges; // graph_edge_t*
};

struct graph_t {
    int size;
    list_t* nodes; // graph_t*
};

graph_edge_t* init_graph_edge(int weight);
graph_node_t* init_graph_node(char* name);
graph_t* init_graph();

void destroy_graph_edge(graph_edge_t*);
void destroy_graph_node(graph_node_t*);
void destroy_graph(graph_t*);


graph_node_t* find_node_by_name(graph_t* graph, char* name);
void print_graph(graph_t* graph);

graph_node_t* add_graph_node(graph_t* graph, char* name);
void connect_nodes(graph_node_t* node1, graph_node_t* node2, int weight);
