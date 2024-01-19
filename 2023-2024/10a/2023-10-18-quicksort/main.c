#include <stdio.h>
#include "../utils/vector.h"
// #include "../6_10_dlist_exc/dlist.h"

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
/*
    Това е същинската част на алгоритъма. В час малко я пообърках и докато стана края на часа така и не я оправих.
    Отбелязал съм долу какво трябваше да се промени.
*/
int partition(vector_t *v, int start, int end)
{
    int i = start;
    int j = end;
    int pivot = getAt(v, end);

    while (1)
    {
        while (getAt(v, i) < pivot)
        {
            i++;
        }

        /*
            Първият проблем, който имаше беше че тук бях написал >= вместо >
            Трябва да се спира на елементи равни на pivot поради две причина.
            Първата е че ако pivot е най-малкият елемент този цикъл ще излезе от масива. Ще трябват да се правят допълнителни проверки и ще стане по гадно и сложно за писане.
            Втората е че при масиви пълни с еднакви елементи това да ги пропускаме би довело до учеличаване на сложността.
            Това е така защото ние ще минем през всички тях и единият подмасив, които ще се получи ще бъде голям колкото целия масив
            понеже j е минало през целия масив. А ние се стремим подмасивите да са достатъчно големи иначе сложността не би била логаритмична.
        */
        while (getAt(v, j) > pivot)
        {
            j--;
        }

        /*
            В крайна сметка елементи равни на pivot може да има и в двата подмасива, които получаваме и това не е проблем.
        */

        if (i >= j)
        {
            return i;
        }

        swap(&(v->arr[i]), &(v->arr[j]));
        /*
            Нещо очевидно, което пропуснах е да променям индексите след самия swap за да не остават на едно и също място.
            Затова и в интернет на повечето места ще намерите алгоритъма написан с do while цикли.
            Това е нужно за да може ако попаднем на еднакви елементи да не ги swap-ваме до безкрай.
            Освен това след размяната елементите вече са на правилните места и няма смисъл пак да ги проверяваме.
        */
        i++;
        j--;
    }
}

void quicksortR(vector_t *v, int start, int end)
{
    if (start >= end)
    {
        return;
    }

    int mid = partition(v, start, end);
    quicksortR(v, start, mid - 1);
    quicksortR(v, mid, end);
}

void quicksort(vector_t *v)
{
    quicksortR(v, 0, getSize(v) - 1);
}

int partitionLomuto(vector_t *v, int start, int end)
{
    int i = 0;
    int pp = start;
    int pivot = getAt(v, end);

    for (int j = start; j < end; j++)
    {
        if (getAt(v, j) < pivot)
        {
            if (j != pp)
            {
                swap(&v->arr[j], &v->arr[pp]);
            }
            pp++;
        }
    }

    swap(&v->arr[end], &v->arr[pp]);

    return pp;
}

void quicksortRLomuto(vector_t *v, int start, int end)
{
    if (start >= end)
    {
        return;
    }

    int mid = partitionLomuto(v, start, end);
    quicksortR(v, start, mid - 1);
    quicksortR(v, mid + 1, end);
}

void quicksortLomuto(vector_t *v)
{
    quicksortRLomuto(v, 0, getSize(v) - 1);
}

void allSums(vector_t *v, int index, int sum)
{
    if (index == getSize(v))
    {
        printf("%d ", sum);
        return;
    }

    allSums(v, index + 1, sum + getAt(v, index));
    allSums(v, index + 1, sum);
}

int main()
{
    vector_t *v = init_vector();

    push_back(v, 0);
    push_back(v, -3);
    push_back(v, 5);
    push_back(v, 3);
    push_back(v, 2);

    allSums(v, 0, 0);

    // int mid = partitionLomuto(v, 0, getSize(v) - 1);
    // printf("mid = %d\n", mid);
    // printVector(v);

    // mid = partitionLomuto(v, mid + 1, getSize(v) - 1);
    // printf("mid = %d\n", mid);
    // printVector(v);

    // mid = partitionLomuto(v, mid + 1, getSize(v) - 1);
    // printf("mid = %d\n", mid);
    quicksortLomuto(v);
    printVector(v);

    // quicksortLomuto(v);
    // printVector(v);

    return 0;
}
