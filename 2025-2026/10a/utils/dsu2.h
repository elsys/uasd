#ifndef _DSU2_H_
#define _DSU2_H_

typedef struct Set {
    struct Set *parent;
    int rank;
} Set;

Set** init_sets(int size);
Set* find2(Set* set);
void union_sets2(Set* set1, Set* set2);
void free_set(Set* set);
void free_sets(Set** sets, int size);
#endif