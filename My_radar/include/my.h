/*
** EPITECH PROJECT, 2025
** Day03
** File description:
** Alphabet
*/

#ifndef _MY_H_
    #define _MY_H_
    #include <SFML/Graphics.h>
    #include <SFML/Graphics/Rect.h>
    #include <SFML/Graphics/Sprite.h>
    #include <SFML/Graphics/Types.h>
    #include <SFML/System/Vector2.h>
    #include <SFML/Audio.h>
    #include <SFML/Audio/Sound.h>
    #include <SFML/Audio/SoundBuffer.h>
    #include <SFML/Audio/Types.h>
    #include <SFML/Audio/Music.h>
    #include <SFML/Audio/SoundStatus.h>
    #include <SFML/Graphics/RenderWindow.h>
    #include <SFML/System/Clock.h>
    #include <SFML/System/Time.h>
    #include <SFML/System/Types.h>
    #include <SFML/Window/Event.h>
    #include <SFML/Window/Mouse.h>
    #include <SFML/Config.h>
    #include <unistd.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <time.h>
    #include <fcntl.h>
    #include <string.h>
    #define ERROR_EPITECH 84
    #define TRUE 1
    #define FALSE 0
    #define MARGE_DESTINATION 2
    #define NMB_STORM 5

int my_printf(char *format, ...);
char *my_strtok(char *str, const char *delim);
char *my_strncpy(char *dest, char const *src, int nb);
int my_atoi(char *str);
int my_compute_square_root(int nb);

typedef struct storm_s {
    sfVector2f postion;
    sfVector2f speed;
    int size;
    sfSprite *storm_srpite;
    sfTexture *storm_texture;
    struct storm_s *next;
} storm_t;

typedef struct airplane_s {
    int x_start;
    int y_start;
    int x_destination;
    int y_destination;
    int speed;
    int delay_take_off;
    int dead;
    int is_mooving;
    int bonus_hitbox;
    sfRectangleShape *hitbox;
    sfVector2f pos;
    sfVector2f direction_vector;
    sfSprite *airplane_srpite;
    sfTexture *texture_airplane;
    struct airplane_s *prev;
    struct airplane_s *next;
} airplane_t;

typedef struct tower_s {
    int x_position;
    int y_position;
    int raduis;
    sfSprite *tower_sprite;
    sfTexture *tower_texture;
    sfCircleShape *circle;
    struct tower_s *prev;
    struct tower_s *next;
} tower_t;


typedef struct main_variables_s {
    sfRenderWindow *window;
    sfEvent event;
    int nb_planes;
    int nb_towers;
    sfClock *clock;
    float delta_time;
    float total_time;
    int l_option;
    int s_option;
    int t_option;
    int r_option;
    int c_option;
    int nb_storms;
    sfText *text_timer;
    sfText *text_end;
    sfText *text_l;
    sfText *text_s;
    sfText *text_t;
    sfText *text_count_p;
    sfText *text_count_s;
    sfFont *font;
    sfMusic *music;
    sfMusic *music_storm;
    sfSprite *background_sprite;
    sfTexture *background_texture;
    tower_t *towers;
    airplane_t *airplane;
    storm_t *array_of_storm[NMB_STORM];
    storm_t *storm;
} main_t;

airplane_t *create_airplaine(char *line, main_t *variables);
tower_t *create_tower(char *line, main_t *variables);
char **my_str_to_word_array(char const *str);
void append_plane(main_t *variables, airplane_t *plane_to_add);
void display_plane(main_t *variables);
void display_tower(tower_t *tower, main_t *variables);
void append_tower(main_t *variables, tower_t *tower_to_add);
void move_plane(main_t *variables);
void check_destination(main_t *variables);
int get_line_to_create_plane(char *path, main_t *variables);
int check_h(char **av, main_t *variables);
void pause_musique(main_t *variables);
void play_music(main_t *variables);
sfVector2f get_direction_vector(int x_start, int y_start, int x_dest,
    int y_dest);
void set_plane_rotation(airplane_t *plane);
void handle_events(main_t *variables, char *path);
int game_finished(main_t *variables);
void init_timer(main_t *variables);
char *my_decimal(int nb);
char *my_strcat(char *dest, char const *src);
void draw_timer(main_t *variables);
void init_end_text(main_t *variables);
void del_node(main_t *variables, airplane_t *plane_to_del);
void colision(main_t *variables);
void init_l_text(main_t *variables);
void init_s_text(main_t *variables);
void draw_l(main_t *variables);
void draw_s(main_t *variables);

typedef struct quad_node_s {
    sfFloatRect area;
    airplane_t *planes[16];
    int nb_planes;
    struct quad_node_s *sub[4];
} quad_node_t;

enum direction
{
    NW,
    NE,
    SW,
    SE
};

void update_colisions(main_t *variables);
void init_storms(main_t *variables);
void move_storms(main_t *variables);
void display_storms(main_t *variables);
void init_t_text(main_t *variables);
void draw_t(main_t *variables);
char *my_strcpy(char *dest, char const *src);
void draw_count_p(main_t *variables);
void init_count_p(main_t *variables);
void draw_count_s(main_t *variables);
void init_count_s(main_t *variables);

#endif
