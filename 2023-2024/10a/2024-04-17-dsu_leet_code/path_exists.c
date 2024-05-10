// https://leetcode.com/problems/find-if-path-exists-in-graph/
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
    }

    bool validPath(int n, int **edges, int edgesSize, int *edgesColSize, int source, int destination)
    {
        Subset *subsets = (Subset *)malloc(n * sizeof(Subset));
        for (int i = 0; i < n; i++)
        {
            subsets[i] = (Subset){i, 0};
        }

        for (int i = 0; i < edgesSize; i++)
        {
            Union(subsets, edges[i][0], edges[i][1]);
        }

        return Find(subsets, source) == Find(subsets, destination);
    }