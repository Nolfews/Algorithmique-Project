/*
** EPITECH PROJECT, 2024
** ht dump
** File description:
** ht dump
*/

#include "hashtable.h"

static void slave_ht_dump(w_hash *tempo, int i)
{
    while (tempo != NULL) {
        my_putstr("> ");
        my_put_nbr(hash(tempo->key, 0));
        my_putstr(" - ");
        my_putstr(tempo->value);
        my_putchar('\n');
        tempo = tempo->next;
    }
}

void ht_dump(hashtable_t *ht)
{
    hashtable_t *tempo = ht;
    w_hash *c_tempo;

    for (int i = 0; i < tempo->index_max; i++) {
        c_tempo = tempo->node[i];
        my_putchar('[');
        my_put_nbr(i);
        my_putstr("]:\n");
        slave_ht_dump(c_tempo, i);
    }
}
