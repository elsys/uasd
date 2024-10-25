#include "stack.h"
#include <stdio.h>
int main() {
    // read str from stdin
    // print reverse

    // Stack* st = init_stack();
    // char c;
    // do {
    //     scanf("%c", &c);
    //     push(st, (int)c);
    // } while (c != '\n');

    // while (! isEmpty(st)) {
    //     printf("%c", (char)pop(st));
    // }

    // given a string '()()()(())'
    // check if brackets are balanced
    // '(()'  ')'
    // ')('
    // use stack 
    Stack* st = init_stack();
    char c;

    do {
        scanf("%c", &c);

        if (c == '(') {
            push(st, (int)c);
        } else if (c == ')') {
            if (isEmpty(st)) {
                printf("not balanced");
                return 0;
            }

            pop(st);
        }

    } while (c != '\n');

    if (isEmpty(st)) {
        printf("balanced");
    } else {
        printf("not balanced");
    }


    return 0;
}