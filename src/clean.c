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

static void free_path(linked_list_t *list)
{
    linked_list_t *next = NULL;

    while (list != NULL) {
        next = list->next;
        free(list);
        list = next;
    }
}

static void free_robots(path_list_t *path_list)
{
    robot_list_t *next = NULL;
    path_list_t *pnext = NULL;

    while (path_list != NULL) {
        while (path_list->robots != NULL) {
            free(path_list->robots->robot->path);
            free(path_list->robots->robot->next_room);
            free(path_list->robots->robot);
            next = path_list->robots->next;
            free(path_list->robots);
            path_list->robots = next;
        }
        pnext = path_list->next;
        free_path(path_list->path);
        free(path_list);
        path_list = pnext;
    }
}

static void free_rooms(linked_list_t *rooms)
{
    linked_list_t *next = NULL;

    while (rooms != NULL) {
        free(rooms->node->name);
        free(rooms->node);
        next = rooms->next;
        free(rooms);
        rooms = next;
    }
}

void main_free(linked_list_t *rooms, path_list_t *path_list)
{
    free_robots(path_list);
    free_rooms(rooms);
}
