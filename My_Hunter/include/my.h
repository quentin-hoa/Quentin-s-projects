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
    #include <unistd.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <time.h>
    #define FULL_LIFE 0
    #define MID_LIFE 1
    #define ALMOST_DEAD 2
    #define DEAD 3
    #define PLAY_AREA_X_MIN 162.0
    #define PLAY_AREA_Y_MIN 50.0
    #define PLAY_AREA_SIZE 700.0
    #define NUM_XWING 8

typedef struct damage_s {
    int hp;
    int state;
    int dying_animation;
} damage_t;

typedef struct x_wing_s {
    sfSprite *sprite;
    sfTexture *texture_sheet;
    sfIntRect rect_spirte;
    sfVector2f speed;
    int level;
    damage_t *damage;
    sfVector2f scale;
} x_wing_t;

typedef struct background_s {
    sfSprite *cockipt_sprite;
    sfTexture *cockpit_texture;
    sfTexture *space;
    sfSprite *space_sprite;
} background_t;

typedef struct number_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect rect_sprite;
} number_t;

typedef struct game_variables_s {
    sfRenderWindow *window;
    sfEvent event;
    sfTexture *game_over_tex;
    sfSprite *game_over_sprite;
    sfMusic *home_music;
    sfMusic *space_music;
    sfText *text_munitions;
    sfText *text_level;
    sfText *text_next_lvl;
    sfText *text_g_over;
    sfText *text_menu;
    sfFont *font;
    x_wing_t x_wing_array[NUM_XWING];
    damage_t damage_array[NUM_XWING];
    int game_state;
    int level;
    int munitions;
    background_t *background;
    sfSoundBuffer *shoot_buffer;
    sfSound *shoot_sound;
    sfTexture *texture_sheet;
} main_t;

void update_xwing_sprite(x_wing_t *xwing);
void hit_xwing(x_wing_t *xwing);
void move_xwing(x_wing_t *xwing, float time, int window_with,
    int window_height);
void handle_click(x_wing_t *xwing, int mouse_x, int mouse_y);
int check_win(x_wing_t xwing[]);
int game_over(main_t *g);
void menu(main_t *g);
int next_level(main_t *g);
void display_ammo_icons(number_t *ammo_icon, int munitions,
    sfRenderWindow *window);
char *my_decimal(int nb);
char *my_strdup(char *src);
int check_help(void);
typedef struct text_s {
    sfFont *font;
    sfText *text;
    char *munitions;
} text_t;
sfText *set_font(main_t *g);
char *my_strcat(char *dest, char const *src);
void draw_munitions(main_t *g);
char *my_strcpy(char *dest, char const *src);
sfText *set_level_text(void);

typedef struct game_assets_s {
    sfTexture *cockpit;
    sfSprite *cockpit_sprite;
    sfTexture *space;
    sfSprite *space_sprite;
    sfClock *clock;
} game_assets_t;
char *my_strcpy(char *dest, char const *src);
char *my_strdup(char *src);
int my_strlen(char *str);
void update_xwing_sprite(x_wing_t *xwing);
void hit_xwing(x_wing_t *xwing);
void handle_click(x_wing_t *xwing, int mouse_x, int mouse_y);
int check_button_click(sfRenderWindow* window, sfEvent *event,
    int current_state);
void init_xwing_params(x_wing_t *xwing, int window_width, int level);
void init_next_level(x_wing_t *xwing, int window_width, int level, main_t *g);
void cleanup_xwing_resources(main_t *g);
void destroy_game_assets(main_t *g);
background_t *init_background();
void sound_shoot(main_t *variables);
void init_sound_shoot(main_t *variables);
void initialistion_xwing(x_wing_t *xwing, int window_width, main_t *g);
void init_enemies(main_t *g);
int game_function(main_t *g, sfEvent *event);
void draw_levels(main_t *g);
void init_text_game_over(main_t *g);
void draw_go_text(main_t *g);
void init_text_next_lv(main_t *g);
void draw_next_level(main_t *g);
void init_text_menu(main_t *g);
void draw_menu(main_t *g);


enum game_state {
    MENU,
    GAME,
    GAMEOVER,
    EXIT,
    WON_LEVEL,
    NEXT_LEVEl
};
#endif /* _MY_H_ */
