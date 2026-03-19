/*
** EPITECH PROJECT, 2025
** Day12
** File description:
** task2
*/

#include "my.h"

int error_handling(int ac)
{
    if (ac == 1)
        return 84;
    if (ac > 3)
        return 84;
    return 0;
}

void algorithm(char **map, int **map_of_number, int row, int col)
{
    for (int k = 0; k < row; k++) {
        map_of_number[k] = malloc(col * sizeof(int));
    }
    find_bigest_square(map, map_of_number, row, col);
    mark_biggest_square(map, map_of_number, row, col);
    print_map_number(map, row, col);
}

int main_file_logic(char *filepath)
{
    char *matrix = read_file(filepath);
    char **map = NULL;
    int row = get_lines(matrix);
    int col = get_col(matrix);
    int **map_of_number = NULL;

    if (my_strcmp(matrix, ERROR_FILE) == 0)
        return 84;
    map = oned_to_twod(matrix);
    map_of_number = malloc(row * sizeof(int *));
    if (!map_of_number)
        return 84;
    algorithm(map, map_of_number, row, col);
    free_all(map, map_of_number, row);
    free(map);
    free(map_of_number);
    return 0;
}

int main(int ac, char **av)
{
    int error_code = 0;
    int size;

    error_code = error_handling(ac);
    if (error_code != 0)
        return error_code;
    if (is_apha_char(av[1][0]) == 1) {
        if (main_file_logic(av[1]) != 0)
            return main_file_logic(av[1]);
    }
    if (is_number(av[1][0]) == 1 || av[1][0] == '-') {
        size = my_atoi(av[1]);
        if (error(size, av[2], ac) != 0)
            return 84;
        call_algorithm_for_home_made_map(av[1], generate_map(av[1], av[2]));
    }
    return 0;
}
