/*
** EPITECH PROJECT, 2024
** my_navy
** File description:
** handler_signaux
*/

#include "include/header.h"

void handler(int signo, siginfo_t *structure, void *ucontext)
{
    ga.my_pid = structure->si_pid;
    ga.trans++;
}

void handler_p2(int signo, siginfo_t *structure, void *ucontext)
{
    ga.my_pid = structure->si_pid;
    ga.trans *= -1;
}
