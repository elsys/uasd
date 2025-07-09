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

typedef struct StackNode
{
    void* val;
    struct StackNode *next;
} StackNode;

typedef struct Stack
{
    StackNode *top;
} Stack;



Stack *init_stack()
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->top = NULL;
    
    return stack;
}

StackNode* create_node(void* val) {
    StackNode *node = (StackNode*)malloc(sizeof(StackNode));
    node->val = val;
    node->next = NULL;
    
    return node;
}

void push(Stack *stack, void* val)
{
    StackNode *node = create_node(val);
    node->next = stack->top;
    stack->top = node;
}

void* pop(Stack *stack)
{
    if (stack->top == NULL)
    {
        printf("Stack is empty.\n");
        exit(1);
    }

    void* val = stack->top->val;
    StackNode *tmp = stack->top;
    stack->top = stack->top->next;
    free(tmp);

    return val;
}

void clear_stack(Stack *stack)
{
    while (stack->top != NULL)
    {
        pop(stack);
    }

    free(stack);
}


void pushInt(Stack *stack, int val) {
    int *val_ptr = (int *)malloc(sizeof(int));
    *val_ptr = val;
    push(stack, val_ptr);
}
int popInt(Stack *stack) {
    int* val_ptr = (int*)pop(stack);
    return *val_ptr;
}

bool bfs(Graph* g, int start, int end) {
    int *visited = (int*)calloc(sizeof(int),26);
    Stack* s = init_stack();
    pushInt(s, start);

    //printf("%d\n", q->front ==NULL );
    while (s->top != NULL) {
        //printf("%d %d\n", current ,end);
        int current = popInt(s);
        visited[current] = true;
        if (current == end) {
            return true;
        }

        Vertex* it = g->adjList[current];
        while(it != NULL) {
            if (!visited[it->val]) {
                pushInt(s, it->val);
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

