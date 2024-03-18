/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-robotfactory-nicolas.nunney
** File description:
** my_strn_array_dup.c
*/

#include <stdlib.h>
#include "my.h"

char **my_strn_array_dup(int n, char **array)
{
    char **array_cpy = malloc(sizeof(char *) * (my_strstrlen(array) + 1 - n));
    int index = 0;

    for (int i = 0; array[i]; i++) {
        if (i >= n) {
            array_cpy[index] = my_strdup(array[i]);
            index++;
        }
    }
    array_cpy[my_strstrlen(array) - n] = NULL;
    return array_cpy;
}
