/*
** EPITECH PROJECT, 2026
** A-maze-d
** File description:
** move_robots
*/

#include "../include/my.h"

static bool try_move_robot(robot_t *robot, int *finished, bool *first_print)
{
    int next_idx = robot->pos_in_path + 1;
    room_t *target = robot->path->rooms[next_idx];

    if (target->type != END && target->occupied)
        return false;
    if (robot->pos_in_path != -1)
        robot->path->rooms[robot->pos_in_path]->occupied = false;
    robot->pos_in_path++;
    if (!*first_print)
        my_printf(" ");
    my_printf("P%d-%s", robot->id, target->name);
    *first_print = false;
    if (target->type == END) {
        robot->finished = true;
        (*finished)++;
    } else
        target->occupied = true;
    return true;
}

static bool run_cycle(robot_t *robots, int nb_robots, int *finished)
{
    bool moves_in_this_round = false;
    bool first_print = true;

    for (int i = 0; i < nb_robots; i++) {
        if (robots[i].finished)
            continue;
        if (try_move_robot(&robots[i], finished, &first_print))
            moves_in_this_round = true;
    }
    if (moves_in_this_round)
        my_printf("\n");
    return moves_in_this_round;
}

void solve_lemin(path_t *paths, robot_t *robots, int nb_robots)
{
    int finished = 0;

    (void)paths;
    my_printf("#moves\n");
    while (finished < nb_robots) {
        if (!run_cycle(robots, nb_robots, &finished))
            break;
    }
}
