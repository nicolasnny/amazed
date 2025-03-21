/*
** EPITECH PROJECT, 2023
** temp my_str_isnum
** File description:
** returns 1 if the string passed as parameter only contains
** digits and 0 otherwise
*/

#include <stdbool.h>

static int is_num(char c)
{
    return (c >= '0' && c <= '9');
}

bool my_str_isnum(char const *str)
{
    for (int i = 0; str[i]; i++) {
        if (!is_num(str[i]))
            return false;
    }
    return true;
}
