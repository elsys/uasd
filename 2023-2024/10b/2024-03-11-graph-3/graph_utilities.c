#include "graph_utilities.h"

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