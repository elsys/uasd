#include <stdio.h>
#include "../utils/graph_matrix.h"
#include <stdbool.h>
#include <stdlib.h>

bool is_euler(Graph *g)
{
    int oddDegreeVertices = 0;

    for (int i = 0; i < g->numVertices; i++)
    {
        int numNeighbors = 0;

        for (int j = 0; j < g->numVertices; j++)
        {
            if (g->adjMatrix[i][j])
            {
                numNeighbors++;
            }
        }

        if (numNeighbors % 2 == 1)
        {
            oddDegreeVertices++;
        }
    }

    return oddDegreeVertices == 0 || oddDegreeVertices == 2;
}

void find_euler_path(Graph *g, int start)
{
    printf("%d ", start);

    for (int i = 0; i < g->numVertices; i++)
    {
        if (g->adjMatrix[start][i])
        {
            g->adjMatrix[start][i] = 0;
            g->adjMatrix[i][start] = 0;
            find_euler_path(g, i);
        }
    }
}

bool is_hamilton_r(Graph *g, int *visited, int visitedCount, int start)
{
    if (visitedCount == g->numVertices)
    {
        return true;
    }

    for (int i = 0; i < g->numVertices; i++)
    {
        if (!visited[i] && g->adjMatrix[start][i])
        {
            visited[i] = 1;
            visitedCount++;
            if (is_hamilton_r(g, visited, visitedCount, i))
            {
                return true;
            }
            visited[i] = 0;
            visitedCount--;
        }
    }

    return false;
}

//
bool is_hamilton(Graph *g)
{
    int *visited = (int *)calloc(g->numVertices, sizeof(int));
    int start = 0;
    int visitedCount = 1;
    visited[0] = 1;

    return is_hamilton_r(g, visited, visitedCount, start);
}

int main()
{
    Graph *g = init_graph(4);

    addEdge(g, 0, 1);
    addEdge(g, 1, 2);
    addEdge(g, 1, 3);
    addEdge(g, 2, 3);

    // if (is_euler(g))
    // {
    //     printf("Is euler");
    //     find_euler_path(g, 0);
    // }
    // else
    // {
    //     printf("Is not");
    // }

    if (is_hamilton(g))
    {
        printf("is hamilton");
    }
    else
    {
        printf("is not");
    }

    return 0;
}