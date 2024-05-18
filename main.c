/*
** EPITECH PROJECT, 2024
** jam
** File description:
** jam
*/

#include "include/jam.h"

int main(void)
{
    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow *window;
    sfEvent event;

    window = sfRenderWindow_create(mode, "SPARKS", sfResize | sfClose, NULL);
    menu(window);
}