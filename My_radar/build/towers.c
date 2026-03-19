/*
** EPITECH PROJECT, 2025
** My_radar
** File description:
** towers
*/

#include "my.h"
#include <SFML/Graphics/Color.h>

static void set_circle(tower_t *tower)
{
    sfVector2f pos = {(float)tower->x_position, (float)tower->y_position};

    tower->circle = sfCircleShape_create();
    sfCircleShape_setRadius(tower->circle, (float)tower->raduis);
    sfCircleShape_setPosition(tower->circle, pos);
    sfCircleShape_setOrigin(tower->circle, (sfVector2f){tower->raduis,
        tower->raduis});
    sfCircleShape_setFillColor(tower->circle, sfTransparent);
    sfCircleShape_setOutlineThickness(tower->circle, 1.5f);
    sfCircleShape_setOutlineColor(tower->circle, sfRed);
}

void intit_one(tower_t *tower, char **parameters)
{
    tower->x_position = my_atoi(parameters[1]);
    tower->y_position = my_atoi(parameters[2]);
    tower->raduis = my_atoi(parameters[3]);
    tower->tower_texture = sfTexture_createFromFile("./content/tower.png",
        NULL);
    tower->tower_sprite = sfSprite_create();
}

tower_t *create_tower(char *line, main_t *variables)
{
    char **parameters = my_str_to_word_array(line);
    tower_t *tower = malloc(sizeof(tower_t));
    sfVector2f center;

    intit_one(tower, parameters);
    sfSprite_setTexture(tower->tower_sprite, tower->tower_texture, sfTrue);
    center.x = 500.0f / 2;
    center.y = 500.0f;
    sfSprite_setOrigin(tower->tower_sprite, center);
    sfSprite_setPosition(tower->tower_sprite,
        (sfVector2f){tower->x_position, tower->y_position});
    sfSprite_setScale(tower->tower_sprite, (sfVector2f){0.1, 0.1});
    tower->next = NULL;
    tower->prev = NULL;
    variables->nb_towers++;
    set_circle(tower);
    return tower;
}

void append_tower(main_t *variables, tower_t *tower_to_add)
{
    tower_t *current_node;

    if (variables->towers == NULL) {
        variables->towers = tower_to_add;
        return;
    }
    current_node = variables->towers;
    while (current_node->next != NULL) {
        current_node = current_node->next;
    }
    current_node->next = tower_to_add;
    tower_to_add->prev = current_node;
}

void display_tower(tower_t *tower, main_t *variables)
{
    tower_t *current_node = tower;

    while (current_node) {
        sfRenderWindow_drawSprite(variables->window,
            current_node->tower_sprite, NULL);
        if (variables->l_option == 0)
            sfRenderWindow_drawCircleShape(variables->window,
                current_node->circle, NULL);
        current_node = current_node->next;
    }
}
