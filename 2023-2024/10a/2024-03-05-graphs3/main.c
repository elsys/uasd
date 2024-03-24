#include <stdio.h>
#include "../utils/graph.h"
#include <stdbool.h>
#include <stdlib.h>

bool dfs(Graph *g, int *colors, int start_vertex, int next_color)
{
    VertexNode *it = g->adjList[start_vertex];

    // printf("From %d\n", start_vertex);
    while (it != NULL)
    {
        printf("From %d, Looking at %d, has color %d, next %d\n", start_vertex, it->val, colors[it->val], next_color);
        if (colors[it->val] == 0)
        {
            colors[it->val] = next_color;
            if (!dfs(g, colors, it->val, next_color == 1 ? 2 : 1))
            {
                return false;
            }
        }
        else if (colors[it->val] != next_color)
        {
            return false;
        }

        it = it->next;
    }

    return true;
}

bool can_be_two_colored(Graph *g)
{
    int *colors = (int *)calloc(g->numVertices, sizeof(int));

    for (int i = 0; i < g->numVertices; i++)
    {
        if (colors[i] == 0)
        {
            colors[i] = 1;
            if (!dfs(g, colors, 0, 2))
            {
                return false;
            }
        }
    }

    return true;
}

int main()
{
    Graph *g = init_graph(6);
    addEdge(g, 0, 1);
    addEdge(g, 0, 2);
    addEdge(g, 1, 3);
    addEdge(g, 2, 3);
    addEdge(g, 3, 4);
    addEdge(g, 4, 5);
    addEdge(g, 2, 4);

    if (can_be_two_colored(g))
    {
        printf("Is possible\n");
    }
    else
    {
        printf("Is not");
    }

    return 0;
}