#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "foo.h"

typedef struct Point {
    int x;
    int y;
    // char c;
    // char c2;   
} Point;

typedef struct Node {
    struct Node* n;
} Node;

float dist (Point* p1, Point* p2) {
    return sqrt((p1->x - p2->x)*(p1->x - p2->x) + (p1->y - p2->y)*(p1->y - p2->y));
}

//

int fib(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }

    return fib(n-1) + fib(n-2);
}

int pow2(int a, int b) {
    if (b == 0) {
        return 1;
    }

    //tail recursion
    return a*pow2(a, b-1);
}


int main () {
    int a = 10;
    float f = 0.5;
    char c = 'a';
    int arr[5] = {1,2,3,4,5};

    if (f > 0) {
        printf("Positive");
    } 
    else if (f == 0) {
        printf("Zero");
    }
    else {
        printf("Negative");
    }

    while (a > 0) {
        //a = 10
        int c = a--;
        //int b = --a;
    }

    for (int i = 10; i > 0; i--) {
        if (i % 2 == 0) {
            continue;
        }
        printf("%d", i);
        if (i == 8) {
            break;
        }

    }

    //scanf("%d", &a);
    printf("Hello world %d!\n", a);

    Point point = {2.0, 3.0};

    printf("%ld\n", sizeof(Point));

    a = 4;
    int* p = &a;
    *p = 5;
    printf("%p %d\n", p, a);


    int N = 20;
    int M = 10;
    //scanf("%d", &N);

    int** darr = (int**)malloc(sizeof(int*)*M);
    for (int i = 0; i < M; i++) {
        darr[i] = (int*)malloc(sizeof(int)*N);
    }
    if (darr == NULL) {
        return -1;
    }

    
    int** tmp = (int**)realloc(darr, sizeof(int*)*M*2);
    if (tmp == NULL) {
        //error handling
        return -1;
    }
    darr = tmp;
    
    int* zeroes = (int*)calloc(M, sizeof(int));

    Point* p1 = (Point*)malloc(sizeof(Point));
    Point* p2 = (Point*)malloc(sizeof(Point));

    p1->x = 0;
    p1->y = 0;
    p2->x = 1;
    p2->y = 1;

    printf("%f\n", dist(p1,p2));

    free(darr);

    printf("%d\n", fib(5));

    return 0;
}