/*
** EPITECH PROJECT, 2024
** functions
** File description:
** another functions of my program
*/

#include "../include/my.h"

void close_boucle_menu(menu *menu)
{
    while (sfRenderWindow_pollEvent(menu->window, &menu->event)) {
        if (menu->event.type == sfEvtClosed) {
            sfRenderWindow_close(menu->window);
        }
    }
}

void move_rect(sfIntRect *rect)
{
    if (rect->left < 220) {
        rect->left = rect->left + 110;
    } else
        rect->left = 0;
}

void position(sfVector2f *pos)
{
    if (pos->x < 1920 && pos->y < 700) {
        pos->x += 50;
        pos->y = rand() % 400;
    } else {
        pos->x = 0;
        pos->y = 0;
    }
}

void close_boucle(data *data)
{
    while (sfRenderWindow_pollEvent(data->window, &data->event)) {
        if (data->event.type == sfEvtClosed) {
            sfRenderWindow_close(data->window);
        }
    }
}
