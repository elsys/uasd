#include<stdio.h>
#include<stdlib.h>

struct Node {
    int val;
    struct Node* next;
};

typedef struct Node Node;

typedef struct Graph {
    int nodeCount;
    Node** adjList;
} Graph;

Node* initNode(int val) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if(!newNode) {
        exit(1);
    }
    newNode->val = val;
    newNode->next = NULL;

    return newNode;
}

Graph* initGraph(int nodeCount) {
    Graph* newGraph = (Graph*) malloc(sizeof(Graph));
    if(!newGraph) {
        exit(1);
    }
    newGraph->nodeCount = nodeCount;
    newGraph->adjList = (Node**) calloc(nodeCount, sizeof(Node*));
    if(!newGraph->adjList) {
        exit(1);
    }
    return newGraph;
}

void addEdgeDirectional(Graph* graph, int from, int to) {
    Node* newNode = initNode(to);
    newNode->next = graph->adjList[from];
    graph->adjList[from] = newNode;
}

void addEdge(Graph* graph, int node1, int node2) {
    addEdgeDirectional(graph, node1, node2);
    addEdgeDirectional(graph, node2, node1);
}

void printGraph(Graph* graph) {
    
    for(int i = 0; i < graph->nodeCount; i++) {
        printf("Neighbors of %d: ", i);
        Node* curr = graph->adjList[i];
        while(curr) {
            printf("%d ", curr->val);
            curr = curr->next;
        }
        printf("\n");
    }
}

int hasEdge(Graph* graph, int from, int to) {
    Node* curr = graph->adjList[from];
    while(curr) {
        if(curr->val == to) {
            return 1;
        } 
    }
    return 0;
}

int getInDegree(Graph* graph, int node) {
    int count = 0;
    for(int i = 0; i < graph->nodeCount; i++) {
        if(i == node) {
            continue;
        }
        count += hasEdge(graph, i, node);
    }
    return count;
}

int getOutDegree(Graph* graph, int node) {
    int count = 0;
    Node* curr = graph->adjList[node];
    while(curr) {
        count++;
    }
    return count;
}

int main() {
    Graph* graph = initGraph(6);
    addEdgeDirectional(graph, 0, 5);
    addEdgeDirectional(graph, 4, 0);
    addEdge(graph, 0, 3);
    addEdge(graph, 4, 3);
    addEdge(graph, 1, 5);
    addEdge(graph, 4, 1);
    addEdge(graph, 4, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 5, 2);

    printGraph(graph);
}