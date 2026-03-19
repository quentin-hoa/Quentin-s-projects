/*
** EPITECH PROJECT, 2025
** setting up
** File description:
** setting up
*/

#include "my.h"

char *erase_first_line(char *matrix)
{
    int count = 0;

    for (int i = 0; matrix[i] != '\n'; i++) {
        count++;
    }
    return (matrix + count + 1);
}

char *read_file(char *path)
{
    int size = get_size(path) + 1;
    char *buff = malloc(size);
    int nb_bytes = 0;
    int fd = open(path, O_RDONLY);
    char *matrix;

    if (fd == -1)
        return ERROR_FILE;
    nb_bytes = read(fd, buff, size);
    buff[nb_bytes] = '\0';
    if (buff == NULL || nb_bytes == 0)
        return ERROR_FILE;
    matrix = my_strdup(erase_first_line(buff));
    for (int i = 0; matrix[i] != '\0'; i++) {
        if (matrix[i] != '.' && matrix[i] != 'o' && matrix[i] != '\n')
            return ERROR_FILE;
    }
    return matrix;
}

void malloc_twod_array(char **twod_array, int nb_lines, int nb_col)
{
    for (int k = 0; k < nb_lines; k++) {
        twod_array[k] = malloc(nb_col + 1);
    }
}

void last_back_slash_zero(int row_i, int col_i, char **result, int nb_lines)
{
    if (row_i < nb_lines)
        result[row_i][col_i] = '\0';
}

char **oned_to_twod(char *matrix)
{
    int nb_lines = get_lines(matrix);
    int nb_col = get_col(matrix);
    int m_i = 0;
    int row_i = 0;
    int col_i = 0;
    char **result = malloc(nb_lines * sizeof(char *));

    malloc_twod_array(result, nb_lines, nb_col);
    for (m_i = 0; matrix[m_i] != '\0'; m_i++) {
        if (matrix[m_i] == '\n') {
            result[row_i][col_i] = '\0';
            row_i++;
            col_i = 0;
        } else {
            result[row_i][col_i] = matrix[m_i];
            col_i++;
        }
    }
    last_back_slash_zero(row_i, col_i, result, nb_lines);
    return result;
}
