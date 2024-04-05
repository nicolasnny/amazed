/*
** EPITECH PROJECT, 2024
** AMAZED
** File description:
** Function to free everything
*/

#include <stddef.h>
#include <stdlib.h>
#include "amazed.h"

int free_queue(linked_list_t *queue)
{
    linked_list_t *next = NULL;

    while (queue != NULL) {
        queue->next = next;
        free(queue);
        queue = next;
    }
    return SUCCESS;
}
