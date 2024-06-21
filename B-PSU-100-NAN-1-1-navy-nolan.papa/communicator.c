/*
** EPITECH PROJECT, 2024
** my_navy
** File description:
** communicator
*/

#include "include/header.h"

int communication(int argc, char **argv, char **map, char **map_enemy)
{
    struct sigaction sig;

    sig.sa_sigaction = &handler;
    sig.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &sig, NULL);
    sig.sa_sigaction = &handler_p2;
    sigaction(SIGUSR2, &sig, NULL);
    my_putstr("my_pid: ");
    my_putnbr((int)getpid());
    if (argc == 2) {
        my_putstr("\n\nwaiting for enemy connection...\n\n");
        pause();
        kill(ga.my_pid, 10);
        my_putstr("enemy connected\n\n");
    } else {
        kill(my_getnbr(argv[1]), 10);
        pause();
        my_putstr("\n\nsuccessfully connected\n\n");
    }
    game_loop(argc, argv, map, map_enemy);
}

int print_map(char **map, char **map_enemy)
{
    for (int i = 0; map[i] != NULL; i++)
        my_putstr(map[i]);
    my_putchar('\n');
    for (int i = 0; map_enemy[i] != NULL; i++)
        my_putstr(map_enemy[i]);
    my_putchar('\n');
}
