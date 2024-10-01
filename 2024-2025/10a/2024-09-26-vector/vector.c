#include "vector.h"
#include <stdio.h>
#include <stdlib.h>

/*
    Бихме могли да върнем и просто вектор а не указател.
    vector_t init_vector();

    По-стандартно е да се работи с указатели. Освен това ако върнем директно
    структура то данните на структурата трябва да се копират в резултата.
    Тоест при използване:
    vector_t v = init_vector();

    резултатът от init_vector() трябва да се копира във v. В случая няма да има много разлика, но
    ако беше по-сложна и голяма структура можем да си го спестим като само подаваме указатели.

*/
vector* init_vector(int initialCapacity) {
    vector* v = (vector*)malloc(sizeof(vector));
    v->arr = (int*)malloc(initialCapacity * sizeof(int));
    v->size = 0; 
    v->capacity = initialCapacity;

    return v;
}

void push(vector *v, int val) {
    /*
        Реалокирането на памет е операция, която искаме да избегнем да правим на всяко добавяне на стойност.
        Затова в нашата имплементация на вектор добавяме и капацитет, който указва количеството заделена памет,
        която имаме на разположение, а size показва частта, която реално използваме в момента.
        Така може да си позволим да реалокираме само когато size достигне capacity. Умножавайки capacity по някаква
        константа като 2 (така работи и стандардния вектор в C++) или 1.5 си гарантираме, че няма да се налага
        да реалокираме при всяко добавяне на елемент.
        Да, това ще доведе до излишество на памет, така че ако искаме максимално оптимални с паметта няма нужда от
        capacity и бихме реалокирали всеки път. Но в повечето случаи бързодействието е по-приоритетно от паметта.
    */
    if (v->size + 1 > v->capacity) {
        v->capacity = v->size * 2;
        int *tmp = (int*)realloc(v->arr, v->capacity);
        if (tmp == NULL) {
            exit(0);
        }
        v->arr = tmp;    
    }

    v->size++;
    v->arr[v->size - 1] = val;
}

int pop(vector *v) {
    // в час не направихме тази проверка, но е хубаво да я има.
    if (v->size == 0)
    {
        printf("cannot pop from empty array");
        exit(0);
    }

    int tmp = v->arr[v->size - 1];
    v->size--;

    return tmp;
}

int getAt(vector *v, int i) {
    // както и тази
    if (i >= v->size)
    {
        exit(1);
    }
    return v->arr[i];
}

void print_vector(vector *v) {
    for (int i = 0; i < v->size; i++) {
        printf("%d ", getAt(v, i));
    }
    printf("\n");
}

void clear_vector(vector *v) {
    v->size = 0;
    free(v->arr);
    v->arr = (int*)malloc(2 * sizeof(int));
    v->capacity = 2;
}

void free_vector(vector *v) {
    free(v->arr);
    free(v);
}