/*
** EPITECH PROJECT, 2025
** My %g specifier
** File description:
** My %g specifier
*/

#include "../include/my.h"

int my_g_caller(va_list list)
{
    double nb = va_arg(list, double);

    return my_g(nb);
}

int calculate_exponent(double nbcopy)
{
    int exponent = 0;

    if (nbcopy >= 10) {
        while (nbcopy >= 10) {
            nbcopy /= 10;
            exponent++;
        }
    }
    if (nbcopy < 1 && nbcopy > 0) {
        while (nbcopy < 1) {
            nbcopy *= 10;
            exponent--;
        }
    }
    return exponent;
}

int my_g(double nb)
{
    int exponent = 0;
    double nbcopy = nb;
    int count = 0;

    if (nb < 0) {
        count += my_c('-');
        nb = -nb;
        nbcopy = nb;
    }
    if (nbcopy == 0) {
        count += my_c('0');
        return count;
    }
    exponent = calculate_exponent(nbcopy);
    if (exponent < -4 || exponent >= 6) {
        count += my_e(nb);
    } else {
        count += my_f(nb);
    }
    return count;
}
