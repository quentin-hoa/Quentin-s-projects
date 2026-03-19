/*
** EPITECH PROJECT, 2025
** Day03
** File description:
** Alphabet
*/

#ifndef _MY_H_
    #define _MY_H_
    #define SIZEBUFFER 16000
    #include <unistd.h>
    #include <stdarg.h>
    #include <stdarg.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <sys/stat.h>
    #include <sys/types.h>
    #include <dirent.h>
    #include <time.h>
    #include <pwd.h>
    #include <grp.h>
    #include <stddef.h>
    #define NUMBER_OF_SP 15
    #define NUMBER_OF_FLAGS 3
    #define NBR_OPTIONS 5
//printf part ------------------------------------
typedef struct specifier_s {
    char option;
    int (*fonction_pointer)(va_list list);
} specifier_t;

int my_u_caller(va_list list);
int my_g_caller(va_list list);
int my_s_caller(va_list list);
int my_c_caller(va_list list);
int my_c(char c);
int my_d(int nb);
int my_d_caller(va_list list);
void my_swap(char *a, char *b);
int my_s(char *str);
int my_f(double nb);
int my_f_caller(va_list list);
int my_strlen(char *str);
char *my_strcat(char *dest, char const *src);
int my_e(double nb);
int my_e_caller(va_list list);
int my_ee(double nb);
int my_ee_caller(va_list list);
char *my_revstr(char *str);
int my_xx(int nb);
int my_xx_caller(va_list list);
char *my_xx_char_caller(va_list list);
char *my_xx_char(int nb);
int my_x(int nb);
int my_x_caller(va_list list);
char *my_x_char_caller(va_list list);
char *my_x_char(int nb);
int my_o(int nb);
int my_o_caller(va_list list);
char *my_o_char(int nb);
char *my_o_char_caller(va_list list);
int my_u(unsigned int n);
int my_g(double nb);
int my_plus(int nb);
int my_plus_caller(va_list list);
int my_space(int nb);
int my_space_caller(va_list list);
int my_flag_0(int min, int nb, char *(*fnt_ptr)(int nb));
char *my_decimal(int nb);
int my_p(void *pointeur);
int my_p_caller(va_list list);
int my_b(int nb);
int my_b_caller(va_list list);
int my_printf(char *format, ...);
//--------------------------------------------

typedef struct option_s {
    char option;
    void (*function_ptr)(va_list list);
} option_t;

typedef struct info_file_s {
    int total;
    char file_type;
    char *right;
    int links;
    char *user;
    char *group;
    int size;
    char *date;
    char *file_name;
    struct info_file_s *next;
} info_file_t;

typedef struct flags_s {
    int is_a_flag;
    int is_t_flag;
    int is_R_flag;
    int is_d_flag;
    int is_l_flag;
} flags_t;

char *my_strcpy(char *dest, char const *src);
void my_ls_l(char *path);
void my_ls_d(char *path);
void my_ls_t(char *path);
void my_ls_R(char *path);
void my_ls(char *path);
void my_ls_a(char *path);
char *my_strdup(char *src);
char *my_strncpy(char *dest, char const *src, int nb);


#endif /* _MY_H_ */
