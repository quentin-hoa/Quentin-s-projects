/*
** EPITECH PROJECT, 2025
** My_radar
** File description:
** storms
*/

#include "my.h"
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>

void init_storm(storm_t *storm)
{
    storm->postion.x = rand() % 1920;
    storm->postion.y = rand() % 1080;
    storm->size = 50 + rand() % 50;
    storm->storm_srpite = sfSprite_create();
    storm->storm_texture = sfTexture_createFromFile("./content/storm.png", NULL);
    sfSprite_setOrigin(storm->storm_srpite, (sfVector2f){250, 250});
    sfSprite_setScale(storm->storm_srpite, (sfVector2f){storm->size/500.0f, storm->size/500.0f});
    sfSprite_setTexture(storm->storm_srpite, storm->storm_texture, sfTrue);
    storm->speed.x = rand() % 80;
    storm->speed.y = rand() % 80;
    sfSprite_setPosition(storm->storm_srpite, storm->postion);
}

void init_storms(main_t *variables)
{
    storm_t *node;

    srand((unsigned int)time(NULL));
    for (int i = 0; i < variables->nb_storms; i++) {
        node = malloc(sizeof(storm_t));
        if (!node)
            return;
        init_storm(node);
        node->next = variables->storm;
        variables->storm = node;
    }
}

void move_storm(storm_t *storm, main_t *variables)
{
    storm->postion.y += storm->speed.y * variables->delta_time;
    storm->postion.x += storm->speed.x * variables->delta_time;
    if (storm->postion.x >= 1920 - 25) {
        storm->postion.x = 1920 - 25;
        storm->speed.x *= -1;
        storm->speed.y = rand() % 150;
    }
    else if (storm->postion.x <= 25) {
        storm->postion.x = 25;
        storm->speed.x *= -1;
        storm->speed.y = rand() % 150;
    }
    if (storm->postion.y >= 1080 - 25) {
        storm->postion.y = 1080 - 25;
        storm->speed.y *= -1;
        storm->speed.x = rand() % 150;
    }
    else if (storm->postion.y <= 25) {
        storm->postion.y = 25;
        storm->speed.y *= -1;
        storm->speed.x = rand() % 150;
    }
    sfSprite_setPosition(storm->storm_srpite, storm->postion);
}

void move_storms(main_t *variables)
{
    storm_t *node = variables->storm;

    while (node) {
        move_storm(node, variables);
        node = node->next;
    }
}

void display_storms(main_t *variables)
{
    storm_t *node = variables->storm;

    while (node) {
        sfRenderWindow_drawSprite(variables->window, node->storm_srpite, NULL);
        node = node->next;
    }
}