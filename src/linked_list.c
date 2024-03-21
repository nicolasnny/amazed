/*
** EPITECH PROJECT, 2024
** AMAZED
** File description:
** Functions related to link list
*/

#include <stdlib.h>
#include "amazed.h"

int add_to_queue(linked_list_t *queue, node_t *node)
{
    linked_list_t *element = malloc(sizeof(linked_list_t));

    element->node = node;
    element->next = queue;
    queue = element;
    return SUCCESS;
}
