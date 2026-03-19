/*
** EPITECH PROJECT, 2025
** setting up
** File description:
** setting up
*/

#include "my.h"

void first_if(square_t *max, char **map, int **num_map)
{
    if (num_map[max->i][max->j] > max->max_size) {
        max->max_size = num_map[max->i][max->j];
        max->max_i = max->i;
        max->max_j = max->j;
    }
}

void second_if(char **map, square_t *max)
{
    if (map[max->max_i - max->i][max->max_j - max->j] == '.')
        map[max->max_i - max->i][max->max_j - max->j] = 'x';
}

void mark_biggest_square(char **map, int **num_map, int rows, int cols)
{
    square_t *max = {0};

    max = malloc(sizeof(square_t));
    for (max->i = 0; max->i < rows; max->i++) {
        for (max->j = 0; max->j < cols; max->j++) {
            first_if(max, map, num_map);
        }
    }
    if (max->max_size == 0) {
        free(max);
        return;
    }
    for (max->i = 0; max->i < max->max_size; max->i++) {
        for (max->j = 0; max->j < max->max_size; max->j++) {
            second_if(map, max);
        }
    }
    free(max);
}
