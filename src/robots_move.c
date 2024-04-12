/*
** EPITECH PROJECT, 2024
** robots_moves
** File description:
** all functions related to robots moovement
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "amazed.h"
#include "my.h"
#include "struct.h"

static bool check_one_path(path_list_t *path_list)
{
    if (path_list == NULL)
        return false;
    while (path_list->robots) {
        if (!path_list->robots->robot->room->end) {
            return false;
        }
        path_list->robots = path_list->robots->next;
    }
    return true;
}

static bool game_finished(path_list_t *path_list)
{
    path_list_t *path_list_cpy = path_list;

    if (path_list_cpy == NULL)
        return false;
    while (path_list_cpy) {
        if (!check_one_path(path_list_cpy)) {
            return false;
        }
        path_list_cpy = path_list_cpy->next;
    }
    return true;
}

static void recursive_move(robot_list_t *robots, char **buffer)
{
    char *str = NULL;

    if (robots == NULL || robots->robot == NULL)
        return;
    recursive_move(robots->next, buffer);
    if (robots->robot->next_room != NULL &&
        (!robots->robot->next_room->node->is_occupied ||
            robots->robot->next_room->node->end)) {
        robots->robot->room->is_occupied = false;
        robots->robot->next_room->node->is_occupied = true;
        robots->robot->room = robots->robot->next_room->node;
        robots->robot->next_room = robots->robot->next_room->next;
        *buffer = my_strcat(*buffer, "P");
        str = my_nb_to_str(robots->robot->id + 1);
        *buffer = my_strcat(*buffer, str);
        free(str);
        *buffer = my_strcat(*buffer, "-");
        *buffer = my_strcat(*buffer, robots->robot->room->name);
        *buffer = my_strcat(*buffer, " ");
    }
}

void move_robots(path_list_t *path_list)
{
    path_list_t *path_list_cpy = path_list;
    char *buffer = "";
    int buf_len = 0;

    if (path_list == NULL)
        return;
    while (!game_finished(path_list_cpy)) {
        recursive_move(path_list_cpy->robots, &buffer);
        if (path_list_cpy->next == NULL && my_strlen(buffer) != 0) {
            path_list_cpy = path_list;
            buf_len = my_strlen(buffer);
            buffer[buf_len - 1] = '\n';
            write(1, buffer, buf_len);
        } else
            path_list_cpy = path_list_cpy->next;
    }
}
