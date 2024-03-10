#pragma once

#include "graph.h"

graph_t* init_graph_from_strings(char* lines[]);

struct span_tree_t {
    struct list_t* children;
    void* value;
};

typedef struct span_tree_t span_tree_t;

span_tree_t* graph_span_tree(graph_t* graph, char* name);