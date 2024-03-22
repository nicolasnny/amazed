/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-amazed-enzo.fokwen-rocher
** File description:
** error_handling.c
*/

#include "amazed.h"
#include "my.h"

char **get_valid_part(char *buf)
{
    linked_list_t *rooms = get_rooms(array);
    char **connections = get_connections(array);

    init_map(connections, rooms);
    free_str_array(array);
    free_str_array(connections);
    return SUCCESS;
}

int file_valid(void)
{
    char buf[BUFSIZ] = {0};
    char **line_array;

    if (read(STDIN_FILENO, buf, BUFSIZ) == -1)
        return ERROR;
    line_array = my_str_to_word_array(buf, "\n");
    return stock_file(line_array);
    char **array = my_str_to_word_array(buf, "\n");

    return array;
}
