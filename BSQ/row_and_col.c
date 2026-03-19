/*
** EPITECH PROJECT, 2025
** Day12
** File description:
** task2
*/

#include "my.h"

int get_lines(char *matrix)
{
    int nb_lines = 0;

    for (int k = 0; matrix[k] != '\0'; k++) {
        if (matrix[k] == '\n')
            nb_lines++;
    }
    return nb_lines;
}

int get_col(char *matrix)
{
    int nb_col = 0;

    if (matrix[0] != '\0') {
        for (int k = 0; matrix[k] != '\n' && matrix[k] != '\0'; k++) {
            nb_col++;
        }
    }
    return nb_col;
}

int get_size(char *path)
{
    int size;
    char buff[1];
    int nb_bytes = 0;
    int fd = open(path, O_RDONLY);
    int i = 0;

    if (fd == -1) {
        return 84;
    }
    nb_bytes = read(fd, buff, 1);
    for (i = 0; nb_bytes != 0; i++) {
        nb_bytes = read(fd, buff, 1);
    }
    close(fd);
    return i;
}
