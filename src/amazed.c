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

static input_t *new_node_input(void)
{
    input_t *input = malloc(sizeof(input_t));

    input->next = NULL;
    input->buffer = NULL;
    return input;
}

static int input_size(input_t *input)
{
    input_t *input_cpy = input;
    int res = 0;

    while (input_cpy) {
        res += 1;
        input_cpy = input_cpy->next;
    }
    return res;
}

static int get_line_size(char **buffer, size_t *buffer_size)
{
    int line_size = getline(buffer, buffer_size, stdin);

    if (line_size == 1)
        return 0;
    return line_size;
}

static input_t *retrieve_input(void)
{
    input_t *input_og = new_node_input();
    input_t *input = input_og;
    input_t *save_node = NULL;
    __ssize_t line_size = 0;
    size_t buffer_size = 0;
    char *buffer = NULL;

    while (line_size != -1) {
        line_size = get_line_size(&buffer, &buffer_size);
        if (line_size != -1 && my_strcmp(buffer, "\n") != 0) {
            buffer[line_size - 1] = '\0';
            input->buffer = my_strdup_banned_chars(buffer, "\n");
            input->next = new_node_input();
            save_node = input;
            input = input->next;
        }
        if (line_size == -1 && my_strcmp(buffer, "\n") != 0)
            save_node->next = NULL;
    }
    return input_og;
}

static char **get_input(void)
{
    input_t *input = retrieve_input();
    int InputSize = input_size(input);
    char **res = malloc(sizeof(char *) * (InputSize + 1));
    input_t *temp = input;

    res[InputSize] = NULL;
    for (int i = 0; temp && temp->buffer != NULL; i++) {
        res[i] = my_strdup(temp->buffer);
        temp = temp->next;
    }
    return res;
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
