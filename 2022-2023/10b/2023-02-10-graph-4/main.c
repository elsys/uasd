#include <stdio.h>
#include <stdlib.h>

#include "vector.h"

struct graph_node_t {
  // struct graph_node_t** connections;
  // int count;

  struct vector_t* connections;
  int visited;
};

void connect_nodes(struct graph_node_t* a, struct graph_node_t* b) {
  vector_add(a->connections, b);
  vector_add(b->connections, a);
}

int find_path_dfs(
  struct graph_node_t* start,
  struct graph_node_t* end
) {
  start->visited = 1;

  for(int i = 0; i < start->connections->size; i++) {
    struct graph_node_t* next =
      vector_get(start->connections, i);

    if(next->visited == 1) continue;
    if(next == end) return 1;

    if(find_path_dfs(next, end) == 1)
      return 1;
  }

  start->visited = 0;
  return 0;
}
/*
int find_path_bfs(
  struct graph_node_t* start,
  struct graph_node_t* end
) {
  struct queue_t* q = init_queue();
  queue_push(q, start);

  while(q->count > 0) {
    struct graph_node_t* curr = queue_pop(q);

    if(curr == end) return 1;

    for(int i = 0; i < curr->connections->count; i++) {
      struct graph_node_t* next =
        vector_get(curr->connections, i);

      if(next->visited == 1) continue;
      queue_push(q, next);
    }
  }

  return 0;
}
*/
int main() {
  /*struct graph_node_t n1;
  struct graph_node_t n2;
  struct graph_node_t n3;
  struct graph_node_t n4;

  connect_nodes(&n1, &n2);
  connect_nodes(&n2, &n3);
  connect_nodes(&n3, &n1);
  connect_nodes(&n3, &n4);*/

  int matrix[7][7] = {
    {0, 1, 0, 0, 0, 1, 0},
    {1, 0, 1, 0, 0, 1, 1},
    {0, 1, 0, 0, 1, 0, 1},
    {0, 0, 0, 0, 1, 1, 1},
    {0, 0, 1, 1, 0, 1, 1},
    {1, 1, 0, 1, 1, 0, 0},
    {0, 1, 1, 1, 1, 0, 0}
  };

  struct vector_t* nodes;
  for(int i = 0; i < 4; i++) {
    struct graph_node_t* new_node = malloc(sizeof(struct graph_node_t));
    vector_add(nodes, new_node);
  }

  for(int i = 1; i < 4; i++) {
    for(int j = 0; j < i; j++) {
      if(matrix[i][j] == 1)
        connect_nodes(
          vector_get(nodes, i),
          vector_get(nodes, j)
        );
    }
  }

  find_path_dfs(
    vector_get(nodes, 4),
    vector_get(nodes, 0)
  );

  /*find_path_bfs(
    vector_get(nodes, 4),
    vector_get(nodes, 0)
  );
*/
  return 0;
}
