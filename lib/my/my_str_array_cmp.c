/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-amazed-enzo.fokwen-rocher
** File description:
** my_str_array_cmp.c
*/

#include <stdio.h>
#include "my.h"

bool my_str_array_cmp(char **array1, char **array2)
{
    if (!array1 || !array2)
        return false;
    for (unsigned int i = 0; array1[i]; i++) {
        if (!array2[i] || my_strcmp(array1[i], array2[i]) != 0)
            return false;
    }
    return true;
}
