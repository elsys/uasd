#include <stdio.h>

#include "graph.h"
#include "list.h"

void demo_list() {
    list_t* my_list = push_list(NULL, (void*)1);
    for(int i = 2; i < 10; i++)
        push_list(my_list, (void*)i);

    printf("List size: %d\n", list_length(my_list));

    while(list_length(my_list) > 3) {
        printf("%d\n", (int)pop_list(&my_list));
    }

    destroy_list(my_list);
}

void demo_graph() {
    graph_edge_t* my_edge = init_graph_edge(1);
    graph_node_t* my_node = init_graph_node("Test");
    graph_t* my_graph = init_graph();

    add_graph_node(my_graph, "test1");
    add_graph_node(my_graph, "test2");
    add_graph_node(my_graph, "test3");
    add_graph_node(my_graph, "test4");
    add_graph_node(my_graph, "test5");

    connect_nodes(
        find_node_by_name(my_graph, "test1"),
        find_node_by_name(my_graph, "test2"),
        1
    );
    connect_nodes(
        find_node_by_name(my_graph, "test1"),
        find_node_by_name(my_graph, "test3"),
        1
    );
    connect_nodes(
        find_node_by_name(my_graph, "test2"),
        find_node_by_name(my_graph, "test4"),
        1
    );
    connect_nodes(
        find_node_by_name(my_graph, "test2"),
        find_node_by_name(my_graph, "test5"),
        1
    );
    connect_nodes(
        find_node_by_name(my_graph, "test3"),
        find_node_by_name(my_graph, "test5"),
        1
    );

    print_graph(my_graph);

    destroy_graph_edge(my_edge);
    destroy_graph_node(my_node);
    destroy_graph(my_graph);
}

int main() {
    // demo_list();
    demo_graph();

    return 0;
}
