#include <stdio.h>
#include <stdlib.h>

void quick_sort(int numbers[], unsigned int count) {
  if(count < 2) return;

  int anchor = 0;

  for(int i = anchor + 1; i < count; i++) {
    if(numbers[i] < numbers[anchor]) {
      // a b c A x d z
      int tmp = numbers[i]; // tmp == d
      // a b c A x _ z
      for(int j = i - 1; j >= anchor; j--)
        numbers[j + 1] = numbers[j];
      // a b c A A x z
      // a b c _ A x z
      numbers[anchor] = tmp; // A => d
      // a b c d A x z
      anchor++;
    }
  }

  // if(anchor >= 2)
  quick_sort(numbers, anchor);

  // if(count - anchor - 1 >= 2)
  quick_sort(numbers + anchor + 1, count - anchor - 1);
  // numbers[anchor + 1] === *(numbers + anchor + 1)
}



struct list_node_t {
    int value;
    struct list_node_t* next;
};

struct list_node_t* create_node(int value) {
    struct list_node_t* new_node = malloc(sizeof(struct list_node_t));
    new_node->value = value;
    new_node->next = NULL;

    return new_node;
}

struct list_node_t* push_front(struct list_node_t* head, int value) {
    struct list_node_t* new_node = create_node(value);

    new_node->next = head;
    head = new_node;

    return head;
}

void print_list(struct list_node_t* head) {
  struct list_node_t* current = head;
  while(current != NULL) {
    printf("%d -> ", current->value);
    current = current->next;
  }
  puts("N");
}

void list_shift_values(struct list_node_t* left, struct list_node_t* right) {
  // for(int j = i - 1; j >= anchor; j--)
  if(left->next != right)
    list_shift_values(left->next, right);
  // numbers[j + 1] = numbers[j];
  left->next->value = left->value;
}

void list_quick_sort(struct list_node_t* head) {
  if(head == NULL || head->next == NULL) return;

  struct list_node_t* anchor = head;

  for(
    struct list_node_t* i = anchor->next;
    i != NULL;
    i = i->next
  ) {
    if(i->value < anchor->value) {
      // a b c A x d z
      int tmp = i->value; // tmp == d
      // a b c A x _ z
      list_shift_values(anchor, i);
      // a b c A A x z
      // a b c _ A x z
      anchor->value = tmp; // A => d
      // a b c d A x z
      anchor = anchor->next;
    }
  }
};



int main() {
    // int numbers[8] = {6, 8, 3, 7, 2, 4, 5, 1};

    // for(int i = 0; i < 8; i++)
    //     printf("numbers[%d] = %d\n", i, numbers[i]);

    // quick_sort(numbers, 8);

    // puts("");
    // for(int i =0; i < 8; i++)
    //     printf("numbers[%d] = %d\n", i, numbers[i]);

    struct list_node_t* my_list = NULL;
    my_list = push_front(my_list, 1);
    my_list = push_front(my_list, 5);
    my_list = push_front(my_list, 4);
    my_list = push_front(my_list, 2);
    my_list = push_front(my_list, 7);
    my_list = push_front(my_list, 3);
    my_list = push_front(my_list, 8);
    my_list = push_front(my_list, 6);

    print_list(my_list);

    list_quick_sort(my_list);

    print_list(my_list);

    return 0;
}