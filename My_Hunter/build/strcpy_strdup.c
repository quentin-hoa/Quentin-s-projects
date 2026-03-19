/*
** EPITECH PROJECT, 2025
** Day03
** File description:
** Main game loop and structure
*/

#include "../include/my.h"

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    for (i = 0; src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return dest;
}

char *my_strdup(char *src)
{
    char *result = malloc(my_strlen(src) + 1);

    result = my_strcpy(result, src);
    return result;
}
