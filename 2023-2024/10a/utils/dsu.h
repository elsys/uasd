
#ifndef DSU_H
#define DSU_H

typedef struct Subset
{
    int parent;
    int rank;
} Subset;

int Find(Subset *subsets, int i);
void Union(Subset *subsets, int src, int dest);

#endif