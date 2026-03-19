/*
** EPITECH PROJECT, 2025
** Day03
** File description:
** Main game loop and structure
*/

#include "../include/my.h"

static void init_rect_srpite(x_wing_t *xwing)
{
    xwing->rect_spirte.left = 0;
    xwing->rect_spirte.top = 0;
    xwing->rect_spirte.width = 166;
    xwing->rect_spirte.height = 500;
}

void initialistion_xwing(x_wing_t *xwing, int window_width, main_t *g)
{
    int safe_margin_x = 50;
    int safe_margin_y = 150;
    float initial_x = rand() % 1920;
    float initial_y = rand() % 1080;

    xwing->texture_sheet = g->texture_sheet;
    xwing->sprite = sfSprite_create();
    xwing->damage->hp = 2;
    xwing->damage->state = FULL_LIFE;
    init_rect_srpite(xwing);
    xwing->scale = (sfVector2f){0.8, 0.8};
    xwing->speed.x = 50.0 + (float)(rand() % 100);
    xwing->speed.y = 50.0 + (float)(rand() % 100);
    sfSprite_setTexture(xwing->sprite, xwing->texture_sheet, sfTrue);
    sfSprite_setTextureRect(xwing->sprite, xwing->rect_spirte);
    sfSprite_setScale(xwing->sprite, xwing->scale);
    sfSprite_setPosition(xwing->sprite, (sfVector2f){initial_x, initial_y});
}

static void firts_if(x_wing_t *xwing, sfVector2f *pos, sfFloatRect bounds, int window_width)
{
    if (pos->x < 0) {
        pos->x = 0;
        xwing->speed.x *= -1;
    }
    else if (pos->x + bounds.width > window_width) {
        pos->x = window_width - bounds.width;
        xwing->speed.x *= -1;
        xwing->speed.y += ((float)(rand() % 50 - 25));
    }
}
void move_xwing(x_wing_t *xwing, float time, int window_width,
    int window_height)
{
    sfVector2f pos = sfSprite_getPosition(xwing->sprite);
    sfFloatRect bounds = sfSprite_getGlobalBounds(xwing->sprite);

    pos.x += xwing->speed.x * time;
    pos.y += xwing->speed.y * time;
    firts_if(xwing, &pos, bounds, window_width);
    if (pos.y < 0) {
        pos.y = 0;
        xwing->speed.y *= -1;
        xwing->speed.x += ((float)(rand() % 50 - 25));
    } else if (pos.y + bounds.height > window_height) {
        pos.y = window_height - bounds.height;
        xwing->speed.y *= -1;
    }
    sfSprite_setPosition(xwing->sprite, pos);
}
