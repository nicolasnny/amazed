/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-amazed-enzo.fokwen-rocher
** File description:
** error_handling.c
*/

#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include "amazed.h"

bool valid_robot_quantity(char **array)
{
    int robot_quantity = my_getnbr(array[0]);

    if (robot_quantity <= 0)
        return false;
    return true;
}

static bool check_valid_room(char **line_array, char *room_name)
{
    char **room_data;

    for (int i = 1; line_array[i]; i++) {
        room_data = my_str_to_word_array(line_array[i], " \t");
        if (my_strcmp(room_name, room_data[0]) == 0) {
            free_str_array(room_data);
            return true;
        }
        free_str_array(room_data);
    }
    return false;
}

static bool is_a_connection(char **line_array, bool *end_of_room, int i)
{
    char **connection_array = my_str_to_word_array(line_array[i], "-");

    if (my_strstrlen(connection_array) != 2) {
        free_str_array(connection_array);
        return false;
    }
    for (int i = 0; connection_array[i]; i++) {
        if (!check_valid_room(line_array, connection_array[i])) {
            free_str_array(connection_array);
            return false;
        }
    }
    *end_of_room = true;
    free_str_array(connection_array);
    return true;
}

static bool is_a_room(char **line_array, bool end_of_room, int i)
{
    char **room_content = my_str_to_word_array(line_array[i], " ");

    if (my_strstrlen(room_content) != 3) {
        free_str_array(room_content);
        return false;
    }
    if (!my_str_isnum(room_content[1]) || !my_str_isnum(room_content[2])) {
        free_str_array(room_content);
        return false;
    }
    if (end_of_room) {
        free_str_array(room_content);
        return false;
    }
    free_str_array(room_content);
    return true;
}

static bool is_a_command(char **line_array, bool end_of_room, int i)
{
    if ((my_strcmp(line_array[i], "##start") == 0 ||
        my_strcmp(line_array[i], "##end") == 0) &&
        is_a_room(line_array, end_of_room, i))
        return true;
    if (my_strncmp(line_array[i], "##", 2) == 0)
        return true;
    return false;
}

static bool valid_end(char **line_array, int i, bool end, bool end_of_room)
{
    if (my_strcmp("##end", line_array[i]) != 0)
        return end;
    if (line_array[i + 1] && !is_a_room(line_array, end_of_room, i + 1))
        return false;
    if (end)
        return false;
    return true;
}

static bool valid_start(char **line_array, int i, bool start, bool end_of_room)
{
    if (my_strcmp("##start", line_array[i]) != 0)
        return start;
    if (line_array[i + 1] && !is_a_room(line_array, end_of_room, i + 1))
        return false;
    if (start)
        return false;
    return true;
}

int get_nb_valid_lines(char **line_array)
{
    bool end_of_rooms = false;
    bool start = false;
    bool end = false;

    if (!valid_robot_quantity(line_array))
        return 0;
    for (int i = 1; line_array[i]; i++) {
        if (!is_a_room(line_array, end_of_rooms, i) &&
            !is_a_command(line_array, end_of_rooms, i) &&
                !is_a_connection(line_array,
                    &end_of_rooms, i)) {
            return i;
        }
        start = valid_start(line_array, i, start, end_of_rooms);
        end = valid_end(line_array, i, end, end_of_rooms);
    }
    if (!start || !end)
        return 0;
    return my_strstrlen(line_array);
}

char **get_valid_part(char **line_array)
{
    int nb_valid_lines = get_nb_valid_lines(line_array);
    char **valid_array;

    if (nb_valid_lines == 0)
        return NULL;
    valid_array = my_strn_array_dup(nb_valid_lines, line_array);
    return valid_array;
}
