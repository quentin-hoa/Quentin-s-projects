/*
** EPITECH PROJECT, 2025
** setting up
** File description:
** setting up
*/

#include "my.h"

void call_algorithm_for_home_made_map(char *size, char **map)
{
    int size_int = my_atoi(size);
    int **map_of_number = malloc(size_int * sizeof(int *));

    for (int k = 0; k < size_int; k++) {
        map_of_number[k] = malloc(size_int * sizeof(int));
    }
    find_bigest_square(map, map_of_number, size_int, size_int);
    mark_biggest_square(map, map_of_number, size_int, size_int);
    print_map_number(map, size_int, size_int);
    free_all(map, map_of_number, size_int);
    free(map);
    free(map_of_number);
}

char **generate_map(char *number, char *seed)
{
    int len = my_strlen(seed);
    int size = my_atoi(number);
    int index;
    int add = 0;
    int j;
    char **map = malloc(size * sizeof(char *));

    for (int k = 0; k < size; k++) {
        map[k] = malloc(size + 1);
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            index = add % len;
            map[i][j] = seed[index];
            add++;
        }
        map[i][size] = '\0';
    }
    return map;
}

int error(int size, char *seed, int ac)
{
    if (ac < 3)
        return 84;
    if (seed[0] == '\0')
        return 84;
    if (size < 0) {
        return 84;
    }
    if (size >= 5000) {
        return 84;
    }
    for (int i = 0; seed[i] != '\0'; i++) {
        if (seed[i] != '.' && seed[i] != 'o')
            return 84;
    }
    return 0;
}

void free_all(char **map, int **map_of_number, int size)
{
    for (int k = 0; k < size; k++) {
        free(map[k]);
        free(map_of_number[k]);
    }
}
