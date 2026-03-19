/*
** EPITECH PROJECT, 2025
** Day03
** File description:
** Alphabet
*/

#include "../include/my.h"

void update_xwing_sprite(x_wing_t *xwing)
{
    int len = 166;

    if (xwing->damage->state == FULL_LIFE) {
        xwing->rect_spirte.left = 0;
    }
    if (xwing->damage->state == MID_LIFE) {
        xwing->rect_spirte.left = len;
    }
    if (xwing->damage->state == ALMOST_DEAD) {
        xwing->rect_spirte.left = 2 * len;
    }
    sfSprite_setTextureRect(xwing->sprite, xwing->rect_spirte);
}

static void if_hit_xwing(x_wing_t *xwing)
{
    if (xwing->damage->hp == 1) {
        xwing->damage->state = MID_LIFE;
    } else if (xwing->damage->hp == 0) {
        xwing->damage->state = ALMOST_DEAD;
    }
}

void hit_xwing(x_wing_t *xwing)
{
    if (xwing->damage->hp > 0) {
        xwing->damage->hp--;
        if_hit_xwing(xwing);
    } else if (xwing->damage->hp == 0)
        xwing->damage->hp = -1;
    update_xwing_sprite(xwing);
}

void handle_click(x_wing_t *xwing, int mouse_x, int mouse_y)
{
    sfFloatRect bounds = sfSprite_getGlobalBounds(xwing->sprite);

    if (sfFloatRect_contains(&bounds, (float)mouse_x, (float)mouse_y)) {
        hit_xwing(xwing);
    }
}

void init_sound_shoot(main_t *variables)
{
    variables->shoot_buffer =
    sfSoundBuffer_createFromFile("./content/sounds/tie-fighter-fire-1.mp3");
    variables->shoot_sound = sfSound_create();

    sfSound_setBuffer(variables->shoot_sound, variables->shoot_buffer);
}

void sound_shoot(main_t *variables)
{
    sfSound_play(variables->shoot_sound);
}

int check_button_click(sfRenderWindow* window, sfEvent *event,
    int current_state)
{
    sfVector2i mouse;

    if (current_state != 0 || event->type != sfEvtMouseButtonPressed)
        return current_state;
    mouse = sfMouse_getPosition(window);
    if ((mouse.x >= 312 && mouse.x <= 712) && (mouse.y >= 645
        && mouse.y <= 775))
        return 1;
    return 0;
}
