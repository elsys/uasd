int* findOrder(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize, int* returnSize) {
    int *inDegrees = (int*)calloc(sizeof(int),numCourses);
 
    for (int i = 0; i < prerequisitesSize; i++) {
        inDegrees[prerequisites[i][0]]++;
    }
 
    Queue* q = init_queue();
    int *result = (int*)malloc(sizeof(int)*numCourses);
    int index = 0;
    for (int i = 0; i < numCourses; i++) {
        if (inDegrees[i] == 0) {
            enqueue(q, i);
        }
    }
 
    while (q->front != NULL) {
        int current = dequeue(q);
        result[index] = current;
        index++;
 
        for (int i = 0; i < prerequisitesSize; i++) {
            if (prerequisites[i][1] == current) {
                inDegrees[prerequisites[i][0]]--;
                if (inDegrees[prerequisites[i][0]] == 0) {
                    enqueue(q, prerequisites[i][0]);
                }
            }
        }
    }
 
    if (index < numCourses - 1) {
        *returnSize = 0;
        return result;
    }
    *returnSize = numCourses;
    return result;
}