/*
** EPITECH PROJECT, 2024
** AMAZED
** File description:
** Function related to key handling
*/

#include <stdbool.h>
#include <ncurses.h>

void analyse_key(int key, bool *over, bool *move_robots)
{
    key = get_ch();
    if (key == ESCAPE) {
        *over = true;
        return;
    }
    if (key == SPACE) {
        if (*move_robots == true)
            *move_robots = false;
        else
            *move_robots = true;
    }
}
