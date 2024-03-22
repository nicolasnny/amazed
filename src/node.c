/*
** EPITECH PROJECT, 2024
** AMAZED
** File description:
** Functions related to node handling
*/

#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include "amazed.h"

node_t *get_element_in_queue(linked_list_t *queue)
{
    linked_list_t *prev = NULL;
    node_t *node = NULL;

    if (queue == NULL)
        return NULL;
    while (queue->next != NULL) {
        prev = queue;
        queue = queue->next;
    }
    if (prev != NULL)
        prev->next = NULL;
    node = queue->node;
    free(queue);
    return node;
}

node_t *get_node_from_id(linked_list_t *list, int id)
{
    while (list != NULL && list->node->id != id)
        list = list->next;
    if (list == NULL)
        return NULL;
    return list->node;
}

void set_as_visited(node_t *node, node_t *parent)
{
    if (node == NULL)
        return;
    node->checked = true;
    node->parent = parent;
}
