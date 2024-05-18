/*
** EPITECH PROJECT, 2024
** menu
** File description:
** menu
*/
#include "../../include/jam.h"

void display_menu(sfRenderWindow *window)
{
    sfTexture *texture;
    sfSprite *sprite;

    texture = sfTexture_createFromFile("./pictures/image1.png", NULL);
    if (!texture) {
        printf("The texture failed to load\n");
        return;
    }
    sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfRenderWindow_drawSprite(window, sprite, NULL);
    sfSprite_destroy(sprite);
    sfTexture_destroy(texture);
}

void menu_event(sfRenderWindow *window, sfEvent event)
{
    sfVector2i mouse = sfMouse_getPosition((const sfWindow*)window);

    if (event.type == sfEvtClosed)
        sfRenderWindow_close(window);
}

void menu(sfRenderWindow* window)
{
    sfEvent event;

    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            menu_event(window, event);
        }
        sfRenderWindow_clear(window, sfBlack);
        display_menu(window);
        sfRenderWindow_display(window);
    }
}