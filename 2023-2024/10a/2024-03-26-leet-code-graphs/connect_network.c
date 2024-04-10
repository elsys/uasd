// https://leetcode.com/problems/number-of-operations-to-make-network-connected/description/

typedef struct VertexNode
{
    int val;
    int weight;
    struct VertexNode *next;
} VertexNode;

typedef struct Graph
{
    int numVertices;
    VertexNode **adjList;
} Graph;

VertexNode *init_node(int val)
{
    VertexNode *node = (VertexNode *)malloc(sizeof(VertexNode));
    node->val = val;
    node->next = NULL;

    return node;
}

Graph *init_graph(int numVertices)
{
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    graph->adjList = (VertexNode **)calloc(numVertices, sizeof(VertexNode *));

    return graph;
}

void addEdgeDirectional(Graph *graph, int from, int to)
{
    if (from < 0 || from >= graph->numVertices || to < 0 || to >= graph->numVertices)
    {
        printf("Invalid from or to\n");
        return;
    }

    VertexNode *newNode = init_node(to);

    newNode->next = graph->adjList[from];
    graph->adjList[from] = newNode;
}

void addEdge(Graph *graph, int from, int to)
{
    addEdgeDirectional(graph, from, to);
    addEdgeDirectional(graph, to, from);
}

void dfs(Graph *g, int current, int *visited)
{
    if (visited[current])
    {
        return;
    }
    visited[current] = 1;
    VertexNode *it = g->adjList[current];
    while (it != NULL)
    {
        dfs(g, it->val, visited);
        it = it->next;
    }
}

int makeConnected(int n, int **connections, int connectionsSize, int *connectionsColSize)
{
    if (connectionsSize < n - 1)
    {
        return -1;
    }
    Graph *g = init_graph(n);
    for (int i = 0; i < connectionsSize; i++)
    {
        addEdge(g, connections[i][0], connections[i][1]);
    }

    int connectedComponents = 0;
    int *visited = (int *)calloc(n, sizeof(int));
    for (int i = 0; i < n; i++)
    {
        if (visited[i] != 1)
        {
            dfs(g, i, visited);
            connectedComponents++;
        }
    }

    return connectedComponents - 1;
}