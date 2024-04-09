/*
** EPITECH PROJECT, 2023
** my_strcmp
** File description:
** Reproduce the behavior of the strcmp function
*/

int find_str(char const *s1, char const *s2)
{
    int i = 0;

    while (s1[i] != '\0' && s2[i] != '\0'){
        if (s1[i] != s2[i]){
            return s1[i] - s2[i];
        }
        i++;
    }
    return 0;
}
