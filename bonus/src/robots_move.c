/*
** EPITECH PROJECT, 2024
** robots_moves
** File description:
** all functions related to robots moovement
*/

#include <stdio.h>
#include <stdlib.h>
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

static void recursive_move(robot_list_t *robots)
{
    if (robots == NULL || robots->robot == NULL)
        return;
    recursive_move(robots->next);
    if (robots->robot->next_room != NULL &&
        (!robots->robot->next_room->node->is_occupied ||
            robots->robot->next_room->node->end)) {
        robots->robot->room->is_occupied = false;
        robots->robot->next_room->node->is_occupied = true;
        robots->robot->room = robots->robot->next_room->node;
        robots->robot->next_room = robots->robot->next_room->next;
        mini_printf("P%d-%s ", robots->robot->id + 1,
            robots->robot->room->name);
    }
}

void move_robots(path_list_t *path_list)
{
    path_list_t *path_list_cpy = path_list;

    if (path_list == NULL)
        return;
    while (!game_finished(path_list_cpy)) {
        recursive_move(path_list_cpy->robots);
        if (path_list_cpy->next == NULL) {
            path_list_cpy = path_list;
            mini_printf("\n");
        } else
            path_list_cpy = path_list_cpy->next;
    }
}
