#include <stdio.h>
#include <stdlib.h>

#include "vector.h"

struct graph_node_t {
  struct vector_t* edges;
  
  // Used by the traversal algorythm
  int visited;
  int weight;
};

struct graph_edge_t {
  int weight;
  struct graph_node_t* a;
  struct graph_node_t* b;
};

void connect_nodes(
  struct graph_node_t* a, 
  struct graph_node_t* b, 
  int weight
) {
  struct graph_edge_t* e = malloc(sizeof(struct graph_edge_t));
  e->weight = weight;
  e->a = a;
  e->b = b;

  vector_add(a->edges, e);
  vector_add(b->edges, e);
}

// TODO:
// - mark nodes as visited
// - do not add visited nodes to the queue
// - handle a weight of -1 in the nodes
// - does the connect_nodes function work correctly?
int find_path_dijkstra(
  struct graph_node_t* start,
  struct graph_node_t* end
) {
  start->weight = 0;
  struct queue_t* nodes = init_queue();
  queue_add(nodes, start);
  
  while(nodes->count > 0) {
    struct graph_node_t* curr = queue_remove(nodes);
    
    for(int i = 0; i < curr->edges->count; i++) {
      struct graph_edge_t* edge = curr->edges[i];
      int tmp_weight = curr->weight + edge->weight;
      
      if(edge->b->weight > tmp_weight)
        edge->b->weight = tmp_weight;
        
      queue_add(nodes, curr->b);
    }
  }

  return end->weight;
}

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
    {0, 2, 0, 0, 0, 7, 0},
    {2, 0, 5, 0, 0, 3, 4},
    {0, 5, 0, 0, 1, 0, 1},
    {0, 0, 0, 0, 8, 6, 1},
    {0, 0, 1, 8, 0, 2, 5},
    {7, 3, 0, 6, 2, 0, 0},
    {0, 4, 1, 1, 5, 0, 0}
  };

  struct vector_t* nodes = vector_init();
  for(int i = 0; i < 7; i++) {
    struct graph_node_t* new_node = malloc(sizeof(struct graph_node_t));
    new_node->edges = vector_init();
    new_node->visited = 0;
    new_node->weight = -1;
    vector_add(nodes, new_node);
  }

  for(int i = 1; i < 7; i++) {
    for(int j = 0; j < i; j++) {
      if(matrix[i][j] != 0)
        connect_nodes(
          vector_get(nodes, i),
          vector_get(nodes, j),
          matrix[i][j]
        );
    }
  }

  int min_weight = find_path_dijkstra(
    vector_get(nodes, 0),
    vector_get(nodes, 3)
  );
  printf("%d\n", min_weight);

  return 0;
}
