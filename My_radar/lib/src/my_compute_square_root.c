/*
** EPITECH PROJECT, 2025
** POINTEURS
** File description:
** Square root
*/

int my_compute_square_root(int nb)
{
    int countsquare = 0;
    int odd = 1;

    if (nb < 0)
        return 0;
    while (nb >= odd) {
        nb -= odd;
        odd += 2;
        countsquare++;
    }
    return countsquare;
}
