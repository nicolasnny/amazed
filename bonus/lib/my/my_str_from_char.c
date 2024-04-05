/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-robotfactory-nicolas.nunney
** File description:
** my_str_from_char.c
*/

#include <stdlib.h>
#include "my.h"

char *my_str_from_char(char c)
{
    char *new_str = malloc(sizeof(char) * 2);

    new_str[0] = c;
    new_str[1] = '\0';
    return new_str;
}
