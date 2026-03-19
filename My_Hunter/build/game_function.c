/*
** EPITECH PROJECT, 2025
** Day03
** File description:
** Alphabet
*/

#include "../include/my.h"

static void first_loop(sfRenderWindow *window, sfEvent *event,
    x_wing_t xwing[], float time)
{
    for (int i = 0; i < NUM_XWING; i++) {
        if (event->type == sfEvtMouseButtonPressed &&
            event->mouseButton.button == sfMouseLeft) {
            handle_click(&xwing[i], event->mouseButton.x,
                event->mouseButton.y);
        }
        move_xwing(&xwing[i], time, 1920, 1080);
    }
}

static void second_loop(sfRenderWindow *window, x_wing_t xwing[])
{
    for (int i = 0; i < NUM_XWING; i++){
            sfRenderWindow_drawSprite(window, xwing[i].sprite, NULL);
            if (xwing[i].damage->hp == -1)
                sfSprite_setColor(xwing[i].sprite, (sfColor){0, 0, 0, 0});
    }
}

int game_function(main_t *g, sfEvent *event)
{
    static sfClock *clock = NULL;
    float time;

    if (clock == NULL)
        clock = sfClock_create();
    time = sfTime_asSeconds(sfClock_restart(clock));
    first_loop(g->window, event, g->x_wing_array, time);
    sfRenderWindow_drawSprite(g->window, g->background->space_sprite, NULL);
    second_loop(g->window, g->x_wing_array);
    sfRenderWindow_drawSprite(g->window, g->background->cockipt_sprite, NULL);
    if (check_win(g->x_wing_array) == 1)
        g->game_state = 4;
    return g->game_state;
}
