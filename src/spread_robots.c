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

static unsigned int get_nb_path(path_list_t *path_list)
{
    path_list_t *temp = path_list;
    unsigned int i = 0;

    while (temp) {
        i++;
        temp = temp->next;
    }
    return i;
}

static path_list_t *append_path(path_list_t *path_list, linked_list_t *path)
{
    path_list_t *new_path_list = malloc(sizeof(path_list_t));

    new_path_list->path = path;
    new_path_list->next = path_list;
    return new_path_list;
}

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

static robot_list_t *add_robot(robot_list_t *robot_list, robot_t *robot,
    linked_list_t *path)
{
    robot_list_t *new_robot_list = malloc(sizeof(robot_list_t));

    new_robot_list->robot = robot;
    new_robot_list->next = robot_list;
    new_robot_list->robot->path = path;
    new_robot_list->robot->next_room = path;
    return new_robot_list;
}

static void place_robot(robot_t *robot, path_list_t *paths)
{
    path_list_t *temp = paths;

    if (!temp)
        return;
    if (!temp->next || temp->path_len + get_nb_robots(temp->robots) <
        temp->next->path_len + get_nb_robots(temp->next->robots)) {
            temp->robots = add_robot(temp->robots, robot, temp->path);
            return;
    } else
        place_robot(robot, temp->next);
}

static path_list_t *set_rooms(robot_t **robot_list, path_list_t *paths)
{
    path_list_t *temp = paths;

    while (temp) {
        temp->robots = NULL;
        temp->path_len = get_path_len(temp->path);
        temp = temp->next;
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

path_list_t *get_path_list(char **data, linked_list_t *rooms, int **link_array)
{
    linked_list_t *path = NULL;
    path_list_t *path_list = NULL;
    unsigned int robot_nb = my_getnbr(data[0]);

    path = find_shortest_path(rooms, link_array);
    while (path && get_nb_path(path_list) < robot_nb) {
        path_list = append_path(path_list, path);
        set_map_to_find_new_path(rooms, path_list);
        path = find_shortest_path(rooms, link_array);
    }
    path_list = spread_robots(rooms, path_list, data);
    return path_list;
}
