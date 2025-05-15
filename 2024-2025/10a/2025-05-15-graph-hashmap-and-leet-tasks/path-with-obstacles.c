
//https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/
// must use pqNode

typedef struct Entry {
    int x;
    int y;
    int elims;
    int dist;
} Entry;


int h(int x, int y, int nx, int ny) {
    return abs(x - nx) + abs(y - ny);
}

int shortestPath(int** grid, int gridSize, int* gridColSize, int k) {
    int m = gridSize;
    int n = gridColSize[0];

    int***visited = (int***)malloc(sizeof(int**)*m);
    for (int i = 0; i < m; i++) {
        visited[i] = (int**)malloc(sizeof(int*)*n);
        for (int j = 0;j < n; j++) {
            visited[i][j] = (int*)calloc(sizeof(int),k + 1);
        }
    }

    PQueue *pq = init_pq();
    Entry* start = (Entry*)malloc(sizeof(Entry));
    *start = (Entry){0,0,0,0};
    pqInsert(pq, start, 0);

    // Проблемът беше, че бях изпуснал това visited 
    visited[0][0][0] = 1;
    //
    int dx[4] = {0,0,-1,1};
    int dy[4] = {-1,1,0,0};

    while(pq->size > 0) {
        Entry* e = (Entry*)(deleteMin(pq)->data);
        //printf("%d %d %d \n", e->x, e->y, e->elims);

        if (e->x == m-1 && e->y == n-1) {
            return e->dist;
        }

        for (int i = 0; i < 4; i++) {
            int nx = e->x + dx[i];
            int ny = e->y + dy[i];

            if (nx < 0 || nx >= m || ny < 0 || ny >= n) {
                continue;
            }
            int newElims = e->elims + grid[nx][ny];
            if (newElims > k || visited[nx][ny][newElims] != 0) {
                continue;
            }
            visited[nx][ny][newElims] = 1;

            Entry* newEntry = (Entry*)malloc(sizeof(Entry));
            *newEntry = (Entry){nx, ny, newElims, e->dist + 1}; 
            pqInsert(pq, newEntry, e->dist + 1 + h(nx, ny, m-1, n-1));
        }

        
    }

    return -1;
}