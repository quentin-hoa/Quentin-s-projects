/*
** EPITECH PROJECT, 2025
** Day03
** File description:
** Alphabet
*/

#include "../include/my.h"
#include <SFML/Window/Keyboard.h>

void menu(main_t *g)
{
    sfRenderWindow_drawSprite(g->window, g->background->space_sprite, NULL);
    draw_menu(g);
    if (sfKeyboard_isKeyPressed(sfKeyS))
        g->game_state = GAME;
    else if (sfKeyboard_isKeyPressed(sfKeyE))
        g->game_state = EXIT;
}

int game_over(main_t *g)
{
    sfRenderWindow_drawSprite(g->window, g->background->space_sprite, NULL);
    draw_go_text(g);
    if (sfKeyboard_isKeyPressed(sfKeyM))
        return MENU;
    else if (sfKeyboard_isKeyPressed(sfKeyE))
        return EXIT;
}

int next_level(main_t *g)
{
    sfRenderWindow_drawSprite(g->window, g->background->space_sprite, NULL);
    draw_next_level(g);
    if (sfKeyboard_isKeyPressed(sfKeyM))
        return MENU;
    else if (sfKeyboard_isKeyPressed(sfKeyE))
        return EXIT;
    else if (sfKeyboard_isKeyPressed(sfKeyN))
        return NEXT_LEVEl;
    else
        return g->game_state;
}

int check_win(x_wing_t xwing[])
{
    int count = 0;

    for (int i = 0; i < NUM_XWING; i++) {
        if (xwing[i].damage->hp == -1)
        count++;
    }
    if (count == NUM_XWING) {
        return 1;
    }
    return 0;
}
