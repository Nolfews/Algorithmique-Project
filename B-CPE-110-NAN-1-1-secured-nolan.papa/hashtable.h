/*
** EPITECH PROJECT, 2023
** B-CPE-110 : Secured
** File description:
** hashtable.h
*/

#ifndef HASHTABLE_H
    #define HASHTABLE_H
    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>

typedef struct word_hash {
    char *key;
    char *value;
    struct word_hash *next;
} w_hash;

typedef struct hashtable_s {
    int index_max;
    int (*hash)(char *, int);
    w_hash **node;
} hashtable_t;

// Hash function
int hash(char *key, int len);

// Create & destro table
hashtable_t *new_hashtable(int (*hash)(char *, int), int len);
void delete_hashtable(hashtable_t *ht);

// Handle table
int ht_insert(hashtable_t *ht, char *key, char *value);
int ht_delete(hashtable_t *ht, char *key);
char *ht_search(hashtable_t *ht, char *key);
void ht_dump(hashtable_t *ht);
void my_putchar(char c);
void my_put_nbr(int nb);
void my_putstr(char const *str);
int my_strlen(char const *str);
char *my_strcpy(char const *src);
int my_strcmp(char *str1, char *str2);
#endif /* HASHTABLE_H */
