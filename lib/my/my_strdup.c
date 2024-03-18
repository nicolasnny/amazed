/*
** EPITECH PROJECT, 2023
** B-PSU-200-PAR-2-1-minishell1-nicolas.nunney
** File description:
** my_strdup.c
*/

#include <stdbool.h>
#include <stdlib.h>
#include "my.h"

char *my_strdup_banned_chars(char *src, char *banned_chars)
{
    int i = 0;
    int new_str_index = 0;
    char *dest = malloc(sizeof(char) *
        my_strlen_banned_chars(src, banned_chars) + 1);

    while (src[i] != '\0') {
        if (!my_char_in_str(src[i], banned_chars)) {
            dest[new_str_index] = src[i];
            new_str_index++;
        }
        i++;
    }
    dest[new_str_index] = '\0';
    return dest;
}

char *my_strdup(char *src)
{
    int i = 0;
    char *dest = malloc(sizeof(char) * my_strlen(src) + 1);

    if (!dest)
        return NULL;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}
