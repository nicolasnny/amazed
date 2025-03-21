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

static int get_line_size(size_t *line_size, char **buffer,
    size_t *buffer_size)
{
    *line_size = getline(buffer, buffer_size, stdin);
    if (*line_size == 1)
        return 0;
    if (*line_size == 0)
        return 1;
    return *line_size;
}

static input_t *retrieve_input(void)
{
    input_t *input_og = new_node_input();
    input_t *input = input_og;
    input_t *save_node = NULL;
    size_t line_size = 0;
    size_t buffer_size = 0;
    char *buffer = NULL;

    while (get_line_size(&line_size, &buffer, &buffer_size) != -1) {
        if (buffer && my_strcmp(buffer, "\n") != 0) {
            buffer[line_size] = '\0';
            input->buffer = my_strdup(buffer);
            input->next = new_node_input();
            save_node = input;
            input = input->next;
        }
    }
    if ((int)line_size == -1 && save_node)
        save_node->next = NULL;
    return input_og;
}

static char **get_input(void)
{
    input_t *input = retrieve_input();
    char *res = malloc(sizeof(char));
    char **final_array = NULL;
    input_t *temp = input;

    res[0] = '\0';
    for (int i = 0; temp && temp->buffer != NULL; i++) {
        res = my_strcat(res, temp->buffer);
        temp = temp->next;
    }
    final_array = my_str_to_word_array(res, "\n");
    free_input(input);
    return get_valid_part(final_array);
}

static int start_algo(linked_list_t *rooms, char **connections, char **data)
{
    int **link_array = NULL;
    path_list_t *path_list = NULL;

    link_array = init_map(connections, rooms);
    path_list = get_path_list(data, rooms, link_array);
    if (!path_list) {
        print_str_array(data);
        main_free(rooms, path_list, data);
        return ERROR;
    }
    print_basic_output(rooms, data, connections, path_list);
    main_free(rooms, path_list, data);
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
        free_str_array(data);
        return ERROR;
    }
    return start_algo(rooms, connections, data);
}
