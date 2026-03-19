/*
** EPITECH PROJECT, 2025
** Day03
** File description:
** Alphabet
*/

#include "../include/my.h"

void init_xwing_params(x_wing_t *xwing, int window_width, int level)
{
    int safe_margin_x = 50;
    int safe_margin_y = 150;
    float initial_x = (float)(rand() % (window_width - safe_margin_x));
    float initial_y = (float)(rand() % (window_width - safe_margin_y));

    xwing->scale = (sfVector2f){(0.8 / (level + 0.2)), (0.8 / (level + 0.2))};
    xwing->speed.x = (50.0 * (level + 0.2)) + (float)(rand() % 100);
    xwing->speed.y = (50.0 * (level + 0.2)) + (float)(rand() % 100);
    sfSprite_setPosition(xwing->sprite, (sfVector2f){initial_x, initial_y});
}

void init_next_level(x_wing_t *xwing, int window_width, int level, main_t *g)
{
    xwing->texture_sheet = g->texture_sheet;
    xwing->sprite = sfSprite_create();
    sfSprite_setTexture(xwing->sprite, xwing->texture_sheet, sfTrue);
    xwing->damage->hp = 2;
    xwing->damage->state = FULL_LIFE;
    xwing->rect_spirte.left = 0;
    xwing->rect_spirte.top = 0;
    xwing->rect_spirte.width = 166;
    xwing->rect_spirte.height = 500;
    sfSprite_setTextureRect(xwing->sprite, xwing->rect_spirte);
    init_xwing_params(xwing, window_width, level);
    sfSprite_setScale(xwing->sprite, xwing->scale);
}

void init_enemies(main_t *g)
{
    if (g->level == 0) {
        for (int i = 0; i < NUM_XWING; i++) {
            g->x_wing_array[i].damage = &g->damage_array[i];
            initialistion_xwing(&g->x_wing_array[i], 1024, g);
        }
    }
    if (g->level <= 3 && g->level > 0) {
        for (int i = 0; i < NUM_XWING; i++) {
            g->x_wing_array[i].damage = &g->damage_array[i];
            init_next_level(&g->x_wing_array[i], 1024, g->level, g);
        }
    }
}

background_t *init_background()
{
    background_t *background = malloc(sizeof(background_t));

    background->cockpit_texture = sfTexture_createFromFile("./content/cockipt_v3 .png",
        NULL);
    background->cockipt_sprite = sfSprite_create();
    background->space = sfTexture_createFromFile("./content/space.png", NULL);
    background->space_sprite = sfSprite_create();
    sfSprite_setTexture(background->space_sprite, background->space, sfTrue);
    sfSprite_setTexture(background->cockipt_sprite, background->cockpit_texture, sfTrue);
    return background;
}
