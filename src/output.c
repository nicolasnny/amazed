/*
** EPITECH PROJECT, 2024
** output
** File description:
** all output related func
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "amazed.h"
#include "struct.h"
#include "my.h"

char *id2name(int id, linked_list_t *node_list)
{
    while (node_list) {
        if (id == node_list->node->id)
            return node_list->node->name;
        node_list = node_list->next;
    }
    return NULL;
}

static void print_connections(char **connections)
{
    for (int i = 0; connections[i] != NULL; i++) {
        write(1, connections[i], my_strlen(connections[i]));
        write(1, "\n", 1);
    }
}

static void print_rooms_reverse(linked_list_t *rooms)
{
    if (rooms == NULL)
        return;
    print_rooms_reverse(rooms->next);
    if (rooms->node->start)
            write(1, "##start\n", 8);
    if (rooms->node->end)
        write(1, "##end\n", 6);
    write(1, rooms->node->name, my_strlen(rooms->node->name));
    write(1, " ", 1);
    my_put_nbr(rooms->node->x);
    write(1, " ", 1);
    my_put_nbr(rooms->node->y);
    write(1, "\n", 1);
}

void print_basic_output
(linked_list_t *rooms, char **data, char **connections, path_list_t *path_list)
{
    linked_list_t *rooms_cpy = rooms;

    mini_printf("#number_of_robots\n%s\n", data[0]);
    write(1, "#rooms\n", 7);
    print_rooms_reverse(rooms_cpy);
    write(1, "#tunnels\n", 9);
    rooms_cpy = rooms;
    print_connections(connections);
    write(1, "#moves\n", 7);
    move_robots(path_list);
}
