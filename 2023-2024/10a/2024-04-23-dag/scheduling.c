//
// https://leetcode.com/problems/course-schedule-ii/submissions/1239639068/?envType=study-plan-v2&envId=top-interview-150

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

void printGraph(Graph *graph)
{
    for (int i = 0; i < graph->numVertices; i++)
    {
        VertexNode *current = graph->adjList[i];
        printf("Neighbours of %d:\n", i);
        while (current != NULL)
        {
            printf("%d ", current->val);
            current = current->next;
        }
        printf("\n");
    }
}

// Kahn's algorithm
bool canFinish(int numCourses, int **prerequisites, int prerequisitesSize, int *prerequisitesColSize, int *returnSize)
{
    Graph *graph = init_graph(numCourses);
    int *inDegrees = (int *)calloc(numCourses, sizeof(int));
    for (int i = 0; i < prerequisitesSize; i++)
    {
        addEdgeDirectional(graph, prerequisites[i][0], prerequisites[i][1]);
        inDegrees[prerequisites[i][1]]++;
    }

    // find with 0 degree
    int *queue = (int *)malloc(numCourses, sizeof(int));
    int front = 0, rear = 0;

    for (int i = 0; i < numCourses; i++)
    {
        if (inDegrees[i] == 0)
        {
            queue[rear++] = i;
        }
    }

    // O(V + E)
    int *result = (int *)malloc(numCourses, sizeof(int));
    int idx = 0;
    while (front != rear)
    {
        int start = queue[front++];
        result[idx++] = start;
        // delete
        Node *it = graph->adjList[start];
        while (it != NULL)
        {
            // reduce
            inDegrees[it->val]--;
            if (inDegrees[it->val] == 0)
            {
                // insert
                queue[rear++] = it->val;
            }
            it = it->next;
        }
    }

    if (idx == numCourses)
    {
        *returnSize = numCourses;
        return result;
    }
    else
    {
        int empty[0];
        *returnSize = 0;
        return empty;
    }
}