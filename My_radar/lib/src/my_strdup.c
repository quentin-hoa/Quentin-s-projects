/*
** EPITECH PROJECT, 2025
** POINTEURS
** File description:
** copy string
*/

#include "my.h"

char *my_strdup(char *src)
{
    char *result = malloc(my_strlen(src) + 1);

    result = my_strcpy(result, src);
    return result;
}
