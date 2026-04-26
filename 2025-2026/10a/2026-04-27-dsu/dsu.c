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

}

void union_sets(DSU* dsu, int a, int b) {

}

void free_dsu(DSU* dsu) {
    free(dsu->parent);
    free(dsu->rank);
    free(dsu);
}