/*
** EPITECH PROJECT, 2024
** AMAZED
** File description:
** Functions related to opti for the algo
*/

#include <stdbool.h>
#include <stddef.h>
#include "amazed.h"

static void reset_all_node(linked_list_t *nodes)
{
    while (nodes != NULL) {
        nodes->node->checked = false;
        nodes = nodes->next;
    }
}

static void set_path_as_visited(linked_list_t *list)
{
    while (list != NULL) {
        if (!list->node->end && !list->node->start)
            list->node->checked = true;
        list = list->next;
    }
}

void set_map_to_find_new_path(linked_list_t *nodes, path_list_t *paths)
{
    path_list_t *temp;

    if (!paths || !nodes)
        return;
    temp = paths;
    reset_all_node(nodes);
    while (temp) {
        set_path_as_visited(temp->path);
        temp = temp->next;
    }
}
