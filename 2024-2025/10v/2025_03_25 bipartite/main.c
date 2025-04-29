#include<stdio.h>
#include<stdlib.h>
// #include "./queue.h"

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

// void bfs(Graph* graph, int startNode) {
//     if (startNode < 0 || startNode >= graph->nodeCount) {
//         return;
//     }

//     Queue* q = initQueue();
//     int* visited = (int*) calloc(graph->nodeCount, sizeof(int));
//     int* dist = (int*) calloc(graph->nodeCount, sizeof(int));

//     push(q, startNode);
//     visited[startNode] = 1;
//     dist[startNode] = 0;

//     printf("BFS from %d:\n", startNode);

//     while(q->front) {
//         int val = pop(q);
//         printf("%d ", val);

//         Node* curr = graph->adjList[val];
//         while(curr) {
//             if(!visited[curr->val]) {
//                 push(q, curr->val);
//                 visited[curr->val] = 1;
//                 dist[curr->val] = dist[val] + 1;
//             }
//             curr = curr->next;
//         }
//     }
//     printf("\n");
//     for(int i = 0; i < graph->nodeCount; i++) {
//         if(!visited[i]) {
//             dist[i] = -1;
//         }
//         printf("%d: %d\n", i, dist[i]);
//     }

// }

int isBipartiteHelper(Graph* graph, int startNode, int* colors) {
    int prevColor = colors[startNode];
    int newColor = prevColor == 1 ? 2 : 1;

    // printf("%d ", startNode);

    Node* curr = graph->adjList[startNode];
    while(curr) {
        if(!colors[curr->val]) {
            colors[curr->val] = newColor;
            if(!isBipartiteHelper(graph, curr->val, colors)) {
                return 0;
            }
        } else if (colors[curr->val] != newColor) {
            return 0;
        }
        curr = curr->next;
    }

    return 1;
}

int isBipartite(Graph* graph, int startNode) {
    if (startNode < 0 || startNode >= graph->nodeCount) {
        return 0;
    }
    // printf("DFS from %d:\n", startNode);

    int* colors = (int*) calloc(graph->nodeCount, sizeof(int));
    colors[startNode] = 1;

    return isBipartiteHelper(graph, startNode, colors);
    // printf("\n");
}
// bipartite

int isIsolated(Graph* graph, int node) {
    return !getInDegree(graph, node) && !getOutDegree(graph, node);
}

// int isConnected(Graph* graph) {
//     int* visited = (int*) calloc(graph->nodeCount, sizeof(int));
//     dfsHelper(graph, 0, visited);
//     for(int i = 0; i < graph->nodeCount; i++) {
//         if(!visited[i]) {
//             return 0;
//         }
//     }
//     return 1;
// }

//getConnectedComponentCount(Graph* graph)


int main() {
    Graph* graph = initGraph(5);
    // addEdgeDirectional(graph, 0, 5);
    // addEdgeDirectional(graph, 4, 0);
    // addEdge(graph, 0, 3);
    // addEdge(graph, 0, 5);
    // addEdge(graph, 0, 4);
    // addEdge(graph, 4, 3);
    // addEdge(graph, 1, 5);
    // addEdge(graph, 4, 1);
    // addEdge(graph, 4, 2);
    // addEdge(graph, 1, 2);
    // addEdge(graph, 5, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 3, 2);
    addEdge(graph, 2, 0);
    addEdge(graph, 4, 0);
    addEdge(graph, 4, 3);
    addEdge(graph, 0, 3);





    // printGraph(graph);

    // bfs(graph, 0);
    // dfs(graph, 0);
    printf("%d\n", isBipartite(graph, 0));
}