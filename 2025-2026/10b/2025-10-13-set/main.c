#include <stdio.h>
#include <stdlib.h>

// struct set_t {
//     int *data;
//     int size;
//     int capacity;
// };

// typedef struct set_t set_t;

// set_t* set_create() {
//     set_t* s = (set_t*)malloc(sizeof(set_t));
//     s->data = NULL;
//     s->size = 0;
//     s->capacity = 0;
//     return s;
// }

// int set_includes(set_t* s, int value) {
//   if(s->size == 0 || s->data == NULL) return 0;

//     // for (int i = 0; i < s->size; i++) {
//     //     if (s->data[i] == value) {
//     //         return 1; // true
//     //     }
//     // }
//     // return 0; // false

//     int left = 0;
//     int right = s->size - 1;
//     while (left <= right) {
//         int mid = left + (right - left) / 2;
//         if (s->data[mid] == value) {
//             return 1; // true
//         } else if (s->data[mid] < value) {
//             left = mid + 1;
//         } else {
//             right = mid - 1;
//         }
//     }
//     return 0;
// }

O(n) = log(n) + 4 + n + 2 = O(n)
void set_push(set_t* s, int value) {
  if(set_includes(s, value)) {
    return;
  }

  if(s->size == s->capacity) {
    // if(s->capacity == 0) {
    //   s->capacity = 1;
    // } else {
    //   s->capacity *= 2;
    // }
    s->capacity = s->capacity == 0 ? 1 : s->capacity * 2;
    s->data = (int*)realloc(s->data, s->capacity * sizeof(int));
  }

  //s->data[s->size] = value;
  for(int i = s->size - 1; i >= 0; i--) {
    if(s->data[i] > value) {
      // shift right
      for(int j = s->size; j > i; j--) {
        s->data[j] = s->data[j-1];
      }
      s->data[i] = value;
      s->size++;
      return;
    }
  }
  s->data[s->size] = value;
  s->size++;
}

struct node_t {
  int value;
  struct node_t* left;
  struct node_t* right;
};
typedef struct node_t node_t;

node_t* node_create(int value) {
  node_t* n = (node_t*)malloc(sizeof(node_t));
  n->value = value;
  n->left = NULL;
  n->right = NULL;
  return n;
}

struct set_t {
  node_t* root;
  int size;
};
typedef struct set_t set_t;

set_t* set_create() {
  set_t* s = (set_t*)malloc(sizeof(set_t));
  s->root = NULL;
  s->size = 0;
  return s;
}

int set_includes(set_t* s, int value) {
  // Implement the search logic here
  return 0;
}

node_t* set_push_internal(node_t* root, int value) {
  if(root == NULL) {
    return node_create(value);
  }

  if(value < root->value) {
    root->left = set_push_internal(root->left, value);
  } else if(value > root->value) {
    root->right = set_push_internal(root->right, value);
  }
  return root;
}

void set_push(set_t* s, int value) {
  if(set_includes(s, value)) {
    return;
  }
  s->root = set_push_internal(s->root, value);
  s->size++;
}

int main() {
  set_t* s = set_create();
  printf("Set contains 10? %d\n", set_includes(s, 10));
  set_push(s, 10);
  for(int i = 0; i < 100000; i++) {
    set_push(s, i);
  }
  printf("Set contains 10? %d\n", set_includes(s, 10));

  return 0;
}