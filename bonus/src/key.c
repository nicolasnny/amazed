/*
** EPITECH PROJECT, 2024
** AMAZED
** File description:
** Function related to key handling
*/

#include <stdbool.h>
#include <ncurses.h>
#include "amazed.h"

int analyse_key(int key, bool *over, bool *move_robots)
{
    /*if (key == -1)
        perror("getch");
        dprintf(2, "key in func: %d\n", key);*/
    if (key == ESCAPE) {
        *over = true;
        dprintf(2, "in escape\n");
        return key;
    }
    if (key == SPACE) {
        dprintf(2, "in space\n");
        if (*move_robots == true)
            *move_robots = false;
        else
            *move_robots = true;
        return key;
    }
    return key;
}
