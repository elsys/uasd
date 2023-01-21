#include <stdlib.h>
#include <stdio.h>

struct node_t {
  int value;
  struct node_t* tl; // top left
  struct node_t* tr; // top right
  struct node_t* bl; // bottom left
  struct node_t* br; // bottom right
};

// For the sake of sumpler function call and to support dynamic array sizes
// images are defined as 2D arrays, but passed as single pointers and cased back to 2D arrays internally

// These functions call each other in an indirect recursion
void split_tree(struct node_t* root, void *_image, int x1, int x2, int y1, int y2, unsigned int img_size);
struct node_t* create_tree(void *_image, int x1, int x2, int y1, int y2, unsigned int img_size);

void split_tree(struct node_t* root, void *_image, int x1, int x2, int y1, int y2, unsigned int img_size) {
  if(x2 - x1 <= 1 || y2 - y1 <= 1) return;

  // This is the C syntax of defining a pointer to array -> int (*)[8]
  // in this case used as a pointer to a 2D array
  int (*image)[img_size] = (int (*)[img_size]) _image;

  printf("split tree for %d %d %d %d\n", x1, x2, y1, y2);
  // x0 is in the middle between x1 and x2
  int x0 = (x1 + x2)/2;
  int y0 = (y1 + y2)/2;

  // Recursively define and split the subnodes for each quadrant
  root->tl = create_tree(_image, x1, x0, y1, y0, img_size );
  root->tr = create_tree(_image, x0, x2, y1, y0, img_size );
  root->bl = create_tree(_image, x1, x0, y0, y2, img_size );
  root->br = create_tree(_image, x0, x2, y0, y2, img_size );
}

struct node_t* create_tree(void *_image, int x1, int x2, int y1, int y2, unsigned int img_size) {
  int (*image)[img_size] = (int (*)[img_size]) _image;

  // If we have a bigger program we'd want this to be a separate init_node function
  struct node_t* root = malloc(sizeof(struct node_t));
  root->value = -1;
  root->tl = root->tr = root->bl = root->br = NULL;

  printf("build tree for %d %d %d %d\n", x1, x2, y1, y2);
  if(x2 - x1 > 1 && y2 - y1 > 1)
    for(int i = x1; i < x2; i++)
      for(int j = y1; j < y2; j++)
        // If any 2 values are different we want to split the node
        if(image[y1][x1] != image[j][i]) {
          split_tree(root, _image, x1, x2, y1, y2, img_size);
          return root;
        }

  // All values in the area for this node are the same so no need to split
  root->value = image[y1][x1];
  return root;
}

// When rebuilding the image is again defined as a 2D array, but passed as a single pointer
// Recursively go down to leaf nodes and restore each subarea from them
void restore_image(struct node_t* root, int* _image, int x1, int x2, int y1, int y2, unsigned int img_size) {
  int (*image)[img_size] = (int (*)[img_size]) _image;

  printf("restore for %d %d %d %d -> %d\n", x1, x2, y1, y2, root->value);

  // If the node has a value assign it to all array items in the area and stop
  if(root->value >= 0) {
    for(int i = x1; i < x2; i++)
      for(int j = y1; j < y2; j++)
        image[j][i] = root->value;

    return;
  }

  int x0 = (x1 + x2)/2;
  int y0 = (y1 + y2)/2;
  // Recursively go down the tree
  restore_image(root->tl, _image, x1, x0, y1, y0, img_size );
  restore_image(root->tr, _image, x0, x2, y1, y0, img_size );
  restore_image(root->bl, _image, x1, x0, y0, y2, img_size );
  restore_image(root->br, _image, x0, x2, y0, y2, img_size );
}

// Allocate memory for the entire image and start traversing the tree
void* create_image(struct node_t* root, unsigned int img_size) {
  int (*image)[img_size] = calloc(img_size * img_size, sizeof(int));

  restore_image(root, (int*)image, 0, img_size, 0, img_size, img_size);

  return image;
}

void print_image(void *_image, unsigned int img_size) {
  int (*image)[img_size] = (int (*)[img_size]) _image;

  for(int i = 0; i < img_size; i++) {
    for(int j = 0; j < img_size; j++) {
      printf("%d ", image[i][j]);
    }
    puts("");
  }
}

void print_dfs(struct node_t* root, int level) {
  if(root == NULL) return;

  printf("[%d] %d\n", level, root->value);

  if(root->tl != NULL)
    printf("TL");
  print_dfs(root->tl, level + 1);

  if(root->tr != NULL)
    printf("TR");
  print_dfs(root->tr, level + 1);

  if(root->bl != NULL)
    printf("BL");
  print_dfs(root->bl, level + 1);

  if(root->br != NULL)
    printf("BR");
  print_dfs(root->br, level + 1);
}

int main() {
  // int image[8][8] = {
  //   {5, 5, 0, 0, 0, 0, 0, 0},
  //   {5, 5, 0, 0, 0, 0, 0, 0},
  //   {0, 0, 0, 0, 0, 0, 0, 0},
  //   {0, 0, 0, 0, 0, 0, 0, 0},
  //   {0, 0, 0, 0, 0, 0, 0, 0},
  //   {0, 0, 0, 0, 0, 0, 0, 0},
  //   {0, 0, 0, 0, 0, 0, 0, 0},
  //   {0, 0, 0, 0, 0, 0, 0, 0}
  // };

  int image[8][8] = {
    {5, 5, 0, 0, 0, 0, 0, 0},
    {5, 5, 5, 0, 0, 0, 0, 0},
    {0, 0, 0, 7, 7, 7, 0, 0},
    {0, 0, 0, 7, 7, 7, 0, 0},
    {0, 0, 0, 0, 7, 7, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 1, 1, 1},
    {0, 0, 0, 0, 0, 1, 1, 1}
  };

  struct node_t* tree = create_tree((int*)image, 0, 8, 0, 8, 8);

  print_dfs(tree, 0);

  int* result = create_image(tree, 8);
  print_image(result, 8);

  return 0;
}