/*
** EPITECH PROJECT, 2023
** MY.H
** File description:
** Write your my.h header file that contains the prototypes
** of all the functions exposed by your libmy.a
*/

#ifndef MY_H
    #define MY_H
    #include <stdbool.h>

int my_putchar(char);
int my_putchar_err(char);
int my_putstr(char const *str);
int my_putstr_err(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
void my_sort_int_array(int *tab, int size);
char *my_strcpy(char *dest, char const *src);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strcat(char *dest, char const *src);
int my_strstrlen(char **str);
char **my_str_to_word_array(char *str_buf, char *delim);
int mini_printf(char const *format, ...);
char *my_strdup(char *src);
char **my_str_array_dup(char **array);
char **my_str_array_cpy(char **array, char **array_cpy);
void print_str_array(char **array);
void free_str_array(char **array);
int my_strncmp_banned_char(char const *s1, char const *s2, int n,
    char banned_char);
char *my_strdup_banned_chars(char *src, char *banned_chars);
int my_strlen_banned_chars(char *str, char *banned_chars);
bool my_char_in_str(char c, char *str);
char *my_str_from_char(char c);
void my_free_n_str(int nb_of_str, ...);
char **my_strn_array_dup(int n, char **array);
bool my_str_isnum(char const *str);

#endif /*MY_H*/
