/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-amazed-enzo.fokwen-rocher
** File description:
** struct.h
*/

#ifndef STRUCT_H
    #define STRUCT_H

typedef struct node_s {
    int id;
    char *name;
    bool checked;
    struct node_s *parent;
} node_t;

typedef struct linked_list_s {
    node_t *node;
    struct linked_list_s *next;
} linked_list_t;

#endif /*   STRUCT_H    */
