/*
** EPITECH PROJECT, 2025
** Day03
** File description:
** Main game loop and structure
*/

#include "../include/my.h"

int my_strlen(char *str)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++)
        count++;
    return count;
}

void my_swap1(char *a, char *b)
{
    int temp = *a;

    *a = *b;
    *b = temp;
}

char *my_revstr(char *str)
{
    int count = my_strlen(str) - 1;

    for (int i = 0; i < count; i++) {
        my_swap1(&str[i], &str[count]);
        count--;
    }
    return str;
}

char *my_strcat(char *dest, char const *src)
{
    int lenght = my_strlen(dest);
    int i = 0;

    for (; src[i] != '\0'; i++) {
        dest[i + lenght] = src[i];
    }
    dest[i + lenght] = '\0';
    return dest;
}

char *my_decimal(int nb)
{
    char *result = malloc(10);
    char hexa[] = "0123456789";
    int i = 0;
    int nbcopy;

    do {
        nbcopy = nb % 10;
        result[i] = hexa[nbcopy];
        nb /= 10;
        i++;
    } while (nb != 0);
    result[i] = '\0';
    my_revstr(result);
    return result;
}
