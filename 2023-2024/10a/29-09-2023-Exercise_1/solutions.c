#include <stdio.h>
#include "vector.h"

void SelectionSort(vector_t *v)
{
    /*
        Вътрешният цикъл служи за намиране на най-малкия елемент. Важно е на всяка итерация
        да задаваме начални стойности за min и minIndex, иначе алгоритъмът не би работил коректно.
    */
    for (int j = 0; j < getSize(v); j++)
    {
        int min = getAt(v, j);
        int minIndex = j;
        for (int i = j; i < getSize(v); i++)
        {
            if (getAt(v, i) < min)
            {
                min = getAt(v, i);
                minIndex = i;
            }
        }

        int tmp = getAt(v, j);
        v->arr[j] = v->arr[minIndex];
        v->arr[minIndex] = tmp;
    }
}

/*
    Главната идея е, че трябва да използваме два индекса за итерация.
    Един, който да минава по първия вектор и един по втория.
    Взимаме най-малкия елемент измежду двата сочени от индексите. Тъй като
    векторите са сортирани по условие, то това е и най-малкия елемент като цяло.
    Увеличаваме само индекса, от чуйто вектор сме взели елемент и така повтаряме
    докато не изчерпим единия вектор.

    Накрая, остава просто да добавим по ред елементите от другия.
    Съсигурност само един от двата while цикъла ще се изпълни, тъй като съсигурност сме изчерпали
    един от векторите.

    Качил съм и снимка илюстрация на този алгоритъм. Ще го разгледаме отново като стигнем до MergeSort.
*/
vector_t *Merge(vector_t *v1, vector_t *v2)
{
    vector_t *result = init_vector();
    int index1 = 0;
    int index2 = 0;

    while (index1 < getSize(v1) && index2 < getSize(v2))
    {
        if (getAt(v1, index1) < getAt(v2, index2))
        {
            push_back(result, getAt(v1, index1));
            index1++;
        }
        else
        {
            push_back(result, getAt(v2, index2));
            index2++;
        }
    }

    while (index1 < getSize(v1))
    {
        push_back(result, getAt(v1, index1));
        index1++;
    }

    while (index2 < getSize(v2))
    {
        push_back(result, getAt(v2, index2));
        index2++;
    }

    return result;
}

/*
    До другите две задачи така и не стигнахме, ще ги разгледаме друг час като говорим за рекурсия.
*/

int main()
{
    vector_t *v = init_vector();

    push_back(v, 1);
    push_back(v, 1);
    push_back(v, -15);
    push_back(v, 2);
    push_back(v, -7);
    push_back(v, 165);
    push_back(v, 5);
    push_back(v, 10);

    SelectionSort(v);

    vector_t *v2 = init_vector();
    push_back(v2, 1);
    push_back(v2, 2);
    push_back(v2, -7);
    push_back(v2, 100);
    push_back(v2, 5);
    push_back(v2, 17);

    SelectionSort(v2);

    printVector(v);
    printVector(v2);

    vector_t *merged = Merge(v, v2);

    printVector(merged);
}