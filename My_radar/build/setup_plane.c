/*
** EPITECH PROJECT, 2025
** My_radar
** File description:
** setup_plane
*/

#include "my.h"
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Types.h>
#include <SFML/System/Vector2.h>

float simple_atan2(float y, float x)
{
    float angle = 0;
    float abs_x = (x < 0) ? -x : x;
    float abs_y = (y < 0) ? -y : y;

    if (x == 0 && y > 0)
        return 90;
    if (x == 0 && y < 0)
        return 270;
    if (x == 0 && y == 0)
        return 0;
    if (abs_x > abs_y)
        angle = 45 * abs_y / abs_x;
    else
        angle = 90 - (45 * abs_x / abs_y);
    if (x < 0 && y >= 0)
        angle = 180 - angle;
    if (x < 0 && y < 0)
        angle = 180 + angle;
    if (x >= 0 && y < 0)
        angle = 360 - angle;
    return angle;
}

sfVector2f get_direction_vector(int x_start, int y_start, int x_dest,
    int y_dest)
{
    float x = x_dest - x_start;
    float y = y_dest - y_start;
    float lenght = my_compute_square_root((x * x) + (y * y));
    sfVector2f direction_vector;

    if (lenght != 0.0f) {
        direction_vector.x = x / lenght;
        direction_vector.y = y / lenght;
    } else {
        direction_vector.x = 0;
        direction_vector.y = 0;
    }
    return direction_vector;
}

void set_plane_rotation(airplane_t *plane)
{
    float degrees =
    simple_atan2(plane->direction_vector.y, plane->direction_vector.x) + 90;
    sfVector2f center;

    center.x = 250.0f;
    center.y = 250.0f;
    sfSprite_setOrigin(plane->airplane_srpite, center);
    sfSprite_setRotation(plane->airplane_srpite, degrees);
    sfRectangleShape_setRotation(plane->hitbox, degrees);
}
