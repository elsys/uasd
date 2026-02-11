#include "../utils/graph.h"

int main() {
    Graph* g = init_graph(5);
 
    addEdge(g, 0,4);
    addEdge(g, 0,1);
    addEdge(g, 1,4);
    addEdge(g, 3,4);
    addEdge(g, 1,2);
    addEdge(g, 1,3);
    addEdge(g, 3,2);
 
    printGraph(g);
 
 
    return 0;

}