#ifndef _GRAPH_H_
#define _GRAPH_H_

typedef struct EdgeNode {
    int val;
    int weight;
    struct EdgeNode* next;
} EdgeNode;
 
typedef struct Graph {
    int numVertices;
    EdgeNode** adjList;
} Graph;

EdgeNode* init_edgenode(int val, int weight);
Graph* init_graph(int numVertices);
void addEdgeDirectional(Graph* g, int start, int end, int weight);
void addEdge(Graph* g, int start, int end, int weight);
void printGraph(Graph* g);

#endif