/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-amazed-enzo.fokwen-rocher
** File description:
** amazed.c
*/

#include <stdio.h>
#include <unistd.h>
#include "amazed.h"
#include "struct.h"
#include "my.h"

static char **get_input(void)
{
    char buf[BUFSIZ] = {0};
    char **line_array;

    if (read(STDIN_FILENO, buf, BUFSIZ) == -1)
        return NULL;
    line_array = get_valid_part(buf);
    return line_array;
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
    return SUCCESS;
}
