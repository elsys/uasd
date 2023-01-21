#include <stdio.h>
#include <stdlib.h>

struct node_t {
  // struct node_t** connections;
  // int count;

  struct vector_t connections;
};

void connect_nodes(struct node_t* a, struct node_t* b) {
  vector_add(a->connections, b);
  vector_add(b->connections, a);
}

int main() {
  /*struct node_t n1;
  struct node_t n2;
  struct node_t n3;
  struct node_t n4;

  connect_nodes(&n1, &n2);
  connect_nodes(&n2, &n3);
  connect_nodes(&n3, &n1);
  connect_nodes(&n3, &n4);*/

  int matrix[][] = {
    {0, 1, 1, 0},
    {1, 0, 1, 0},
    {1, 1, 0, 1},
    {0, 0, 1, 0}
  };

  struct vector_t nodes;
  for(int i = 0; i < 4; i++) {
    struct node_t* new_node = malloc(sizeof(struct node_t));
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

  return 0;
}