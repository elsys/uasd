#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef struct Graph {
    int vertexCount;
    int** adjMatrix;
} Graph;

Graph* initGraph(int vertexCount) {
    Graph* graph = (Graph*) malloc(sizeof(Graph));
    graph->vertexCount = vertexCount;
    graph->adjMatrix = (int**) malloc(sizeof(int*) * vertexCount);

    for(int i = 0; i < vertexCount; i++) {
        graph->adjMatrix[i] = (int*) calloc(vertexCount, sizeof(int));
    }

    return graph;
}

void printGraph(Graph* graph) {
    printf("# ");
    for(int i = 0; i < graph->vertexCount; i++) {
        printf("%d ", i);
    }
    printf("\n");
    for(int i = 0; i < graph->vertexCount; i++) {
        printf("%d ", i);
        for(int j = 0; j < graph->vertexCount; j++) {
            printf("%d ", graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

void addEdgeDirectional(Graph* graph, int from, int to, int weight) {
    graph->adjMatrix[from][to] = weight;
}

void addEdge(Graph* graph, int vertex1, int vertex2, int weight) {
    addEdgeDirectional(graph, vertex1, vertex2, weight);
    addEdgeDirectional(graph, vertex2, vertex1, weight);
}

int hasEdge(Graph* graph, int from, int to) {
    return graph->adjMatrix[from][to];
}

int getInDegree(Graph* graph, int vertex) {
    int count = 0;
    for(int i = 0; i < graph->vertexCount; i++) {
        count += graph->adjMatrix[i][vertex];
    }
    return count;
}

int getOutDegree(Graph* graph, int vertex) {
    int count = 0;
    for(int i = 0; i < graph->vertexCount; i++) {
        count += graph->adjMatrix[vertex][i];
    }
    return count;
}

int minDistIndex(int* dist, int* visited, int size) {
    int min = INT_MAX;
    int minIndex;

    for (int v = 0; v < size; v++) {
        if (!visited[v] && dist[v] < min) {
            min = dist[v];
            minIndex = v;
        }
    }

    return minIndex;
}

void prims(Graph* graph) {
    int startNode = 0;
    int* visited = (int*)calloc(graph->vertexCount, sizeof(int));
    int* dist = (int*)malloc(graph->vertexCount * sizeof(int));
    int* parent = (int*)calloc(graph->vertexCount, sizeof(int));

    for(int i = 0; i < graph->vertexCount; i++) {
        dist[i] = INT_MAX;
    } 
    dist[startNode] = 0;

    for(int i = 0; i < graph->vertexCount; i++) {
        int u = minDistIndex(dist, visited, graph->vertexCount);

        visited[u] = 1;
        for(int v = 0; v < graph->vertexCount; v++) {
            if(!visited[v] && graph->adjMatrix[u][v] != 0 && dist[v] > graph->adjMatrix[u][v]) {
                dist[v] = graph->adjMatrix[u][v];
                parent[v] = u;
            }
        }
    }


    for(int i = 0; i < graph->vertexCount; i++) {
        if(dist[i] == INT_MAX) {
            dist[i] = -1; 
        }
        printf("%d: %d \t Path: ", i, dist[i]);

        if (dist[i] != -1) {
            int* path = (int*)malloc(sizeof(int) * graph->vertexCount);
            int pathIndex = 0;
            int currentVertex = i;

            while (currentVertex != startNode) {
                path[pathIndex++] = currentVertex;
                currentVertex = parent[currentVertex];
            }
            path[pathIndex++] = startNode;

            for (int j = pathIndex - 1; j >= 0; j--) {
                printf("%d", path[j]);
                if (j > 0) {
                    printf(" -> ");
                }
            }
            printf("\n");
            free(path);
        } else {
            printf("Unreachable\n");
        }
    }
    int sum = 0;
    for(int i = 0; i < graph->vertexCount; i++) {
        if(dist[i] > 0) {
            sum += dist[i];
        }
    }
    printf("Total weight: %d\n", sum);
}

int main() {
    Graph* graph = initGraph(8);
    
    addEdge(graph, 0, 1, 5);
    addEdge(graph, 0, 4, 4);
    addEdge(graph, 1, 3, 4);
    addEdge(graph, 2, 4, 2);
    addEdge(graph, 2, 5, 6);
    addEdge(graph, 3, 5, 8);
    addEdge(graph, 4, 6, 1);
    addEdge(graph, 4, 7, 9);
    addEdge(graph, 5, 6, 1);
    addEdge(graph, 6, 7, 7);


    // int matrix[][9] = {
    //     {0, 4 , 0, 0 , 0 , 0 , 0, 8 , 0},  
    //     {4, 0 , 8, 0 , 0 , 0 , 0, 11, 0}, 
    //     {0, 8 , 0, 7 , 0 , 4 , 0, 0 , 0},
    //     {0, 0 , 7, 0 , 9 , 14, 0, 0 , 0}, 
    //     {0, 0 , 0, 9 , 0 , 10, 0, 0 , 0}, 
    //     {0, 0 , 4, 14, 10, 0 , 2, 0 , 0},
    //     {0, 0 , 0, 0 , 0 , 2 , 0, 1 , 0},  
    //     {8, 11, 0, 0 , 0 , 0 , 1, 0 , 0}, 
    //     {0, 0 , 2, 0 , 0 , 0 , 6, 7 , 0}
    // };

    // for (int i = 0; i < 9; i++) {
    //     for (int j = 0; j < 9; j++) {
    //         if (matrix[i][j] != 0) {
    //             addEdgeDirectional(graph, i, j, matrix[i][j]); 
    //         }
    //     }
    // }

    prims(graph);

    // printGraph(graph);

    // int testNode = 4;
    // printf("%d in:%d\n", testNode, getInDegree(graph, testNode));
    // printf("%d in:%d\n", testNode, getOutDegree(graph, testNode));
}