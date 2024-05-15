// https://leetcode.com/problems/evaluate-division/

#define HASH_SIZE 8

// Chaining implementation of a hash map
typedef struct EntryNode
{
    char *key;
    void *val;
    struct EntryNode *next;
} EntryNode;

typedef struct HashMap
{
    EntryNode **array;
} HashMap;

EntryNode *init_entry(char *key, void *val)
{
    EntryNode *entry = (EntryNode *)malloc(sizeof(EntryNode));
    entry->key = key;
    entry->val = val;
    entry->next = NULL;

    return entry;
}

HashMap *init_hash_map()
{
    HashMap *map = (HashMap *)malloc(sizeof(HashMap));
    map->array = (EntryNode **)calloc(HASH_SIZE, sizeof(EntryNode *));

    return map;
}

int hash(char *key)
{
    int sum = 0;
    for (int i = 0; key[i] != '\0'; i++)
    {
        sum += key[i];
    }

    return sum % HASH_SIZE;
}

void set(HashMap *hash_map, char *key, void *val)
{
    int index = hash(key);
    EntryNode *entry = init_entry(key, val);

    if (hash_map->array[index] == NULL)
    {
        hash_map->array[index] = entry;
    }
    else
    {
        EntryNode *it = hash_map->array[index];

        while (it != NULL)
        {
            if (strcmp(it->key, key) == 0)
            {
                it->val = val;
                // free entry;
                return;
            }

            if (it->next == NULL)
            {
                break;
            }
            it = it->next;
        }

        it->next = entry;
    }
}

void *get(HashMap *hash_map, char *key)
{
    int index = hash(key);

    if (hash_map->array[index] == NULL)
    {
        return NULL;
    }

    EntryNode *it = hash_map->array[index];

    while (it != NULL)
    {
        if (strcmp(it->key, key) == 0)
        {
            return it->val;
        }
        it = it->next;
    }

    return NULL;
}

typedef struct VertexNode
{
    char *val;
    double weight;
    struct VertexNode *next;
} VertexNode;

typedef struct Graph
{
    HashMap *adjList;
} Graph;

VertexNode *init_node(char *val, double weight)
{
    VertexNode *node = (VertexNode *)malloc(sizeof(VertexNode));
    node->val = strdup(val);
    node->next = NULL;
    node->weight = weight;

    return node;
}

Graph *init_graph()
{
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->adjList = init_hash_map();

    return graph;
}

void addEdgeDirectional(Graph *graph, char *from, char *to, double weight)
{
    VertexNode *newNode = init_node(to, weight);

    newNode->next = get(graph->adjList, from);
    set(graph->adjList, from, newNode);
}

void addEdge(Graph *graph, char *from, char *to, double weight)
{
    addEdgeDirectional(graph, from, to, weight);
    addEdgeDirectional(graph, to, from, weight);
}

// char* strdup(char* str) {
//     char* new_str = (char*)malloc(strlen(str) + 1);
//     strcpy(new_str, str);
//     return new_str;
// }

void printGraph(Graph *graph)
{
    for (int i = 0; i < HASH_SIZE; i++)
    {
        EntryNode *current = graph->adjList->array[i];
        if (current == NULL)
        {
            continue;
        }

        while (current != NULL)
        {
            VertexNode *currentNode = (VertexNode *)current->val;
            printf("Neighbours of %s:\n", current->key);
            while (currentNode != NULL)
            {
                printf("%s(%f) ", currentNode->val, currentNode->weight);
                currentNode = currentNode->next;
            }
            current = current->next;
            printf("\n");
        }
    }
}

double evaluateDivUtil(Graph *g, char *start, char *end, double acc, HashMap *visited)
{
    if (strcmp(start, end) == 0)
    {
        return acc;
    }

    VertexNode *current = (VertexNode *)get(g->adjList, start);
    while (current != NULL)
    {
        if (get(visited, current->val) == NULL)
        {
            set(visited, current->val, (void *)1);
            double res = evaluateDivUtil(g, current->val, end, acc * current->weight, visited);
            if (res != -1)
            {
                return res;
            }

            set(visited, current->val, (void *)NULL);
        }

        current = current->next;
    }

    return -1;
}

double evaluateDiv(Graph *g, char *start, char *end)
{
    HashMap *visited = init_hash_map();
    set(visited, start, (void *)1);

    if (get(g->adjList, start) == NULL || get(g->adjList, end) == NULL)
    {
        return -1;
    }

    return evaluateDivUtil(g, start, end, 1, visited);
}

double *calcEquation(char ***equations, int equationsSize,
                     int *equationsColSize, double *values, int valuesSize,
                     char ***queries, int queriesSize, int *queriesColSize, int *returnSize)
{
    Graph *g = init_graph();
    for (int i = 0; i < equationsSize; i++)
    {
        addEdgeDirectional(g, equations[i][0], equations[i][1], values[i]);
        addEdgeDirectional(g, equations[i][1], equations[i][0], 1 / values[i]);
    }

    *returnSize = queriesSize;
    double *result = (double *)malloc(queriesSize * sizeof(double));

    for (int i = 0; i < queriesSize; i++)
    {
        result[i] = evaluateDiv(g, queries[i][0], queries[i][1]);
    }

    return result;
}
