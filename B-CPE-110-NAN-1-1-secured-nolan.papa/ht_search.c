/*
** EPITECH PROJECT, 2024
** ht search
** File description:
** ht search
*/

#include "hashtable.h"

char *search(hashtable_t *ht, char *key)
{
    hashtable_t *tempo = ht;
    int key_word = ht->hash(key, 0);
    int nb_key = key_word % tempo->index_max;
    w_hash *c_tempo = tempo->node[nb_key];

    if (my_strcmp(c_tempo->key, key) == 0)
        return (c_tempo->value);
    while (c_tempo->next != NULL) {
        if (my_strcmp(c_tempo->next->key, key) == 0) {
            return (c_tempo->next->value);
        } else {
            c_tempo = c_tempo->next;
        }
    }
    return (NULL);
}

char *ht_search(hashtable_t *ht, char *key)
{
    if (ht == NULL || key == NULL)
        return (NULL);
    if (ht->index_max == 0 || ht->node == NULL)
        return (NULL);
    if (key[0] == '\0')
        return (NULL);
    return (search(ht, key));
}
