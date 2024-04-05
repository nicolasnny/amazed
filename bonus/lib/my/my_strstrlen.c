/*
** EPITECH PROJECT, 2023
** MY LIB
** File description:
** Returns the lengh of a string of string
*/

#include <stdlib.h>

int my_strstrlen(char **array)
{
    int len = 0;

    while (array[len])
        len++;
    return len;
}
