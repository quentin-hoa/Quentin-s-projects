/*
** EPITECH PROJECT, 2025
** My_radar
** File description:
** destination
*/

#include "my.h"

void kill_plane(airplane_t *plane)
{
    if (plane->airplane_srpite) {
        sfSprite_setColor(plane->airplane_srpite,
            (sfColor){255, 255, 255, 255});
        sfSprite_destroy(plane->airplane_srpite);
    }
    if (plane->texture_airplane)
        sfTexture_destroy(plane->texture_airplane);
    free(plane);
}

void del_node(main_t *variables, airplane_t *plane_to_del)
{
    if (plane_to_del->prev != NULL)
        plane_to_del->prev->next = plane_to_del->next;
    else
        variables->airplane = plane_to_del->next;
    if (plane_to_del->next != NULL) {
        plane_to_del->next->prev = plane_to_del->prev;
        if (plane_to_del->prev == NULL)
            plane_to_del->next->prev = NULL;
    }
    kill_plane(plane_to_del);
    variables->nb_planes--;
}

void check_destination(main_t *variables)
{
    airplane_t *current_node = variables->airplane;
    airplane_t *next_node = NULL;
    float dx;
    float dy;

    while (current_node) {
        dx = current_node->x_destination - current_node->pos.x;
        dy = current_node->y_destination - current_node->pos.y;
        next_node = current_node->next;
        if (((dx * dx) + (dy * dy)) <= MARGE_DESTINATION) {
            del_node(variables, current_node);
        }
        current_node = next_node;
    }
}
