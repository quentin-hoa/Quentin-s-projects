/*
** EPITECH PROJECT, 2025
** Printf
** File description:
** add 0 to the left for int
*/

#include "../include/my.h"

int my_b_caller(va_list list)
{
    int nb = va_arg(list, int);

    return my_b(nb);
}

int my_b(int nb)
{
    char hexa[] = "01";
    int nbcopy;
    int count = 0;

    if (nb >= 2)
        count += my_b(nb / 2);
    nbcopy = nb % 2;
    count += my_c(hexa[nbcopy]);
    return count;
}
