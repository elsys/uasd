#include <stdio.h>
#include <string.h>
#include "stack.h"

int main() {
    char* str = "()()()((())";
    Stack* stack = init_stack();

    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == '(') {
            push(stack, 1);
        } else {
            if (isEmpty(stack)) {
                printf("not balanced\n");
                break;
            }
            pop(stack);
        }
    }

    if (isEmpty(stack)) {
        printf("balanced\n");
    } else {
        printf("not balanced\n");
    }


    return 0;
}