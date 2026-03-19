/*
** EPITECH PROJECT, 2025
** My_radar
** File description:
** event
*/

#include "my.h"
#include <SFML/Audio/Music.h>
#include <unistd.h>


int game_finished(main_t *variables)
{
    if (variables->nb_planes > 0)
        return 0;
    sfRenderWindow_close(variables->window);
    return 1;
}

void handle_options(main_t *variables)
{
    if (variables->event.type == sfEvtKeyPressed &&
        variables->event.key.code == sfKeyL)
        variables->l_option = !variables->l_option;
    if (variables->event.type == sfEvtKeyPressed &&
        variables->event.key.code == sfKeyS)
        variables->s_option = !variables->s_option;
    if (variables->event.type == sfEvtKeyPressed &&
        variables->event.key.code == sfKeyT) {
            if (variables->t_option == 0)
                sfMusic_play(variables->music_storm);
            variables->t_option = !variables->t_option;
        }
    if (variables->event.type == sfEvtKeyPressed &&
        variables->event.key.code == sfKeyC)
        variables->c_option = !variables->c_option;
}

void handle_events(main_t *variables, char *path)
{
    while (sfRenderWindow_pollEvent(variables->window, &variables->event)) {
        if (variables->event.type == sfEvtClosed ||
            (variables->event.type == sfEvtKeyPressed &&
                variables->event.key.code == sfKeyE))
            sfRenderWindow_close(variables->window);
        if (variables->event.type == sfEvtKeyPressed &&
            variables->event.key.code == sfKeyM) {
            pause_musique(variables);
        }
        handle_options(variables);
    }
}
