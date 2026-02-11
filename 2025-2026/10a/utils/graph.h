#ifndef _GRAPH_H_
#define _GRAPH_H_

typedef struct EdgeNode {
    int val;
    struct EdgeNode* next;
} EdgeNode;
 
typedef struct Graph {
    int numVertices;
    EdgeNode** adjList;
} Graph;

EdgeNode* init_edgenode(int val);
Graph* init_graph(int numVertices);
void addEdgeDirectional(Graph* g, int start, int end);
void addEdge(Graph* g, int start, int end);
void printGraph(Graph* g);

#endif