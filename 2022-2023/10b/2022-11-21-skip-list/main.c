#include <stdlib.h>
#include <stdio.h>

struct node_t {
  int value;
  struct node_t* next;
  struct node_t* skip;
};

struct node_t* init_node(int value) {
  struct node_t* new_node = malloc(sizeof(struct node_t));
  
  new_node->value = value;
  new_node->skip = new_node->next = NULL;
  
  return new_node;
}

struct node_t* add(struct node_t* head, int value) {
  if(head == NULL) return init_node(value);
  if(head->value > value) {
    struct node_t* new_node = init_node(value);
    new_node->next = head;
    //new_node->skip = head->skip || head->next;
    new_node->skip = head->skip;
    if(new_node->skip == NULL)
      new_node->skip = head->next;
    head->skip = NULL;
    return new_node;
  }
  
  struct node_t* curr = head;
  struct node_t* last_skip = head;
  
  while(
    curr->skip != NULL &&
    curr->skip->value < value
  )
    curr = curr->skip;
  last_skip = curr;
  
  while(
    curr->next != NULL && 
    curr->next->value < value
  ) 
    curr = curr->next; 
  
  struct node_t* new_node = init_node(value);
  new_node->next = curr->next;
  curr->next = new_node;
  
  if(last_skip->skip == NULL) {
    last_skip->skip = new_node;
  }
  
  return head;
}

void rebuild_skips(struct node_t* head) {
  if(head == NULL) return;
  
  struct node_t* curr = head->next;
  struct node_t* last_skip = head;
  
  if(head->next != NULL && head->next->next != NULL)
    head->skip = head->next->next;
  
  while(curr != NULL) {
    printf("%p %p\n", last_skip->skip, curr);
    if(last_skip->skip == curr) {
      if(curr->next != NULL)
        curr->skip = curr->next->next;
      last_skip = curr;
    } else {
      curr->skip = NULL;
      printf("%d ok\n", curr->value);
    }
    
    curr = curr->next;
  }
}

void print_list(struct node_t* head) {
  int i = 0;
  while(head != NULL) {
    printf(
      "[%d] %d p=%p n=%p s=%p\n", 
      i++,
      head->value,
      head,
      head->next,
      head->skip
    );
    head = head->next;
  }
}

int main() {
  struct node_t* list = NULL;
  
  for(int i = 0; i < 5; i++) 
    list = add(list, (4-i) * 3);
  
  for(int i = 0; i < 3; i++) 
    list = add(list, 14 + i * 3);
    
  add(list, 15);
  add(list, 16);
  
  print_list(list);
  puts("");
  
  rebuild_skips(list);
  print_list(list);
	return 0;
}
