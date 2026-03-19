/*
** EPITECH PROJECT, 2025
** My_radar
** File description:
** main for my_radar
*/

#include "my.h"
#include <SFML/Audio/Music.h>
#include <SFML/Config.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/System/Vector2.h>

void create_sprite_background(main_t *variables)
{
    variables->background_texture =
    sfTexture_createFromFile("./content/map.jpg", NULL);
    variables->background_sprite = sfSprite_create();
    sfSprite_setTexture(variables->background_sprite,
        variables->background_texture, sfTrue);
}

void set_time(main_t *variables)
{
    if (!variables->clock)
        variables->clock = sfClock_create();
    variables->delta_time =
    sfTime_asSeconds(sfClock_restart(variables->clock));
    variables->total_time += variables->delta_time;
}

static void init_all_text(main_t *variables)
{
    init_timer(variables);
    init_l_text(variables);
    init_s_text(variables);
    init_t_text(variables);
    init_count_p(variables);
    init_count_s(variables);
}

void init_variables(main_t *variables)
{
    sfVideoMode mode = { 1920, 1080, 32};

    variables->window = sfRenderWindow_create(mode, "my_radar",
        sfClose | sfResize, NULL);
    sfRenderWindow_setFramerateLimit(variables->window, 60);
    create_sprite_background(variables);
    variables->l_option = 0;
    variables->s_option = 0;
    variables->t_option = 0;
    variables->r_option = 0;
    variables->c_option = 0;
    variables->clock = NULL;
    variables->nb_planes = 0;
    variables->nb_towers = 0;
    variables->airplane = NULL;
    variables->towers = NULL;
    variables->storm = NULL;
    variables->nb_storms = 3;
    variables->music_storm = sfMusic_createFromFile("./content/storm_sound.mp3");
    init_all_text(variables);
}

static void call_function(main_t *variables)
{
    sfRenderWindow_drawSprite(variables->window,
        variables->background_sprite, NULL);
    set_time(variables);
    if (variables->s_option != 1)
        display_plane(variables);
    move_plane(variables);
    update_colisions(variables);
    check_destination(variables);
    display_tower(variables->towers, variables);
    if (variables->t_option == 1) {
        display_storms(variables);
        draw_t(variables);
        draw_count_s(variables);
    }
    move_storms(variables);
    game_finished(variables);
    if (variables->l_option == 1)
        draw_l(variables);
    if (variables->s_option == 1)
        draw_s(variables);
    draw_timer(variables);
    if (variables->c_option == 1)
        draw_count_p(variables);
    sfRenderWindow_display(variables->window);
}

static void destroy_music(main_t *variables)
{
    sfMusic_destroy(variables->music);
    sfMusic_destroy(variables->music_storm);
}

int main(int ac, char **av)
{
    main_t *variables = malloc(sizeof(main_t));
    int h = 0;

    /*if (ac != 2)
        return ERROR_EPITECH;*/
    init_variables(variables);
    h = check_h(av, variables);
    if (h != 1)
        return h;
    init_storms(variables);
    if (!variables->window)
        return ERROR_EPITECH;
    if (get_line_to_create_plane(av[1], variables) == 84)
        return ERROR_EPITECH;
    play_music(variables);
    while (sfRenderWindow_isOpen(variables->window)) {
        handle_events(variables, av[1]);
        call_function(variables);
    }
    destroy_music(variables);
    return 0;
}
