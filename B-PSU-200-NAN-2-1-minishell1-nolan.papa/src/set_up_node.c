/*
** EPITECH PROJECT, 2024
** error handler
** File description:
** error handler
*/

#include "../header.h"

c_env_t *create_node(char *data)
{
    c_env_t *newnode = malloc(sizeof(c_env_t));

    newnode->data = my_strcpy(data);
    newnode->next = NULL;
    return newnode;
}

c_env_t *insert(c_env_t *head, c_env_t *node)
{
    c_env_t *temp = head;

    for (int i = 0; temp != NULL; i++) {
        if (temp->next == node->next) {
            temp = node;
            return temp;
        }
        temp = temp->next;
    }
    return temp;
}

void append(c_env_t **head, char *data)
{
    c_env_t *newNode = create_node(data);
    c_env_t *temp = *head;

    if (*head == NULL) {
        *head = newNode;
        temp = *head;
        return;
    }
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void printlist(c_env_t *head)
{
    c_env_t *temp = head;

    while (temp != NULL) {
        if (temp->data != NULL) {
            my_putstr(temp->data);
            my_putchar('\n');
        }
        temp = temp->next;
    }
}

c_env_t *create_list(char **str)
{
    c_env_t *head;

    for (int i = 0; str[i] != NULL; i++) {
        append(&head, str[i]);
    }
    return head;
}
