/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-amazed-enzo.fokwen-rocher
** File description:
** error_handling.c
*/

#include "amazed.h"
#include "my.h"

char **get_valid_part(char *buf)
{
    char **array = my_str_to_word_array(buf, "\n");

    return array;
}
