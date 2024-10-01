#include "dsu.h"

int Find(Subset *subsets, int i)
{
    if (subsets[i].parent == i)
    {
        return i;
    }

    return Find(subsets, subsets[i].parent);
}

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