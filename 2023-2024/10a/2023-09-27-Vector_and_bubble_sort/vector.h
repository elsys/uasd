#ifndef VECTOR
#define VECTOR

typedef struct vector_t
{
    int *arr;
    unsigned int size;
    unsigned int capacity;
} vector_t;

/*
    Ще пишем структурите в отделни файлове за да може лесно да ги преизползваме на различни места.
    Това прави кода по-четим и лесен за разбиране.

    За да може една структура от данни наистина да се използва по предназначение ни трябват
    някакви методи за работа с нея. Би било добре когато пишем структури
    да дефинираме такива методи, така че при използване на структурата, възможно най-голяма част от достъпът
    до нея да става през тези функции. Те служат като един вид "интерфейс" над нашата структура,
    чрез който програмистът, който ще я използва, може да се възползва от всички нейни възможности.
    Той не се интересува от конкретната реализация на структурата ами от функциите, които тя предлага.

    Този вид абстракция е удобен защото така ясно указваме как тази структура се очаква да се използва.
    Всякакви допълнителни проверки и error handling могат да бъдат имплементирани в тези функции и така
    програмистът няма да трябва да се тревожи за тях ами директно ще си използва функциите.
    Например при добавяне на елемент функцията сама се грижи да реалокира нова памет, при достъп до елемент проверката
    дали индексът е в границите на масива е скрита във функцията.

    По този начин също така се предпазваме от това да някоя структура да се използва по нестандартен начин.
    Чрез директен достъп до член данните на структурата ние можем да правим каквото си искаме с тях. Можем
    да ги променим по такъв начин, че те да станат безмислени и това да попречи на работата и.
    Например да зададем size и capacity различни от реалните. Докато когато програмистът използва структурата
    през нашия интерфейс от функции, те ни гарантират, че всичко се използва по предназначение и член данните ще са
    такива каквито очакваме.

*/

vector_t *init_vector();
void push_back(vector_t *, int);
int pop(vector_t *);
void clear(vector_t *);

int getAt(vector_t *, int);
int getSize(vector_t *);

void printVector(vector_t *);
#endif