#include <stdio.h>
#include <stdlib.h>
#include "../utils/hash.h"
#include "../utils/vector.h"

vector_t *lzw(char *text)
{
    HashMap *dict = init_hash_map();
    ;
    int dict_size = 256;
    for (int i = 0; i < 256; i++)
    {
        char *key = (char *)malloc(2);
        key[0] = i;
        key[1] = '\0';
        printf("%i\n", i);
        setInt(dict, key, i);
    }

    vector_t *result = init_vector();
    char *w = (char *)malloc(256);
    int word_size = 0;

    for (int i = 0; text[i] != '\0'; i++)
    {
        w[word_size++] = text[i];
        w[word_size] = '\0';

        printf("%d\n", getInt(dict, w));
        if (getInt(dict, w) != -1)
        {
            continue;
        }
        else
        {
            setInt(dict, w, dict_size++);

            w[word_size - 1] = '\0';
            push_back(result, getInt(dict, w));

            w[0] = text[i];
            w[1] = '\0';
            word_size = 1;
        }
    }

    return result;
}

int main()
{
    char *text = "ABABABA";
    vector_t *result = lzw(text);
    printVector(result);

    return 0;
}