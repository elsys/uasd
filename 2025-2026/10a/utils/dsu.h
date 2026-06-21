#ifndef _DSU_H_
#define _DSU_H_

typedef struct DSU {
    int size;
    int *parent;

    // Ignore rank for now
    int *rank;
} DSU;

DSU* init_dsu(int size);
int find(DSU* dsu, int x);
void union_sets(DSU* dsu, int a, int b);
void free_dsu(DSU* dsu);

#endif