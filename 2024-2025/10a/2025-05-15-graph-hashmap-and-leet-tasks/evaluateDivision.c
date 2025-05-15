// https://leetcode.com/problems/evaluate-division/
// use graph with hashmap

double evaluateDiv(Graph *g, char* start, char* end, HashMap* visited, double accum) {
    if (strcmp(start, end) == 0) {
        return accum;
    }
    if (get(visited, start) != NULL) {
        return -1;
    }
    set(visited, start, (void*)1);
    //printf("%s\n",start);

    Vertex* it = (Vertex*)get(g->adjList, start);
    while(it != NULL) {
        double res = evaluateDiv(g, it->val, end, visited, accum * it->weight);
        if (res != -1) {
            return res;
        }

        it = it->next;
    }

    return -1;
}

/**
 * Note:H The returned array must be malloced, assume caller calls free().
 */
double* calcEquation(char*** equations, int equationsSize, int* equationsColSize, 
double* values, int valuesSize, 
char*** queries, int queriesSize, int* queriesColSize, 
int* returnSize) {
    Graph* g = init_graph();

    for(int i = 0; i < equationsSize; i++) {
        addEdgeDirectional(g, equations[i][0], equations[i][1], values[i]);
        addEdgeDirectional(g, equations[i][1], equations[i][0], 1/values[i]);
    }
    
    double* res = (double*)malloc(sizeof(double)*queriesSize);
    *returnSize = queriesSize;

    for(int i = 0; i < queriesSize; i++) {
        HashMap* visited = init_hashmap();
        if (get(g->adjList, queries[i][0]) == NULL || get(g->adjList, queries[i][1]) == NULL) {
            res[i] = -1;
            continue;
        }

        res[i] = evaluateDiv(g, queries[i][0], queries[i][1], visited, 1);
    }

    return res;
}