#include <stdio.h>
#include "skip_list.h"

int main()
{
    SkipList *list = init_list();

    sl_insert(list, 1);
    sl_insert(list, 4);
    sl_insert(list, 3);
    sl_insert(list, -10);
    sl_insert(list, -5);
    sl_insert(list, 137);
    sl_insert(list, 100);
    sl_insert(list, 23);
    sl_insert(list, 5);

    printList(list);
    clear(list);
}
