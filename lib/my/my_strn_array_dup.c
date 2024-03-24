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
    char **array_cpy = malloc(sizeof(char *) * (n + 1));

    for (int i = 0; array[i] && i != n; i++)
        array_cpy[i] = my_strdup(array[i]);
    array_cpy[n] = NULL;
    return array_cpy;
}
