//implement disjoint set union (DSU) data structure
#include "dsu.h"
#include <stdlib.h>

DSU* init_dsu(int size) {
    DSU* dsu = (DSU*)malloc(sizeof(DSU));
    dsu->size = size;
    dsu->parent = (int*)malloc(sizeof(int) * size);
    dsu->rank = (int*)malloc(sizeof(int) * size);

    for (int i = 0; i < size; i++) {
        dsu->parent[i] = i;
        dsu->rank[i] = 0;
    }

    return dsu;
}

int find(DSU* dsu, int x) {
    if (dsu->parent[x] != x) {
        dsu->parent[x] = find(dsu, dsu->parent[x]);
    }
    return dsu->parent[x];
}

void union_sets(DSU* dsu, int a, int b) {
    int rootA = find(dsu, a);
    int rootB = find(dsu, b);

    // with rank optimization
    if (rootA != rootB) {
        if (dsu->rank[rootA] < dsu->rank[rootB]) {
            dsu->parent[rootA] = rootB;
        } else if (dsu->rank[rootA] > dsu->rank[rootB]) {
            dsu->parent[rootB] = rootA;
        } else {
            dsu->parent[rootB] = rootA;
            dsu->rank[rootA]++;
        }
    }
}

void free_dsu(DSU* dsu) {
    free(dsu->parent);
    free(dsu->rank);
    free(dsu);
}