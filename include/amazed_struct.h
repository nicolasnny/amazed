/*
** EPITECH PROJECT, 2024
** AMAZED
** File description:
** Structure of amazed project
*/

#ifndef AMAZED_STRUCT_H
    #define AMAZED_STRUCT_H

typedef struct node_s {
    bool checked;
    struct node_s *parent;
} node_t;

typedef struct linked_list_s {
    node_t *node;
    struct linked_list_s *next;
} linked_list_t;

typedef struct path_s {
    linked_list_t *list;
    unsigned int lenght;
} path_t;

#endif
