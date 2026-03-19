/*
** EPITECH PROJECT, 2025
** My_radar
** File description:
** colision
*/

#include "my.h"

int check_coliston_one_storm(storm_t *storm, airplane_t *plane)
{
    float x_distance = plane->pos.x - storm->postion.x;
    float y_distance = plane->pos.y - storm->postion.y;
    float limit = storm->size / 2.0f + (25.0f + (float)plane->bonus_hitbox / 2);

    if (x_distance < 0)
        x_distance *= -1;
    if (y_distance < 0)
        y_distance *= -1;
    if (x_distance <= limit && y_distance <= limit)
        return 1;
    return 0;
}

int check_colision_all_storms(airplane_t *plane, main_t *variables)
{
    storm_t *node = variables->storm;

    while (node){
        if (check_coliston_one_storm(node, plane) == 1)
            return 1;
        node = node->next;
    }
    return 0;
}

int check_colision(airplane_t *plane1, airplane_t *plane2)
{
    float x_distance = plane1->pos.x - plane2->pos.x;
    float y_distance = plane1->pos.y - plane2->pos.y;
    float limit = 50 + (float)(plane1->bonus_hitbox + plane2->bonus_hitbox) / 2;

    if (x_distance < 0)
        x_distance *= -1;
    if (y_distance < 0)
        y_distance *= -1;
    if (x_distance <= limit && y_distance <= limit)
        return 1;
    return 0;
}

int is_in_tower(tower_t *tower, airplane_t *plane)
{
    float x_dis = (float)tower->x_position - plane->pos.x;
    float y_dis = (float)tower->y_position - plane->pos.y;
    float disatance = (x_dis *x_dis) + (y_dis *y_dis);
    float rsq_distance = (float)tower->raduis * (float)tower->raduis;

    if (disatance <= rsq_distance)
        return 1;
    return 0;
}

int is_protected(airplane_t *plane, main_t *variables)
{
    tower_t *current_node = variables->towers;

    while (current_node) {
        if (is_in_tower(current_node, plane) == 1) {
            return 1;
        }
        current_node = current_node->next;
    }
    return 0;
}

quad_node_t *create_quad_node(float x, float y, float widht, float height)
{
    quad_node_t *node = malloc(sizeof(quad_node_t));

    if (!node)
        return NULL;
    node->area.left = x;
    node->area.top = y;
    node->area.width = widht;
    node->area.height = height;
    node->nb_planes = 0;
    for (int i = 0; i < 4; i++) {
        node->sub[i] = NULL;
    }
    return node;
}

static int get_quadrant(sfFloatRect area, airplane_t *plane)
{
    float mid_x = area.left + (area.width / 2);
    float mid_y = area.top + (area.height / 2);

    if (plane->pos.x < mid_x && plane->pos.y < mid_y)
        return NW;
    if (plane->pos.x >= mid_x && plane->pos.y < mid_y)
        return NE;
    if (plane->pos.x < mid_x && plane->pos.y >= mid_y)
        return SW;
    return SE;
}

static void split_node(quad_node_t *node)
{
    float w = node->area.width / 2;
    float h = node->area.height / 2;
    float x = node->area.left;
    float y = node->area.top;

    node->sub[0] = create_quad_node(x, y, w, h);
    node->sub[1] = create_quad_node(x + w, y, w, h);
    node->sub[2] = create_quad_node(x, y + h, w, h);
    node->sub[3] = create_quad_node(x + w, y + h, w, h);
}

void insert_plane_in_quad(quad_node_t *node, airplane_t *plane)
{
    if (node->sub[0] != NULL) {
        insert_plane_in_quad(node->sub[get_quadrant(node->area, plane)], plane);
        return;
    }
    if (node->nb_planes < 16) {
        node->planes[node->nb_planes] = plane;
        node->nb_planes++;
    }
    if (node->nb_planes > 8 && node->area.width > 10) {
        split_node(node);
        for (int i = 0; i < node->nb_planes; i++) {
            insert_plane_in_quad(node, node->planes[i]);
        }
        node->nb_planes = 0;
    }
}

static void storm_colision(main_t *variables, quad_node_t *node, int i)
{
    if (node->planes[i]->dead == 0) {
        if (node->planes[i]->dead == 0 && check_colision_all_storms(node->planes[i], variables) == 1 && is_protected(node->planes[i], variables) == 0) {
            node->planes[i]->dead = 1;
            variables->nb_planes--;
        }
    }
}

static void second_for_loop(quad_node_t *node, main_t *variables, int i)
{
    if (variables->t_option == 1)
            storm_colision(variables, node, i);
    for (int j = i + 1; j < node->nb_planes; j++) {
        if (variables->t_option == 1)
            storm_colision(variables, node, j);
        if (node->planes[i]->dead == 1 || node->planes[j]->dead == 1)
            continue;
        if (check_colision(node->planes[i], node->planes[j]) == 1 && (is_protected(node->planes[i], variables) == 0 && is_protected(node->planes[j], variables) == 0)) {
            node->planes[i]->dead = 1;
            node->planes[j]->dead = 1;
            variables->nb_planes -= 2;
        }
    }
}

void check_quad_colisions(quad_node_t *node, main_t *variables)
{
    if (node->sub[0] != NULL) {
        for (int i = 0; i < 4; i++) {
            check_quad_colisions(node->sub[i], variables);
        }
        return;
    }
    for (int i = 0; i < node->nb_planes; i++) {
        second_for_loop(node, variables, i);
    }
}

void free_quad(quad_node_t *node)
{
    if (node == NULL)
        return;
    if (node->sub[0] != NULL) {
        for (int i = 0; i < 4; i++)
            free_quad(node->sub[i]);
    }
    free(node);
}

void update_colisions(main_t *variables)
{
    quad_node_t *main_quad = create_quad_node(0, 0, 1920, 1080);
    airplane_t *current_node = variables->airplane;


    while (current_node) {
        if (current_node->dead == 0 && current_node->is_mooving == 1)
            insert_plane_in_quad(main_quad, current_node);
        current_node = current_node->next;
    }
    check_quad_colisions(main_quad, variables);
    free_quad(main_quad);
}
