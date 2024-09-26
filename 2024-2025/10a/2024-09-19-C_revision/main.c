#include <stdio.h>
// за функциите за работа с динамична памет
#include <stdlib.h>
#include <stdbool.h>

// локални файлове се include-ват с кавички ""
// при компилиране подаваме и файла с реалната имплементация
// gcc main.c foo.c
#include "foo.h"

int safeSub(int a, int b) {
    return a > b ? a - b : 0;
}

// typedef ни позволява да използваме името директно като тип
// иначе бихме използвали като
// struct Point p; вместо само Point p;
typedef struct Point {
    int x;
    int y;
    char c1;
    char c;
} Point;


// Fn = Fn-1 + Fn-2
int fib(int n) {
    if (n <= 1) {
        return 1;
    }

    // всяко извикване на fib извиква други две, които сами по себе си извикват други две и т.н, става изключително бавно
    return fib(n - 2) + fib(n - 1);
}

int main() {
    int n = 1, n3 = 3;
    long n2 = 2;
    float f = 1.5;
    double d = 2.5;

    char c = 'c';
    char word[6] = "hello";

    // Bool b = true;
    // при scanf се подават адресите на променливите с оператора &
    printf("%d", n);
    //scanf("%d", &n);

    int *p = &n;
    printf("%d\n", *p);
    *p = 3;
    printf("%d\n", n);
    p = &n3;

    int i = 20;
    while (i < 10) {

        // some code

        ++i;
    }

    for (int i = 0; i < 10; i++) {
        if (i % 2 != 0) {
            continue;
        } 

        if (i == 8) {
            break;
        }
    }

    Point point;
    point.x = 1.5;
    point.y = 2.5;

    printf("%ld", sizeof(Point));

    int *arr = (int *)malloc(10 * sizeof(int));
    if (arr == NULL) {
        // не е успяло да задели памет
        // handle err
        exit(1);
    }
    // при реалокиране е добра практика да се използва временен указател в случай, че realloc върне грешка.
    // В такъв случай оригиналната памет не се освобождава, но губим връзка към нея => memory leak

    int *tmp = realloc(arr, 20 * sizeof(int));
    if (tmp == NULL) {
        exit(1);
    }
    arr = tmp;

    // calloc приема аргументите малко по различно, два вместо един.
    // също инициализира паметта с нули, докато при malloc са случайни стойности

    int *arr2 = (int *)calloc(10, sizeof(int));

    bar();

    fib(200);

    

    return 0;
}