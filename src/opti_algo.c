/*
** EPITECH PROJECT, 2024
** AMAZED
** File description:
** Functions related to opti for the algo
*/

#include <stdbool.h>

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
            list->node->visited = true;
        list = list->next;
    }
}

void set_map_to_find_new_path(linked_list_t *nodes, linked_list_t **paths)
{
    if (paths == NULL)
        return;
    reset_all_node(nodes);
    for (unsigned int i = 0; paths[i] != NULL; i++)
        set_path_as_visited(paths[i]);
}
