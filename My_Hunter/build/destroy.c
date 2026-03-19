/*
** EPITECH PROJECT, 2025
** Day03
** File description:
** Main game loop and structure
*/

#include "../include/my.h"

void destroy_game_assets(main_t *g)
{
    if (g->home_music)
        sfMusic_destroy(g->home_music);
    if (g->space_music)
        sfMusic_destroy(g->space_music);
    if (g->game_over_sprite)
        sfSprite_destroy(g->game_over_sprite);
    if (g->game_over_tex)
        sfTexture_destroy(g->game_over_tex);
    if (g->text_munitions)
        sfText_destroy(g->text_munitions);
    if (g->text_level)
        sfText_destroy(g->text_level);
}

void cleanup_xwing_resources(main_t *g)
{
    for (int i = 0; i < NUM_XWING; i++) {
        if (g->x_wing_array[i].sprite)
            sfSprite_destroy(g->x_wing_array[i].sprite);
        g->x_wing_array[i].sprite = NULL;
        g->x_wing_array[i].texture_sheet = NULL;
    }
}
