/*
** EPITECH PROJECT, 2025
** My_radar
** File description:
** readfile
*/

#include "my.h"

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

char *read_file(char *path)
{
    int size = get_size(path) + 1;
    char *buff = malloc(size);
    int nb_bytes = 0;
    int fd = open(path, O_RDONLY);

    if (fd == -1)
        return NULL;
    nb_bytes = read(fd, buff, size);
    buff[nb_bytes] = '\0';
    if (buff == NULL || nb_bytes == 0)
        return NULL;
    return buff;
}

void init_towers_planes(char *line, main_t *variables)
{
    if (line[0] == 'A')
        append_plane(variables, create_airplaine(line, variables));
    if (line[0] == 'T')
        append_tower(variables, create_tower(line, variables));
    
}

int good_line(char *line)
{
    if (line[0] == 'A' || line[0] == 'T' || line[0] == 'R')
        return 0;
    return 1;
}

int get_line_to_create_plane(char *path, main_t *variables)
{
    int size = get_size(path);
    char *file = read_file(path);
    char *token;

    if (!file)
        return ERROR_EPITECH;
    token = my_strtok(file, "\n");
    while (token) {
        if (good_line(token) == 1)
            return ERROR_EPITECH;
        init_towers_planes(token, variables);
        token = my_strtok(NULL, "\n");
    }
    free(file);
    return 0;
}
