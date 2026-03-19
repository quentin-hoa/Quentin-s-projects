/*
** EPITECH PROJECT, 2025
** Day03
** File description:
** Alphabet
*/

#ifndef _MY_H_
    #define _MY_H_
    #define SIZEBUFFER 1000100
    #include <unistd.h>
    #include <stdarg.h>
    #include <stdarg.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <fcntl.h>
    #include <sys/stat.h>
    #include <sys/types.h>
    #include <dirent.h>
    #define ERROR_FILE "no such file or directory"


int my_printf(char *format, ...);
int my_atoi(char *str);
char *my_strdup(char *str);
int is_apha_char(char c);
int is_number(char c);
int mini_three(int a, int b, int c);
int my_atoi_c(char c);
int my_strcmp(char *s1, char *s2);
char *erase_first_line(char *matrix);
char *read_file(char *path);
void malloc_twod_array(char **twod_array, int nb_lines, int nb_col);
char **oned_to_twod(char *matrix);
int get_col(char *matrix);
int get_lines(char *matrix);
void mark_biggest_square(char **map, int **num_map, int rows, int cols);
void fill_map_of_number(int i, int j, char **map, int **map_of_number);
int **find_bigest_square(char **map, int **map_of_number, int row, int col);
void print_map_number(char **map, int row, int col);
char **generate_map(char *number, char *seed);
int my_strlen(char *str);
void call_algorithm_for_home_made_map(char *size, char **map);
void free_all(char **map, int **map_of_number, int size);

typedef struct square_s {
    int max_j;
    int max_i;
    int i;
    int j;
    int max_size;
} square_t;
void first_if(square_t *max, char **map, int **num_map);
void second_if(char **map, square_t *max);
void mark_biggest_square(char **map, int **num_map, int rows, int cols);
int error(int size, char *seed, int ac);
int get_size(char *path);

#endif /* _MY_H_ */
