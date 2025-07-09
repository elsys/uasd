typedef struct Vertex {
    int val;
    double weight;
    struct Vertex* next;
} Vertex;

typedef struct Graph {
    int numVertices;
    Vertex **adjList;
} Graph;

Vertex* init_vertex(int val, int weight) {
    Vertex* vertex = (Vertex*)malloc(sizeof(Vertex));
    vertex->val = val;
    vertex->weight = weight;
    vertex->next = NULL;

    return vertex;
}

Graph* init_graph(int numVertices) {
    Graph *graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    graph->adjList = (Vertex**)calloc(numVertices, sizeof(Vertex*));

    return graph;
}

void addEdgeDirectional(Graph*graph, int from, int to, double weight) {
    Vertex* new_vertex = init_vertex(to, weight);
    new_vertex->next = graph->adjList[from];
    graph->adjList[from] = new_vertex;
}

void addEdge(Graph* graph, int from, int to, double weight) {
    addEdgeDirectional(graph, from, to, weight);
    addEdgeDirectional(graph, to, from, weight);
}

void printGraph(Graph *graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        Vertex* it = graph->adjList[i];
        printf("Neighbors of %d: ", i);
        while (it != NULL)
        {
            printf("%d ", it->val);
            it = it->next;
        }
        printf("\n");
    }
}

bool dfs(Graph* g, int current, int end, int* visited) {
    if (current == end) {
        return true;
    }

    Vertex *it = g->adjList[current];
    visited[current] = true;
    while(it != NULL) {
        if (!visited[it->val]) {
            bool res = dfs(g, it->val, end, visited);
            if (res) {
                return true;
            }
        }

        it = it->next;
    }

    return false;
}

bool equationsPossible(char** equations, int equationsSize) {
    Graph* g = init_graph(26);

    for (int i = 0; i < equationsSize; i++) {
        if (equations[i][1] == '=') {
            addEdge(g, equations[i][0] - 'a', equations[i][3] - 'a', 1);
        }
    }

    for (int i = 0; i < equationsSize; i++) {
        if (equations[i][1] == '!') {
            int *visited = (int*)calloc(sizeof(int),26);
            if(dfs(g, equations[i][0] - 'a', equations[i][3] - 'a', visited)) {
                return false;
            }
        }
    }

    return true;
}
