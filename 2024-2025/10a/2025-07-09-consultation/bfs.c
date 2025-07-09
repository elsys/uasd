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

typedef struct QNode
{
    void* val;
    struct QNode *next;
} QNode;

typedef struct Queue
{
    QNode *front;
    QNode *rear;
} Queue;


QNode *create_qnode(void* val)
{
    QNode *node = (QNode *)malloc(sizeof(QNode));
    node->val = val;
    node->next = NULL;

    return node;
}

Queue *init_queue()
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    
    return queue;
}

void enqueue(Queue *queue, void* val)
{
    QNode *node = create_qnode(val);
    if (queue->front == NULL)
    {
        queue->rear = queue->front = node;
        return;
    }

    queue->rear->next = node;
    queue->rear = node;
}

void* dequeue(Queue *queue)
{
    if (queue->front == NULL)
    {
        printf("Queue is empty.\n");
        exit(1);
    }

    QNode *front = queue->front;

    void* val = front->val;
    QNode *tmp = front;
    queue->front = front->next;
    free(tmp);

    if (queue->front == NULL)
    {
        queue->rear = NULL;
    }

    return val;
}

void clear_queue(Queue *queue)
{
    while (queue->front != NULL)
    {
        dequeue(queue);
    }

    free(queue);
}
void print_queue(Queue *queue)
{
    QNode *it = queue->front;
    printf("Q: ");
    while (it != NULL)
    {
        printf("%p -> ", it->val);
        it = it->next;
    }
    printf("NULL\n");
}

void enqueueInt(Queue *queue, int val) {
    int *val_ptr = (int *)malloc(sizeof(int));
    *val_ptr = val;
    enqueue(queue, val_ptr);
}
int dequeueInt(Queue *queue) {
    int* val_ptr = (int*)dequeue(queue);
    return *val_ptr;
}


bool bfs(Graph* g, int start, int end) {
    int *visited = (int*)calloc(sizeof(int),26);
    Queue* q = init_queue();
    enqueueInt(q, start);

    //printf("%d\n", q->front ==NULL );
    while (q->front != NULL) {
        //printf("%d %d\n", current ,end);
        int current = dequeueInt(q);
        visited[current] = true;
        if (current == end) {
            return true;
        }

        Vertex* it = g->adjList[current];
        while(it != NULL) {
            if (!visited[it->val]) {
                enqueueInt(q, it->val);
            }

            it = it->next;
        }
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
            if(bfs(g, equations[i][0] - 'a', equations[i][3] - 'a')) {
                return false;
            }
        }
    }

    return true;
}

