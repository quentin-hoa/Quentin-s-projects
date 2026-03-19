/*
** EPITECH PROJECT, 2025
** Day03
** File description:
** Main game loop and structure
*/

#include "../include/my.h"
#include <unistd.h>
#include <time.h>
#include <stdlib.h>

void handle_events(main_t *g)
{
    while (sfRenderWindow_pollEvent(g->window, &g->event)) {
        if (g->event.type == sfEvtClosed || g->event.type == sfEvtKeyPressed && g->event.key.code == sfKeyE) {
            sfRenderWindow_close(g->window);
        }
        g->game_state = check_button_click(g->window, &g->event,
            g->game_state);
        if (g->event.type == sfEvtMouseButtonPressed && g->game_state == 1) {
            sound_shoot(g);
            g->munitions--;
        }
    }
    if (g->munitions == 0)
        g->game_state = 2;
}

void init_resources(main_t *g)
{
    g->texture_sheet = sfTexture_createFromFile("./content/xwing.png",
        NULL);
    g->game_over_tex =
    sfTexture_createFromFile("./content/game_over.png", NULL);
    g->game_over_sprite = sfSprite_create();
    sfSprite_setTexture(g->game_over_sprite, g->game_over_tex, sfTrue);
    g->home_music =
    sfMusic_createFromFile("./content/sounds/cantina-band.mp3");
    sfMusic_setLoop(g->home_music, sfTrue);
    g->space_music =
    sfMusic_createFromFile("./content/sounds/space_music.mp3");
    sfMusic_setLoop(g->space_music, sfTrue);
    g->text_munitions = set_font(g);
    g->text_level = set_level_text();
    g->level = 0;
    init_enemies(g);
    g->game_state = 0;
    srand((unsigned int)time(NULL));
    g->munitions = NUM_XWING + 4;
    g->background = init_background();
    init_sound_shoot(g);
    init_text_game_over(g);
    init_text_next_lv(g);
    init_text_menu(g);
}

static void check_music(main_t *g)
{
    if (sfMusic_getStatus(g->space_music) != sfPlaying)
            sfMusic_play(g->space_music);
}

static void check_home_music(main_t *g)
{
    if (sfMusic_getStatus(g->home_music) != sfPlaying)
            sfMusic_play(g->home_music);
}

void handle_game_states(main_t *g)
{
    if (g->game_state == MENU) {
        menu(g);
        check_home_music(g);
        cleanup_xwing_resources(g);
        g->level = 0;
        init_enemies(g);
        g->munitions = NUM_XWING + 4;
    } else if (g->game_state == GAME) {
        sfMusic_stop(g->home_music);
        check_music(g);
        g->game_state = game_function(g, &g->event);
        draw_munitions(g);
        draw_levels(g);
    }
    if (g->game_state == GAMEOVER) {
        sfMusic_stop(g->space_music);
        sfRenderWindow_drawSprite(g->window, g->game_over_sprite, NULL);
        g->game_state = game_over(g);
        cleanup_xwing_resources(g);
        g->level = 0;
        init_enemies(g);
    }
}

void handle_level_states(main_t *g)
{
    if (g->game_state == EXIT) {
        sfRenderWindow_close(g->window);
    } else if (g->game_state == WON_LEVEL) {
        sfMusic_stop(g->space_music);
        g->game_state = next_level(g);
    }
    if (g->game_state == NEXT_LEVEl) {
        cleanup_xwing_resources(g);
        g->level++;
        init_enemies(g);
        g->munitions = NUM_XWING + 4;
        g->game_state = 1;
    }
}

int main(int ac, char **av)
{
    sfVideoMode mode = {1920, 1080, 32};
    sfUint32 style = {sfClose | sfResize};
    main_t g;

    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h')
        return check_help();
    init_resources(&g);
    g.window = sfRenderWindow_create(mode, "My Hunter", style, NULL);
    sfRenderWindow_setFramerateLimit(g.window, 60);
    if (!g.window)
        return 84;
    while (sfRenderWindow_isOpen(g.window)) {
        handle_events(&g);
        handle_game_states(&g);
        handle_level_states(&g);
        if (g.game_state == 3)
            break;
        sfRenderWindow_display(g.window);
    }
    destroy_game_assets(&g);
    return 0;
}
