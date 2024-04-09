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
    for (int i = 0; connections[i] != NULL; i++)
        mini_printf("%s\n", connections[i]);
}

static void print_rooms_reverse(linked_list_t *rooms)
{
    if (rooms == NULL)
        return;
    print_rooms_reverse(rooms->next);
    if (rooms->node->start)
            mini_printf("##start\n");
    if (rooms->node->end)
        mini_printf("##end\n");
    mini_printf("%s %d %d\n", rooms->node->name, rooms->node->x,
        rooms->node->y);
}

void print_basic_output
(linked_list_t *rooms, char **data, char **connections, path_list_t *path_list)
{
    linked_list_t *rooms_cpy = rooms;

    mini_printf("#number_of_robots\n%s\n", data[0]);
    mini_printf("#rooms\n");
    print_rooms_reverse(rooms_cpy);
    mini_printf("#tunnels\n");
    rooms_cpy = rooms;
    print_connections(connections);
    mini_printf("#moves\n");
    move_robots(path_list);
}
