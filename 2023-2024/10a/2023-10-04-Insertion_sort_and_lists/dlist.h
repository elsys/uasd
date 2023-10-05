#ifndef DLIST_H
#define DLIST_H

typedef struct Node
{
    int value;
    struct Node *next;
    struct Node *prev;
} Node;

/*
    Много често за удобство се пази и края на списъка. Така можем да добавяме/махаме бързо както от началото така и от края.
    Понякога дори има и трети указател сечощ към "текущ" елемент, които може да местим наляво надясно и да служи за итератор,
    чрез който бързо да махаме и добавяме някъде по-средата на масива.

    Важното, което да запомним е, че може да си модифицираме списъка както си искаме - едносвързан, двузвързан, да пазим начало, край, текущ,
    да е цикличен и т.н. В зависимост от начина по-който се очаква да го използваме прецаняме какво ни трябва.
*/

typedef struct DList
{
    Node *head;
    Node *tail;
} DList;

DList *init_dlist();
void insertBegin(DList *, int);
void insertEnd(DList *, int);

int getAt(DList *, int);
void clear(DList *);
int pop(DList *);
void printDList(DList *);
void printDListReverse(DList *);
int popFront(DList *);

void insertAt(DList *, int, int);
int removeAt(DList *, int);

#endif
