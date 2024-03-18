/*
** EPITECH PROJECT, 2023
** MY_STRLEN
** File description:
** count char of string
*/

#include <stddef.h>
#include "my.h"

int my_strlen_banned_chars(char *str, char *banned_chars)
{
    int i = 0;
    int cpt = 0;

    while (str[i] != '\0') {
        if (my_char_in_str(str[i], banned_chars))
            cpt++;
        i++;
    }
    return i - cpt;
}

int my_strlen(char const *str)
{
    size_t i = 0;

    while (str[i] != '\0')
        i++;
    return i;
}
