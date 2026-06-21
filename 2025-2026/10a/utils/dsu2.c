//implement disjoint set union (DSU) data structure
#include "dsu2.h"
#include <stdlib.h>

Set** init_sets(int size) {
    Set** sets = (Set**)malloc(sizeof(Set*) * size);
    for (int i = 0; i < size; i++) {
        sets[i] = (Set*)malloc(sizeof(Set));
        sets[i]->parent = sets[i];
        sets[i]->rank = 0;
    }

    return sets;
}

Set* find2(Set* set) {
    if (set->parent != set) {
        set->parent = find2(set->parent);
    }
    return set->parent;
}

void union_sets2(Set* set1, Set* set2) {
    Set* root1 = find2(set1);
    Set* root2 = find2(set2);

    if (root1 != root2) {
        if (root1->rank < root2->rank) {
            root1->parent = root2;
        } else if (root1->rank > root2->rank) {
            root2->parent = root1;
        } else {
            root2->parent = root1;
            root1->rank++;
        }
    }
}

void free_set(Set* set) {
    if (set == NULL) {
        return;
    }

    free_set(set->parent);
    free(set);
}

void free_sets(Set** sets, int size) {
    for (int i = 0; i < size; i++) {
        free_set(sets[i]);
    }
    free(sets);
}