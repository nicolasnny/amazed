/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-amazed-enzo.fokwen-rocher
** File description:
** error_handling.c
*/

#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include "amazed.h"

bool valid_robot_quantity(char **array)
{
    int robot_quantity = my_getnbr(array[0]);

    if (robot_quantity <= 0)
        return false;
    return true;
}

char **get_valid_part(char **line_array)
{
    if (!valid_robot_quantity(line_array))
        return NULL;
    return line_array;
}
