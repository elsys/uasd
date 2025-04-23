#include <stdio.h>
#include <stdlib.h>

typedef struct Set {
    struct Set* parent;
    int rank;
} Set;

Set* find(Set* set) {
    if(set == set->parent) {
        return set;
    }
    return find(set->parent);
}

void set_union(Set* set1, Set* set2) {
    Set* root1 = find(set1);
    Set* root2 = find(set2);

    if (root1->rank < root2->rank) {
        root1->parent = root2;
    } else {
        root2->parent = root1;
        if(root2->rank == root1->rank) {
            root1->rank++;
        }
    }
}

typedef struct Edge {
    int from;
    int to;
    int weight;
} Edge;

int compare(const void* a, const void* b) {
    Edge* a_edge = (Edge*)a;
    Edge* b_edge = (Edge*)b;

    return a_edge->weight - b_edge->weight;
}

void Kruskal(Edge edges[], int E, int V) {
    qsort(edges, E, sizeof(Edge), compare);

    Edge* result = (Edge*)malloc(sizeof(Edge)*(V-1));
    Set** sets = (Set**)malloc(sizeof(Set*)*V);

    for(int i = 0; i < V; i++) {
        Set* set = (Set*)malloc(sizeof(Set));
        set->parent = set;
        set->rank = 0;
        sets[i] = set;
    }

    int k = 0;
    for(int i = 0; i < E; i++) {
        Set* root1 = find(sets[edges[i].from]);
        Set* root2 = find(sets[edges[i].to]);

        if (root1 == root2) {
            continue;
        }

        result[k++] = edges[i];
        set_union(root1, root2);

        if (k == V-1) {
            break;
        }
    }

    printf("Result:\n");
    for (int i = 0; i < V-1; i++) {
        printf("%d. from %d to %d w %d\n", i, result[i].from, result[i].to, result[i].weight);
    }
}

int main() {
    Kruskal(
        (Edge[]){
            (Edge){0, 1, 8},
            (Edge){1, 2, 7},
            (Edge){3, 0, 4},
            (Edge){4, 1, 2},
            (Edge){5, 2, 9},
            (Edge){6, 3, 8},
            (Edge){6, 0, 11},
            (Edge){6, 4, 7},
            (Edge){7, 6, 1},
            (Edge){7, 4, 6},
            (Edge){8, 7, 2},
            (Edge){8, 1, 4},
            (Edge){8, 2, 14},
            (Edge){8, 5, 10},
        }
        , 14, 9
    );

    return 0;
}