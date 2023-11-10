#include <stdio.h>

int foo(int arg) {
    //return arg + 2;

    // int res = 0;

    // for(int i = 1; i < arg; i++)
    //     res += i;

    // return res;
    
    printf("foo(%d)\n", arg);
    if(arg == 0) return 0;

    int res = arg + foo(arg-1);
    printf("food(%d) = %d\n", arg, res);
    return res;
}

int main() {
    printf("%d\n", foo(0));
    puts("");
    printf("%d\n", foo(1));
    puts("");
    printf("%d\n", foo(5));
    return 0;
}