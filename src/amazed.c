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

void disp_robots(path_list_t *path_list)
{
    path_list_t *temp = path_list;
    int i = 1;
    robot_list_t *temp_robots;

    while (temp) {
        mini_printf("path n°%d:\n\t", i);
        display_list_name(temp->path);
        mini_printf("\nrobots:\n");
        temp_robots = temp->robots;
        while (temp_robots) {
            mini_printf("\t-id = %d\n", temp_robots->robot->id);
            temp_robots = temp_robots->next;
        }
        i++;
        temp = temp->next;
    }
}

int amazed(void)
{
    char **data = get_input();
    linked_list_t *rooms = NULL;
    char **connections = NULL;
    int **link_array = NULL;
    path_list_t *path_list = NULL;

    if (!data)
        return ERROR;
    rooms = get_rooms(data);
    connections = get_connections(data);
    link_array = init_map(connections, rooms);
    path_list = get_path_list(data, rooms, link_array);
    print_basic_output(rooms, data, connections, path_list);
    return SUCCESS;
}
