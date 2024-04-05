/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-amazed-enzo.fokwen-rocher
** File description:
** struct.h
*/

#ifndef STRUCT_H
    #define STRUCT_H
    #include <stdbool.h>

typedef struct node_s {
    int id;
    char *name;
    bool checked;
    bool start;
    bool end;
    struct node_s *parent;
} node_t;

typedef struct linked_list_s {
    node_t *node;
    struct linked_list_s *next;
} linked_list_t;

enum room_type {
    Start,
    Middle,
    End
};

#endif /*   STRUCT_H    */
