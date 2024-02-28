#include <stdio.h>

#include "graph.h"

int main() {
    // list_t* list = init_list();
    // push_list(list, 1);
    // push_list(list, 2);

    // for(int i = 0; i < 3; i++) 
    //     printf("%d\n", list_get_at(list, i));

    // graph_node_t* node1 = init_graph_node("Pencho");
    // printf("%s\n", node1->name);

    // graph_t* graph = init_graph();

    // add_graph_node(graph, "Pencho");
    // add_graph_node(graph, "Gencho");
    // add_graph_node(graph, "Penka");

    // connect_nodes(
    //     find_node_by_name(graph, "Pencho"),
    //     find_node_by_name(graph, "Gencho")
    // );
    // connect_nodes(
    //     find_node_by_name(graph, "Gencho"),
    //     find_node_by_name(graph, "Penka")
    // );
    // connect_nodes(
    //     find_node_by_name(graph, "Pencho"),
    //     find_node_by_name(graph, "Penka")
    // );

    // print_graph(graph);

    // char* input_data[] = {
    //     "3",
    //     "Pencho Gencho Penka",
    //     "0 1 1",
    //     "1 0 1",
    //     "1 1 0"
    // };

    // graph_t* graph = init_graph_from_strings(input_data);
    graph_t* graph = init_graph();

    add_graph_node(graph, "1");
    add_graph_node(graph, "2");
    add_graph_node(graph, "3");
    add_graph_node(graph, "4");
    add_graph_node(graph, "5");

    connect_nodes(
        find_node_by_name(graph, "1"),
        find_node_by_name(graph, "2")
    );
    connect_nodes(
        find_node_by_name(graph, "1"),
        find_node_by_name(graph, "3")
    );
    connect_nodes(
        find_node_by_name(graph, "2"),
        find_node_by_name(graph, "4")
    );
    connect_nodes(
        find_node_by_name(graph, "2"),
        find_node_by_name(graph, "5")
    );
    connect_nodes(
        find_node_by_name(graph, "3"),
        find_node_by_name(graph, "5")
    );

    // print_graph(graph);

    graph_span_tree(graph, "1");

    return 0;
}
