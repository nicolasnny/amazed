/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-amazed-enzo.fokwen-rocher
** File description:
** amazed.c
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "amazed.h"
#include "struct.h"
#include "my.h"

static path_list_t *append_path(path_list_t *path_list, linked_list_t *path)
{
    path_list_t *new_path_list = malloc(sizeof(path_list_t));

    new_path_list->path = path;
    new_path_list->next = path_list;
    return new_path_list;
}

static char **get_input(void)
{
    char buf[BUFSIZ] = {0};
    char **line_array;
    char *seps = my_strdup("\n");

    if (read(STDIN_FILENO, buf, BUFSIZ) == -1)
        return NULL;
    line_array = my_str_to_word_array(buf, seps);
    return get_valid_part(line_array);
}

static void disp_robots(robot_list_t *robots)
{
    robot_list_t *temp = robots;

    while (temp) {
        printf("\t- robot : %d\n", temp->robot->id);
        temp = temp->next;
    }
}

int amazed(void)
{
    char **data = get_input();
    linked_list_t *rooms = NULL;
    char **connections = NULL;
    int **link_array = NULL;
    linked_list_t *path = NULL;
    path_list_t *path_list = NULL;

    if (!data)
        return ERROR;
    rooms = get_rooms(data);
    connections = get_connections(data);
    link_array = init_map(connections, rooms);
    path = find_shortest_path(rooms, link_array);
    display_list_name(path);
    set_map_to_find_new_path(rooms, path_list);
    while (path) {
        path_list = append_path(path_list, path);
        path = find_shortest_path(rooms, link_array);
        display_list_name(path);
        set_map_to_find_new_path(rooms, path_list);
    }
    path_list = spread_robots(rooms, path_list, data);
    path_list_t *temp = path_list;
    int i = 1;
    while (temp) {
        printf("path: \n");
        display_list_name(temp->path);
        printf("; robots:\n");
        disp_robots(temp->robots);
        i++;
        temp = temp->next;
    }
    return SUCCESS;
}
