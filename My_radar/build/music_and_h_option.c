/*
** EPITECH PROJECT, 2025
** My_radar
** File description:
** music and h option
*/

#include "my.h"
#include <SFML/Audio/Music.h>
#include <SFML/Audio/SoundStatus.h>
#include <SFML/Audio/Types.h>

void h_option(void)
{
    my_printf("Air traffic simulation panel\n\n");
    my_printf("USAGE\n");
    my_printf("\t./my_radar path_to_script [OPTIONS]\n\n");
    my_printf("DESCRIPTION\n");
    my_printf("\tpath_to_script\tThe path to the script file.\n\n");
    my_printf("OPTIONS\n");
    my_printf("\t-h\t\tPrint the usage and quit.\n\n");
    my_printf("BONUS OPTIONS\n");
    my_printf("\t-r\t\tSet random plane hitboxes (between 50 and 70 square pixels).\n");
    my_printf("\t-s[NUMBER]\tSet the number of storms.\n\n");
    my_printf("USER INTERACTIONS\n");
    my_printf("\t'L' key\t\tEnables/disables hitboxes and areas.\n");
    my_printf("\t'S' key\t\tEnables/disables sprites.\n");
    my_printf("\t'E' key\t\tExits the simulation.\n");
    my_printf("\t'T' key\t\tActivates/deactivates storms.\n");
    my_printf("\t'C' key\t\tActivates/deactivates the plane counter.\n");
    my_printf("\t'M' key to pause/play music\n");
}

int what_option(char *av, main_t *variables)
{
    if (av[1] == 'r') {
        variables->r_option = 1;
        return 0;
    }
    if (av[1] == 's') {
        variables->nb_storms = my_atoi(av + 2);
        if (variables->nb_storms < 0)
            variables->nb_storms = 0;
        return 0;
    }
    return ERROR_EPITECH;
}

int check_bonus_option(char **av, main_t *variables)
{
    int i = 2;

    while (av[i] != NULL) {
        for (int j = 0; av[i][j] != '\0'; j++) {
            if (av[i][j] == '-') {
                if (what_option(av[i], variables) == ERROR_EPITECH)
                    return ERROR_EPITECH;
            }
        }
        i++;
    }
    return 0;
}

int check_h(char **av, main_t *variables)
{
    if (av[1][0] == '-' && av[1][1] == 'h') {
        h_option();
        return 0;
    }
    if (check_bonus_option(av, variables) == ERROR_EPITECH)
        return ERROR_EPITECH;
    return 1;
}

void pause_musique(main_t *variables)
{
    if (sfMusic_getStatus(variables->music) == sfPlaying) {
        sfMusic_pause(variables->music);
    }
    if (sfMusic_getStatus(variables->music) == sfPaused) {
        sfMusic_play(variables->music);
    }
}

void play_music(main_t *variables)
{
    variables->music = sfMusic_createFromFile("./content/audio.mp3");
    sfMusic_setLoop(variables->music, sfTrue);
    sfMusic_play(variables->music);
}
