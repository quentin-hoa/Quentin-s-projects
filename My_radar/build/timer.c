/*
** EPITECH PROJECT, 2025
** My_radar
** File description:
** timer
*/

#include "my.h"
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Text.h>

void init_timer(main_t *variables)
{
    variables->text_timer = sfText_create();
    variables->font = sfFont_createFromFile("./content/font.ttf");
    sfText_setFont(variables->text_timer, variables->font);
    sfText_setPosition(variables->text_timer, (sfVector2f){1830, 20});
    sfText_setCharacterSize(variables->text_timer, 30);
}

void draw_timer(main_t *variables)
{
    int min = (int)variables->total_time / 60;
    int sec = (int)variables->total_time % 60;
    char *minutes = my_decimal((int)variables->total_time / 60);
    char *secondes = my_decimal((int)variables->total_time % 60);
    char *timer = malloc(5);

    timer[0] = '\0';
    if (min < 10)
        timer = my_strcat(timer, "0");
    timer = my_strcat(timer, minutes);
    timer = my_strcat(timer, ":");
    if (sec < 10)
        timer = my_strcat(timer, "0");
    timer = my_strcat(timer, secondes);
    sfText_setString(variables->text_timer, timer);
    sfRenderWindow_drawText(variables->window, variables->text_timer, NULL);
}

void init_end_text(main_t *variables)
{
    variables->text_end = sfText_create();
    sfText_setFont(variables->text_end, variables->font);
    sfText_setPosition(variables->text_end, (sfVector2f){250, 300});
    sfText_setCharacterSize(variables->text_end, 100);
}


void init_l_text(main_t *variables)
{
    variables->text_l = sfText_create();
    sfText_setFont(variables->text_l, variables->font);
    sfText_setPosition(variables->text_l, (sfVector2f){100, 20});
    sfText_setCharacterSize(variables->text_l, 50);
}

void init_s_text(main_t *variables)
{
    variables->text_s = sfText_create();
    sfText_setFont(variables->text_s, variables->font);
    sfText_setPosition(variables->text_s, (sfVector2f){700, 20});
    sfText_setCharacterSize(variables->text_s, 50);
}

void draw_l(main_t *variables)
{
    sfText_setString(variables->text_l, "OPTION \"L\" ACTIVATED");
    sfRenderWindow_drawText(variables->window, variables->text_l, NULL);
}

void draw_s(main_t *variables)
{
    sfText_setString(variables->text_s, "OPTION \"S\" ACTIVATED");
    sfRenderWindow_drawText(variables->window, variables->text_s, NULL);
}

void init_t_text(main_t *variables)
{
    variables->text_t = sfText_create();
    sfText_setFont(variables->text_t, variables->font);
    sfText_setPosition(variables->text_t, (sfVector2f){1200, 20});
    sfText_setCharacterSize(variables->text_t, 50);
}

void draw_t(main_t *variables)
{
    sfText_setString(variables->text_t, "OPTION \"T\" ACTIVATED");
    sfRenderWindow_drawText(variables->window, variables->text_t, NULL);
}

void init_count_p(main_t *variables)
{
    variables->text_count_p = sfText_create();
    sfText_setFont(variables->text_count_p, variables->font);
    sfText_setPosition(variables->text_count_p, (sfVector2f){100, 950});
    sfText_setCharacterSize(variables->text_count_p, 50);
}

void draw_count_p(main_t *variables)
{
    char *number = my_decimal(variables->nb_planes);
    char muni[14];
    char *phrase = NULL;

    my_strcpy(muni, "PLANES :");
    phrase = my_strcat(muni, number);
    sfText_setString(variables->text_count_p, phrase);
    sfRenderWindow_drawText(variables->window, variables->text_count_p, NULL);
}

void init_count_s(main_t *variables)
{
    variables->text_count_s = sfText_create();
    sfText_setFont(variables->text_count_s, variables->font);
    sfText_setPosition(variables->text_count_s, (sfVector2f){1300, 950});
    sfText_setCharacterSize(variables->text_count_s, 50);
}

void draw_count_s(main_t *variables)
{
    char *number = my_decimal(variables->nb_storms);
    char muni[14];
    char *phrase = NULL;

    my_strcpy(muni, "STORMS :");
    phrase = my_strcat(muni, number);
    sfText_setString(variables->text_count_s, phrase);
    sfRenderWindow_drawText(variables->window, variables->text_count_s, NULL);
}
