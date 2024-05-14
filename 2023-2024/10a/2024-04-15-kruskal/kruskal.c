#include <stdio.h>
#include <stdlib.h>

// Structure to represent an edge in the graph
typedef struct Edge
{
    int src;
    int dest;
    int weight;
} Edge;

typedef struct Subset
{
    int parent;
} Subset;

// Find set of an element i
int find(struct Subset subsets[], int i)
{
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

void Union(struct Subset subsets[], int x, int y)
{
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    subsets[yroot].parent = xroot;
}

int compare(const void *a, const void *b)
{
    Edge *edge1 = (Edge *)a;
    Edge *edge2 = (Edge *)b;
    return edge1->weight - edge2->weight;
}

// Function to construct MST using Kruskal's algorithm
void KruskalMST(int V, int E, struct Edge edges[])
{
    Edge *result = (Edge *)malloc(V * sizeof(Edge)); // Stores the result MST
    int e = 0;                                       // Index variable for result[]
    qsort(edges, E, sizeof(edges[0]), compare);

    Subset *subsets = (Subset *)malloc(V * sizeof(Subset));
    for (int i = 0; i < V; i++)
    {
        subsets[i] = (Subset){i};
    }

    for (int i = 0; i < E; i++)
    {
        int p1 = find(subsets, edges[i].src);
        int p2 = find(subsets, edges[i].dest);

        if (p1 == p2)
        {
            continue;
        }

        result[e++] = edges[i];

        if (e == V)
        {
            break;
        }
    }

    for (int i = 0; i < V; i++)
    {
        printf("%d-%d %d\n", result[i].src, result[i].dest, result[i].weight);
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

    KruskalMST(V, E, edges);

    return 0;
}