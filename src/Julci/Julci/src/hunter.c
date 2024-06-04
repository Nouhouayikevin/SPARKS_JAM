/*
** EPITECH PROJECT, 2024
** hunter
** File description:
** hunter
*/

#include "../include/my.h"
#include <time.h>

void kill(data *data, int i)
{
    sfFloatRect rect = sfSprite_getGlobalBounds(data->birds);
    float x = data->event.mouseButton.x;
    float y = data->event.mouseButton.y;

    if (sfFloatRect_contains(&rect, x, y) == sfTrue &&
        data->event.type == sfEvtMouseButtonPressed) {
        data->pos.x = 0;
        data->pos.y = rand() % 400;
        data->rect.left = 0;
    }
}

void loop_contains(data *data, int i)
{
    close_boucle(data);
    data->position = sfMouse_getPosition(data->window);
    data->pos_c.x = data->position.x;
    data->pos_c.y = data->position.y;
    sfSprite_setPosition(data->cursor, data->pos_c);
    data->time = sfClock_getElapsedTime(data->clock);
    data->seconds = data->time.microseconds / 1000000.0;
    if (data->seconds > 0.15) {
        move_rect(&data->rect);
        position(&data->pos);
        sfClock_restart(data->clock);
    }
    kill(data, i);
    if (data->event.type == sfEvtMouseButtonPressed)
        sfSound_play(data->sound);
    display(data);
}

void game_loop(data *data)
{
    int i = 0;

    init_variables(data);
    data->position = sfMouse_getPosition(data->window);
    data->pos_c.x = (float)data->position.x;
    data->pos_c.y = (float)data->position.y;
    CURSOR(data->window, sfFalse);
    while (sfRenderWindow_isOpen(data->window)) {
        loop_contains(data, i);
        i++;
    }
    destroy(data);
}
