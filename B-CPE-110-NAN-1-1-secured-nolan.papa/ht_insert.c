/*
** EPITECH PROJECT, 2024
** ht insert
** File description:
** ht insert
*/

#include "hashtable.h"

int ht_insert(hashtable_t *ht, char *key, char *value)
{
    int nb_key;
    w_hash *c_tempo = malloc(sizeof(w_hash));

    if (ht == NULL || key == NULL || value == NULL)
        return (84);
    if (ht->index_max == 0 || ht->node == NULL)
        return (84);
    if (key[0] == '\0' || value[0] == '\0')
        return (84);
    nb_key = ht->hash(key, 0) % ht->index_max;
    c_tempo->key = my_strcpy(key);
    c_tempo->value = my_strcpy(value);
    c_tempo->next = ht->node[nb_key];
    ht->node[nb_key] = c_tempo;
    return (0);
}
