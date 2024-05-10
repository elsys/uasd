#include <stdio.h>
#include <stdlib.h>

typedef struct Edge
{
    int src;
    int dest;
    float weight;
} Edge;

int compare(const void *a, const void *b)
{
    Edge *e1 = (Edge *)a;
    Edge *e2 = (Edge *)b;

    return e1->weight - e2->weight;
}

typedef struct Subset
{
    int parent;
    int rank;
} Subset;

int Find(Subset *subsets, int i)
{
    if (subsets[i].parent == i)
    {
        return i;
    }

    return Find(subsets, subsets[i].parent);
}

// needs further optimization to be lgn
void Union(Subset *subsets, int src, int dest)
{
    int root1 = Find(subsets, src);
    int root2 = Find(subsets, dest);

    if (subsets[root1].rank < subsets[root2].rank)
    {
        subsets[root1].parent = root2;
    }
    else if (subsets[root1].rank > subsets[root2].rank)
    {
        subsets[root2].parent = root1;
    }
    else
    {
        subsets[root2].parent = root1;
        subsets[root1].rank++;
    }
}

void Kruskal(Edge edges[], int V, int E)
{
    // O(E*lg(E)) = Elg(V^2) = E * 2 * lg(V) = E*lg(V)
    qsort(edges, E, sizeof(Edge), compare);

    Edge *result = (Edge *)malloc((V - 1) * sizeof(Edge));
    int e = 0;
    Subset *subsets = (Subset *)malloc(V * sizeof(Subset));
    // V
    for (int i = 0; i < V; i++)
    {
        subsets[i] = (Subset){i};
    }

    // E * (lgV) , с оптимизация O(E*a(V)) = O(E)
    for (int i = 0; i < E; i++)
    {
        int root1 = Find(subsets, edges[i].src);
        int root2 = Find(subsets, edges[i].dest);

        if (root1 == root2)
        {
            continue;
        }

        result[e++] = edges[i];
        Union(subsets, root1, root2);

        if (e == V - 1)
        {
            break;
        }
    }

    for (int i = 0; i < E; i++)
    {
        printf("%d-%d %f\n", edges[i].dest, edges[i].src, edges[i].weight);
    }
}

int main()
{
    int V = 5;
    int E = 10;
    Edge edges[] = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4},
        {2, 4, 8},
        {3, 4, 10},
        {1, 4, 7},
        {1, 2, 9},
        {3, 4, 10}};

    Kruskal(edges, V, E);
}