/*
** EPITECH PROJECT, 2024
** hash
** File description:
** hash
*/

#include "hashtable.h"
const double pi = 3.14159265359;

int hash(char *key, int len)
{
    long long nb = 0.00;
    int result = 0;

    for (int i = 0; key[i] != '\0'; i++) {
        if (i % 2 == 0) {
            nb = (nb + key[i] + 48 + pi) * (pi + pi / 2);
        } else {
            nb = (nb - key[i + 1] + 48 + pi) * (pi + pi / 2);
        }
        if (key[i] <= key[i + 1])
            nb = nb / 2 * -1;
        if (key[0] > key[i])
            nb = nb * pi * 1.5;
        if (key[i] % 2 == 0)
            nb = nb / pi * -1.5;
    }
    if (nb < 0) {
        nb *= -1;
    }
    return ((int)nb);
}

hashtable_t *new_hashtable(int (*hash)(char *, int), int len)
{
    hashtable_t *ht = malloc(sizeof(hashtable_t));

    ht->index_max = len;
    ht->node = malloc(sizeof(w_hash) * len);
    ht->hash = hash;
    for (int i = 0; i <= len; i++) {
        ht->node[i] = NULL;
    }
    return (ht);
}

void delete_hashtable(hashtable_t *ht)
{
    free(ht->node);
    free(ht);
}
