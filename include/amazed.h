/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-amazed-enzo.fokwen-rocher
** File description:
** amazed.h
*/

#include <stdbool.h>
#include "struct.h"

#ifndef AMAZED_H
    #define AMAZED_H
    #define SUCCESS 0
    #define ERROR 84
    #include "struct.h"

linked_list_t *get_rooms(char **array);
char **get_connections(char **array);
int amazed(void);
char **get_valid_part(char *buf);
int **init_map(char **buffer, linked_list_t *node_list);

#endif /*   A_MAZE_D    */
