/*
** EPITECH PROJECT, 2023
** my_getnbr
** File description:
** my_getnbr
*/

#include <stdio.h>
#include <stdbool.h>

static int ovf(int a, char b)
{
    if (a > 2147483647 / 10){
        return 1;
    }
    if (a * 10 > 2147483647 - (b - 48))
        return 1;
    return 0;
}

static int check_sign(int i, char const *str)
{
    if (i == 1 && str[i - 1] == '+')
        return 1;
    if (i == 1 && str[i - 1] == '-')
        return -1;
    if (str[i - 1] == '-' && str[i - 2] == '+')
        return -1;
    if (str[i - 1] == '-' && str[i - 2] == '-')
        return 1;
    if (str[i - 1] == '+' && str[i - 2] == '-')
        return -1;
    return 1;
}

static bool valid_number(char const *str)
{
    if (((str[0] < 48) || (str[0] > 57)) && str[0] != '-' && str[0] != '+')
        return false;
    for (int i = 1; str[i] != '\0'; i++) {
        if (str[i] < 48 || str[i] > 57)
            return false;
    }
    return true;
}

static int check_nb_adding(char c, int nb)
{
    if (c >= '0' && c <= '9' && ovf(nb, c) == 0){
        nb *= 10;
        nb += c - 48;
    }
    return nb;
}

int my_getnbr(char const *str)
{
    int nb = 0;
    int sign = 1;
    char tp;

    if (!valid_number(str))
        return 0;
    for (int i = 0; str[i] != '\0'; i++){
        if (str[i] >= '0' && str[i] <= '9' && ovf(nb, str[i]) == 1)
            return 0;
        nb = check_nb_adding(str[i], nb);
        tp = str[i];
        if (i > 0 && str[i - 1] >= 48 && str[i - 1] <= 57 &&
            ((tp < 48) || (tp > 57)))
            return nb * sign;
        if (i > 0 && tp >= 48 && tp <= 57 && ((str[i - 1] == 45) ||
            (str[i - 1] == 43)))
            sign = check_sign(i, str);
    }
    return nb * sign;
}
