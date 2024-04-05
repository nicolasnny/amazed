/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-amazed-enzo.fokwen-rocher
** File description:
** spread_robots.c
*/

#include <stdlib.h>
#include <stdio.h>
#include "amazed.h"
#include "my.h"
#include "struct.h"

static int get_path_len(linked_list_t *path)
{
    linked_list_t *temp = path;
    unsigned int i = 0;

    while (temp) {
        i++;
        temp = temp->next;
    }
    return i;
}

static int get_nb_robots(robot_list_t *robot_list)
{
    robot_list_t *temp = robot_list;
    unsigned int i = 0;

    while (temp) {
        i++;
        temp = temp->next;
    }
    return i;
}

static node_t *get_start_room(linked_list_t *rooms)
{
    linked_list_t *temp = rooms;

    while (temp) {
        if (temp->node->start)
            return temp->node;
        temp = temp->next;
    }
    return NULL;
}

static robot_list_t *add_robot(robot_list_t *robot_list, robot_t *robot)
{
    robot_list_t *new_robot_list = malloc(sizeof(robot_list_t));

    new_robot_list->robot = robot;
    new_robot_list->next = robot_list;
    return new_robot_list;
}

static void place_robot(robot_t *robot, path_list_t *paths)
{
    path_list_t *temp = paths;

    if (!temp)
        return;
    if (temp->path_len + get_nb_robots(temp->robots) <=
        temp->next->path_len + get_nb_robots(temp->next->robots) ||
        !temp->next) {
            add_robot(temp->robots, robot);
            return;
    } else
        place_robot(robot, temp->next);
}

static path_list_t *set_rooms(robot_t **robot_list, path_list_t *paths)
{
    path_list_t *temp = paths;

    while (temp) {
        temp->robots = NULL;
        temp = temp->next;
        temp->path_len = get_path_len(temp->path);
    }
    for (unsigned int i = 0; robot_list[i]; i++) {
        place_robot(robot_list[i], paths);
    }
    return paths;
}

path_list_t *spread_robots(linked_list_t *rooms,
    path_list_t *paths, char **data)
{
    unsigned int robot_nb = my_getnbr(data[0]);
    robot_t **robot_list = malloc(sizeof(robot_t *) * (robot_nb + 1));
    node_t *start_room = get_start_room(rooms);

    for (unsigned int i = 0; i != robot_nb; i++) {
        robot_list[i] = malloc(sizeof(robot_t));
        robot_list[i]->id = i;
        robot_list[i]->room = start_room;
    }
    robot_list[robot_nb] = NULL;
    return set_rooms(robot_list, paths);
}
