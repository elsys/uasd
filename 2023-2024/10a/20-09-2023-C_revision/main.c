#include <stdio.h>

// за функциите за работа с динамична памет
#include <stdlib.h>

// при използване на math.h се компилира с флага -lm, който казва на компилатора да
// link-нe имплементациите на функциите от math.h, тъй като по подразбиране не са
#include <math.h>

// локални файлове се include-ват с кавички ""
// при компилиране подаваме и файла с реалната имплементация
#include "foo.h"

// gcc main.c foo.c -lm && ./a.out

void print_binary(unsigned int number)
{
    if (number >> 1)
    {
        print_binary(number >> 1);
    }
    else
    {
        putc('\n', stdout);
    }
    putc((number & 1) ? '1' : '0', stdout);

    // Пример с 5=101
    // 101 >> 010 >> 001 >> 000 - край
    // 001    001    001
    //   1      0      1  = 101
}

// Fn = Fn-1 + Fn-2
int fib(int n)
{
    if (n == 0)
    {
        return 1;
    }
    if (n == 1)
    {
        return 1;
    }

    // всяко извикване на fib извиква други две, които сами по себе си извикват други две и т.н, става изключително бавно
    return fib(n - 1) + fib(n - 2);
}

// typedef ни позволява да използваме името директно като тип
// иначе бихме използвали като
// struct Point p; вместо само Point p;
typedef struct Point
{
    double x;
    double y;
} Point;

int main()
{
    Point p, p2;
    p.x = 0;
    p.y = 2;

    // при scanf се подават адресите на променливите с оператора &
    printf("p.x = ");
    scanf("%lf", &p2.x);
    printf("p.y = ");
    scanf("%lf", &p2.y);

    float d = sqrt(pow((p.x - p2.x), 2) + pow((p.y - p2.y), 2));
    float eps = 0.001;

    // при сравнения с float е хубаво да използваме някаква малка помощна стойност тъй като могат да бъдат неточни.
    if (abs(d) < eps)
    {
        printf("same point\n");
    }

    int arr[] = {1, 2, 3};
    for (int i = 0; i < 3; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Разликата м/у calloc и malloc
    int *arrP = (int *)malloc(3 * sizeof(int));
    int *arrC = (int *)calloc(3, sizeof(int));

    if (arrP == NULL)
    {
        // не е успяло да задели памет
        // handle err
    }

    printf("%d\n", arrP[1]); // не гарантирано, че е нула, може да е garbage стойност
    printf("%d\n", arrC[1]); // 0 със сигурност

    // при реалокиране е добра практика да се използва временен указател в случай, че realloc върне грешка.
    // В такъв случай оригиналната памет не се освобождава, но губим връзка към нея => memory leak

    // int arrP = (int *)realloc(arrP, 6 * sizeof(int));
    int *tmp = (int *)realloc(arrP, 6 * sizeof(int));
    if (tmp != NULL)
    {
        arrP = tmp;
    }
    else
    {
        // sad
    }

    free(arrP);
    free(arrC);

    arrP = arr;
    printf("%d\n", arrP[1]); // 2, същото като *(arrP + 1)

    // Бинарни операции (ще ги упражним отново и ще им обърнем повече внимание по-напред)
    int a = 0b101011;
    int b = 0b010101;

    print_binary(a & b); // 000001 AND
    print_binary(a | b); // 111111 OR
    print_binary(a ^ b); // 111110 XOR
    print_binary(~a);    // 11111111111111111111111111010100 NOT инвертира всички битове затова се появяват и многото единици

    printf("\n%d\n", fib(5));
    // printf("\n%d\n", fib(100)); //ще си почакаме

    int num = 3;
    int *p3 = &num; // & - взима адреса на променлива
    printf("%p\n", p3);
    printf("%d\n", *p3);   // 3 // * - взима стойността, към която сочи указател (дерефенциране)
    printf("%d\n", ++*p3); // 4
    printf("%d\n", num);   // 4 - оригиналната променлива се променя също

    // include-натата функция
    foo();

    return 0;
}
