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

    if (read(STDIN_FILENO, buf, BUFSIZ) == SYS_ERROR)
        return NULL;
    line_array = my_str_to_word_array(buf, seps);
    return get_valid_part(line_array);
}

static int start_algo(linked_list_t *rooms, char **connections, char **data)
{
    int **link_array = NULL;
    path_list_t *path_list = NULL;

    link_array = init_map(connections, rooms);
    path_list = get_path_list(data, rooms, link_array);
    if (!path_list) {
        print_str_array(data);
        return ERROR;
    }
    print_basic_output(rooms, data, connections, path_list);
    return SUCCESS;
}

int amazed(void)
{
    char **data = get_input();
    linked_list_t *rooms = NULL;
    char **connections = NULL;

    if (!data)
        return ERROR;
    rooms = get_rooms(data);
    connections = get_connections(data);
    if (!rooms || !connections[0]) {
        print_str_array(data);
        return ERROR;
    }
    return start_algo(rooms, connections, data);
}
