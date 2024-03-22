/*
** EPITECH PROJECT, 2024
** AMAZED
** File description:
** Functions related to link list
*/

#include <stdlib.h>
#include "amazed.h"

int add_to_queue(linked_list_t **queue, node_t *node)
{
    linked_list_t *element = malloc(sizeof(linked_list_t));

    element->node = node;
    element->next = *queue;
    *queue = element;
    return SUCCESS;
}

unsigned int get_list_size(linked_list_t *list)
{
    unsigned int size = 0;

    while (list != NULL) {
        size++;
        list = list->next;
    }
    return size;
}

void display_list_name(linked_list_t *list)
{
    my_putstr("NULL");
    while (list) {
        mini_printf(" -> %s", list->node->name);
        list = list->next;
    }
    my_putchar('\n');
}
