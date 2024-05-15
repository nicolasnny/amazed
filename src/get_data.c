/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-amazed-enzo.fokwen-rocher
** File description:
** error_handling.c
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "amazed.h"

static void set_node_content(linked_list_t *new_node, char **content_array)
{
    static int id = 0;

    new_node->node = malloc(sizeof(node_t));
    new_node->node->id = id;
    if (!content_array[1] || !content_array[2] || !content_array[0])
        return;
    new_node->node->name = my_strdup(content_array[0]);
    new_node->node->x = my_getnbr(content_array[1]);
    new_node->node->y = my_getnbr(content_array[2]);
    new_node->node->is_occupied = false;
    free_str_array(content_array);
    id++;
}

static linked_list_t *insert_room(linked_list_t *rooms, char **array, int i)
{
    linked_list_t *new_node = malloc(sizeof(linked_list_t));
    char **content_array = my_str_to_word_array(array[i], " \t");

    set_node_content(new_node, content_array);
    new_node->node->start = false;
    new_node->node->end = false;
    if (i > 0 && my_strcmp(array[i - 1], "##start") == 0)
        new_node->node->start = true;
    if (i > 0 && my_strcmp(array[i - 1], "##end") == 0)
        new_node->node->end = true;
    new_node->next = rooms;
    new_node->node->checked = false;
    return new_node;
}

static bool count_name(linked_list_t *rooms, char *name)
{
    linked_list_t *temp = rooms;
    int i = 0;

    while (temp) {
        if (my_strcmp(temp->node->name, name) == 0)
            i++;
        temp = temp->next;
    }
    return i;
}

static bool room_name_unique(linked_list_t *rooms)
{
    linked_list_t *temp = rooms;

    while (temp) {
        if (count_name(rooms, temp->node->name) != 1)
            return false;
        temp = temp->next;
    }
    return true;
}

linked_list_t *get_rooms(char **array)
{
    linked_list_t *rooms = NULL;

    for (int i = 1; array[i]; i++) {
        if (array[i][0] != '#' && !my_char_in_str('-', array[i])) {
            rooms = insert_room(rooms, array, i);
        }
    }
    if (!room_name_unique(rooms))
        return NULL;
    return rooms;
}

static int get_nb_connections(char **array)
{
    int connections_cpt = 0;

    for (int i = 0; array[i]; i++) {
        if (my_char_in_str('-', array[i]))
            connections_cpt++;
    }
    return connections_cpt;
}

char **get_connections(char **array)
{
    char **connections = malloc(sizeof(char *) *
        (get_nb_connections(array) + 1));
    int connections_index = 0;

    for (int i = 0; array[i]; i++) {
        if (my_char_in_str('-', array[i])) {
            connections[connections_index] = my_strdup(array[i]);
            connections_index++;
        }
    }
    connections[connections_index] = NULL;
    return connections;
}
