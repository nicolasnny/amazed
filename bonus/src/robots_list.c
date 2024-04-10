/*
** EPITECH PROJECT, 2024
** AMAZED
** File description:
** Functions related to robot lists
*/

#include <stdlib.h>
#include <stddef.h>
#include "amazed.h"

static void add_robot_to_path(robot_list_t **list, robot_t *robot)
{
    robot_list_t *element = malloc(sizeof(robot_list_t));

    element->robot = robot;
    element->next = *list;
    *list = element;
}

static void add_all_robots(robot_list_t **robots, robot_list_t *path_list)
{
    while (path_list != NULL) {
        add_robot_to_path(robots, path_list->robot);
        path_list = path_list->next;
    }
}

robot_list_t *get_robot_list(path_list_t *path_list)
{
    robot_list_t *robots = NULL;

    while (path_list != NULL) {
        add_all_robots(&robots, path_list->robots);
        path_list = path_list->next;
    }
    return robots;
}
