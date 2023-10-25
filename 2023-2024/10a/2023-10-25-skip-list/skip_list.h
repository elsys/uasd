#ifndef SKIP_LISTH
#define SKIP_LISTH

#define MAX_LEVEL 16

/*
    За по-лесно директно зададохме константен MAX_LEVEL и масив с такъв размер. Иначе трябваше да се занимаваме динамично да го алокираме и следим
    Това разбира се увеличава използваната памет с 16 указателя за всеки Node. Не е прекалено фрапиращо, особено ако данните, които пазим не са просто един int,
    а някакъв по-сложен обект, на чийто фон тези 16 указателя да нямат толкова значение. Но най-добре би било да се алокират динамично.
    Тогава освен основните n Node-a на нулево ниво, допълнителната памет би била следната:
    1/2 Node-ове на второ ниво
    1/4 на трето
    1/8 на четвърто и т.н
    1/2 + 1/4 + 1/8 + ... = 1

    Общата допълнителна памет е отново n, а цялата с нулево ниво - само 2n.

*/
typedef struct Node
{
    int value;
    struct Node *next[MAX_LEVEL];
} Node;

typedef struct SkipList
{
    Node *head;
} SkipList;

SkipList *init_list();
void clear(SkipList *list);
void printList(SkipList *list);

void sl_insert(SkipList *list, int val);
Node *sl_search(SkipList *list, int val);
Node *sl_remove(SkipList *list, int val);

#endif