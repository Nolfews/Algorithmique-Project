/*
** EPITECH PROJECT, 2024
** ht delete
** File description:
** ht delete
*/

#include "hashtable.h"

int delete(hashtable_t *ht, char *key)
{
    hashtable_t *tempo = ht;
    int key_word = ht->hash(key, 0);
    int nb_key = key_word % tempo->index_max;
    w_hash *c_tempo = tempo->node[nb_key];

    if (c_tempo == NULL)
        return (84);
    if (c_tempo->key == key) {
        c_tempo = c_tempo->next;
    }
    while (c_tempo->next != NULL) {
        if (my_strcmp(c_tempo->next->key, key) == 0) {
            c_tempo->next = c_tempo->next->next;
        } else {
            c_tempo = c_tempo->next;
        }
    }
    return (0);
}

int ht_delete(hashtable_t *ht, char *key)
{
    if (ht == NULL || key == NULL)
        return (84);
    if (ht->index_max == 0 || ht->node == NULL)
        return (84);
    if (key[0] == '\0')
        return (84);
    return (delete(ht, key));
}
