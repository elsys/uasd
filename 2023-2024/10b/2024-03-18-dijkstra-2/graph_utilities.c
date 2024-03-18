#include <stdlib.h>
#include <string.h>
#include "graph_utilities.h"
#include "priority_queue.h"

// graph_t* init_graph_from_strings(char* lines[]) {
//     graph_t* new_graph = init_graph();

//     int node_count = atoi(lines[0]);
//     for(int i = 0; i < node_count; i++) {
//         char buffer[100];
//         sscanf(lines[1], "%s", buffer);

//         add_graph_node(new_graph, buffer);
//     }

//     return new_graph;
// }

// tree_t* init_tree() {
//     tree_t* new_tree = malloc(sizeof(tree_t));
//     new_tree->children = new_tree->value = NULL;
//     return new_tree;
// }

// void tree_add(tree_t* tree, void* child) {
//     tree_t* node = init_tree();
//     node->value = child;

//     if(tree->children == NULL)
//         tree->children = init_list(node);
//     else
//         push_list(tree->children, node);
// }

// int is_in_tree(graph_node_t* graph_node) {
//     return 0;
// }

// void recurse_add(tree_t* tree_root) {
//     graph_node_t* graph_node = tree_root->value;

//     for(int i = 0; i < list_length(graph_node->edges); i++) {
//         graph_node_t* neighbour = list_get_at(graph_node->edges, i);
//         if(!is_in_tree(neighbour))
//             tree_add(
//                 tree_root,
//                 neighbour
//             );
//     }

//     for(int i = 0; i < list_length(tree_root->children); i++) {
//         recurse_add(
//             list_get_at(tree_root->children, i)
//         );
//     }
// }

// tree_t* graph_span_tree(graph_t* graph, char* name) {
//     // printf("0");
//     tree_t* tree_root = init_tree();
// // printf("1");
//     graph_node_t* root = find_node_by_name(graph, name);
//     // printf("2");
//     tree_root->value = root;
// // printf("3");

//     recurse_add(tree_root);

//     return tree_root;
// }


struct djikstra_info_t {
    graph_node_t* node;
    int visited;
    int weight;
    graph_node_t* prev;
};

int compare_nodes(void* left, void* right) {
    int w1 = ((struct djikstra_info_t*)left)->weight;
    int w2 = ((struct djikstra_info_t*)right)->weight;

    if(w1 == w2) return 0;
    if(w1 == -1) return 1;
    if(w2 == -1) return -1;

    return w1 - w2;
}

void find_dijkstra_route(graph_t* graph, char* start, char* end) {
    list_t* info = NULL;

    queue_t* nodes = priority_queue(compare_nodes);
    for(int i = 0; i < list_length(graph->nodes); i++) {
        struct djikstra_info_t* d_node = malloc(sizeof(struct djikstra_info_t));
        d_node->node = list_get_at(graph->nodes, i);
        d_node->visited = 0;
        if(strcmp(start, d_node->node->name) == 0)
            d_node->weight = 0;
        else
            d_node->weight = -1;
        d_node->prev = NULL;

        push_queue(nodes, d_node);
    }

    // put all nodes in priority queue
    // set all weights to INF (-1)
    // find start, set weight to 0
    
    // while queue not empty
        // take node with least weight
        // find new weights for neighbors
        // weight(neighbor) = weight(node) + weight(edge)
        // if new weight < old weight then update table
}