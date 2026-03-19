/*
** EPITECH PROJECT, 2025
** My Unsigned Number
** File description:
** My Unsigned Number
*/

#include "../include/my.h"

int my_u_caller(va_list list)
{
    unsigned int n = va_arg(list, unsigned int);

    return my_u(n);
}

int my_u(unsigned int n)
{
    char buffer[12];
    int i = 0;

    if (n == 0) {
        my_c('0');
        return 1;
    }
    while (n > 0) {
        buffer[i] = (n % 10) + '0';
        i++;
        n /= 10;
    }
    buffer[i] = '\0';
    my_revstr(buffer);
    my_s(buffer);
    return i;
}
