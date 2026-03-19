/*
** EPITECH PROJECT, 2025
** My_radar
** File description:
** airplane
*/

#include "my.h"
#include <SFML/Graphics/RectangleShape.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/System/Vector2.h>

static void init_one(airplane_t *plane, char **parameters)
{
    plane->x_start = my_atoi(parameters[1]);
    plane->y_start = my_atoi(parameters[2]);
    plane->x_destination = my_atoi(parameters[3]);
    plane->y_destination = my_atoi(parameters[4]);
    plane->speed = my_atoi(parameters[5]);
    plane->delay_take_off = my_atoi(parameters[6]);
    plane->dead = 0;
    plane->is_mooving = 0;
}

static void init_hitbox(airplane_t *plane, main_t *variables)
{
    plane->bonus_hitbox = (variables->r_option == 1) ? rand() % 20 : 0;
    plane->hitbox = sfRectangleShape_create();
    sfRectangleShape_setSize(plane->hitbox, (sfVector2f){50 + plane->bonus_hitbox, 50 + plane->bonus_hitbox});
    sfRectangleShape_setOrigin(plane->hitbox,
        (sfVector2f){25 + (plane->bonus_hitbox / 2), 25 + (plane->bonus_hitbox / 2)});
    sfRectangleShape_setPosition(plane->hitbox, plane->pos);
    sfRectangleShape_setFillColor(plane->hitbox, sfTransparent);
    sfRectangleShape_setOutlineThickness(plane->hitbox, 1.5f);
    sfRectangleShape_setOutlineColor(plane->hitbox, sfRed);
}

static void init_two(airplane_t *plane)
{
    plane->texture_airplane = sfTexture_createFromFile("./content/bus.png",
        NULL);
    plane->airplane_srpite = sfSprite_create();
    sfSprite_setTexture(plane->airplane_srpite, plane->texture_airplane,
        sfTrue);
    sfSprite_setOrigin(plane->airplane_srpite, (sfVector2f){250, 250});
    sfSprite_setScale(plane->airplane_srpite, (sfVector2f){0.1, 0.1});
    plane->pos = (sfVector2f){(float)plane->x_start, (float)plane->y_start}; 
    sfSprite_setPosition(plane->airplane_srpite, plane->pos);
}

airplane_t *create_airplaine(char *line, main_t *variables)
{
    char **parameters = my_str_to_word_array(line);
    airplane_t *plane = malloc(sizeof(airplane_t));

    init_one(plane, parameters);
    init_two(plane);
    plane->direction_vector = get_direction_vector(plane->x_start,
        plane->y_start, plane->x_destination, plane->y_destination);
    variables->nb_planes++;
    plane->next = NULL;
    plane->prev = NULL;
    init_hitbox(plane, variables);
    set_plane_rotation(plane);
    return plane;
}

void append_plane(main_t *variables, airplane_t *plane_to_add)
{
    airplane_t *current_node;

    if (variables->airplane == NULL) {
        variables->airplane = plane_to_add;
        return;
    }
    current_node = variables->airplane;
    while (current_node->next) {
        current_node = current_node->next;
    }
    current_node->next = plane_to_add;
    plane_to_add->prev = current_node;
}

void display_plane(main_t *variables)
{
    airplane_t *current_node = variables->airplane;

    while (current_node) {
        if (current_node->dead == 0 && current_node->is_mooving == 1) {
            sfRenderWindow_drawSprite(variables->window,
            current_node->airplane_srpite, NULL);
            if (variables->l_option == 0)
                sfRenderWindow_drawRectangleShape(variables->window,
                    current_node->hitbox, NULL);
        }
        current_node = current_node->next;
    }
}

static void actualize_pos(main_t *variables, airplane_t *plane)
{
    float move_x = plane->speed * variables->delta_time *
        plane->direction_vector.x;
    float move_y = plane->speed * variables->delta_time *
        plane->direction_vector.y;

    plane->pos.x += move_x;
    plane->pos.y += move_y;
    sfSprite_setPosition(plane->airplane_srpite, plane->pos);
    sfRectangleShape_setPosition(plane->hitbox, plane->pos);
}

void move_plane(main_t *variables)
{
    airplane_t *current_node = variables->airplane;

    while (current_node) {
        if (current_node->dead == 0 &&
            (variables->total_time >= (float)current_node->delay_take_off)) {
            current_node->is_mooving = 1;
            actualize_pos(variables, current_node);
        }
        current_node = current_node->next;
    }
}
