/*
** EPITECH PROJECT, 2025
** Day03
** File description:
** Alphabet
*/

#include "../include/my.h"
#include <SFML/Graphics/Text.h>

int check_help(void)
{
    write(1, "Welcome to Star Wars: Astro Defense!\n\n", 39);
    write(1, "This game is similar to Duck Hunt, but you play as an ", 55);
    write(1, "Imperial pilot commanding a TIE fighter. ", 41);
    write(1, "Your mission is to shoot down the Rebel X-Wings flying ", 57);
    write(1, "across your field of view.\n", 27);
    write(1, "Use the mouse to aim and the left click to shoot.\n", 51);
    write(1, "Will you manage to shoot them all down before running ", 53);
    write(1, "out of ammo? \n", 14);
    return 0;
}

sfText *set_font(main_t *g)
{
    sfText *text = sfText_create();
    g->font = sfFont_createFromFile("./content/font_h.TTF");

    sfText_setFont(text, g->font);
    sfText_setPosition(text, (sfVector2f){780, 970});
    sfText_setCharacterSize(text, 30);
    return text;
}

void draw_munitions(main_t *g)
{
    char *number = my_decimal(g->munitions);
    char muni[14];
    char *phrase = NULL;

    my_strcpy(muni, "MUNITIONS :");
    phrase = my_strcat(muni, number);
    sfText_setString(g->text_munitions, phrase);
    sfRenderWindow_drawText(g->window, g->text_munitions, NULL);
}

sfText *set_level_text(void)
{
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("./content/font_h.TTF");

    sfText_setFont(text, font);
    sfText_setPosition(text, (sfVector2f){20, 20});
    sfText_setCharacterSize(text, 30);
    return text;
}

void draw_levels(main_t *g)
{
    char *number = my_decimal(g->level);
    char muni[11];
    char *phrase = NULL;

    my_strcpy(muni, "LEVEL : ");
    phrase = my_strcat(muni, number);
    sfText_setString(g->text_level, phrase);
    sfRenderWindow_drawText(g->window, g->text_level, NULL);
}


void init_text_game_over(main_t *g)
{
    g->text_g_over = sfText_create();
    sfText_setFont(g->text_g_over, g->font);
    sfText_setCharacterSize(g->text_g_over, 50);
    sfText_setPosition(g->text_g_over, (sfVector2f){500, 500});

}

void draw_go_text(main_t *g)
{
    sfText_setString(g->text_g_over, "\tGAME OVER\n\n\nPress 'm' to go to menu\n\nPress 'e' to exit");
    sfRenderWindow_drawText(g->window, g->text_g_over, NULL);
}

void init_text_next_lv(main_t *g)
{
    g->text_next_lvl = sfText_create();
    sfText_setFont(g->text_next_lvl, g->font);
    sfText_setCharacterSize(g->text_next_lvl, 50);
    sfText_setPosition(g->text_next_lvl, (sfVector2f){500, 500});
}

void draw_next_level(main_t *g)
{
    sfText_setString(g->text_next_lvl, "YOU PASSED THE LEVEL\n\n\nPress 'm' to go to menu\n\nPress 'n' to next lvl\n\nPress 'e' to exit");
    sfRenderWindow_drawText(g->window, g->text_next_lvl, NULL);
}

void init_text_menu(main_t *g)
{
    g->text_menu = sfText_create();
    sfText_setFont(g->text_menu, g->font);
    sfText_setCharacterSize(g->text_menu, 50);
    sfText_setPosition(g->text_menu, (sfVector2f){500, 500});

}

void draw_menu(main_t *g)
{
    sfText_setString(g->text_menu, "Press 's' to go to start\n\nPress 'e' to exit");
    sfRenderWindow_drawText(g->window, g->text_menu, NULL);
}