/*
** EPITECH PROJECT, 2024
** hit enemy
** File description:
** hit enemy
*/

void hit_enemy(int y, int x, char **map_enemy, int i)
{
    y = y + 1;
    x = (x - 1) * 2 + 2;
    if (i == 1 || map_enemy[y][x] == 'x') {
        map_enemy[y][x] == 'x';
    } else {
        map_enemy[y][x] == 'o';
    }
}
