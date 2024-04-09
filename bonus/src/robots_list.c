/*
** EPITECH PROJECT, 2024
** AMAZED
** File description:
** Functions related to robot lists
*/

#include <stddef.h>
#include "amazed.h"

static void append_path_robots(robot_list_t *robots, robot_list_t *robot_path)
{
    if (robots == NULL)
        return;
    while (robots->next != NULL)
        robots = robots->next;
    robots->next = robot_path;
}

robot_list_t *get_robot_list(path_list_t *path_list)
{
    robot_list_t *robots = NULL;

    while (path_list != NULL) {
        append_path_robots(robots, path_list->robots);
        path_list = path_list->next;
    }
    return robots;
}
