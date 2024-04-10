// https://leetcode.com/problems/network-delay-time/description/

typedef struct VertexNode
{
    int val;
    int w;
    struct VertexNode *next;
} VertexNode;

typedef struct Graph
{
    int numVertices;
    VertexNode **adjList;
} Graph;

VertexNode *init_node(int val, int w)
{
    VertexNode *node = (VertexNode *)malloc(sizeof(VertexNode));
    node->val = val;
    node->next = NULL;
    node->w = w;

    return node;
}

Graph *init_graph(int numVertices)
{
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    graph->adjList = (VertexNode **)calloc(numVertices, sizeof(VertexNode *));

    return graph;
}

void addEdgeDirectional(Graph *graph, int from, int to, int w)
{
    if (from < 0 || from >= graph->numVertices || to < 0 || to >= graph->numVertices)
    {
        printf("Invalid from or to\n");
        return;
    }

    VertexNode *newNode = init_node(to, w);

    newNode->next = graph->adjList[from];
    graph->adjList[from] = newNode;
}

void addEdge(Graph *graph, int from, int to, int w)
{
    addEdgeDirectional(graph, from, to, w);
    addEdgeDirectional(graph, to, from, w);
}

int extract_min(int *dist, int *visited, int n)
{
    int min = INT_MAX;
    int min_index = -1;
    for (int i = 0; i < n; i++)
    {
        if (visited[i])
        {
            continue;
        }
        if (min > dist[i])
        {
            min = dist[i];
            min_index = i;
        }
    }

    return min_index;
}

void djikstra(Graph *g, int *dist, int *visited, int n)
{
    while (true)
    {
        int x = extract_min(dist, visited, n);
        if (x == -1)
        {
            return;
        }
        visited[x] = 1;
        VertexNode *it = g->adjList[x];
        while (it != NULL)
        {
            if (dist[it->val] > dist[x] + it->w)
            {
                dist[it->val] = dist[x] + it->w;
            }
            it = it->next;
        }
    }
}

int networkDelayTime(int **times, int timesSize,
                     int *timesColSize, int n, int k)
{
    Graph *g = init_graph(n);
    for (int i = 0; i < timesSize; i++)
    {
        addEdgeDirectional(g, times[i][0] - 1, times[i][1] - 1,
                           times[i][2]);
    }

    int *dist = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        dist[i] = INT_MAX;
    }
    dist[k - 1] = 0;

    int *visited = (int *)calloc(n, sizeof(int));

    djikstra(g, dist, visited, n);

    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            return -1;
        }
        if (max < dist[i])
        {
            max = dist[i];
        }
    }

    return max;
}