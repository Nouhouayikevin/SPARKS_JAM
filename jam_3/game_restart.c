/*
** EPITECH PROJECT, 2024
** gmae_restart.c
** File description:
** This is for game restart
*/
#include "my.h"
#include <SFML/Graphics.h>
#include "my.h"
#include <stdio.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <time.h>

int random_num(int max, int min)
{
    srand(time(NULL));
    return (rand() % (max - min + 1) + min);
}

int cut_game_restart(affiche *sound, sfRenderWindow *w, int x, sfVector2f rs)
{
    sfVector2i mouse;
    sfEvent event;

    while (sfRenderWindow_pollEvent(w, &event)){
        mouse = sfMouse_getPosition((const sfWindow *)w);
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(w);
        if (event.type == sfEvtMouseButtonPressed && mouse.x >= 949
            && mouse.x <= 1008 && mouse.y >= 499 && mouse.y <= 527)
            game_function2(event, w, rs);
        if (event.type == sfEvtMouseButtonPressed && mouse.x >= 944
            && mouse.x <= 1026 && mouse.y >= 557 && mouse.y <= 576)
            sfRenderWindow_close(w);
        if (event.type == sfEvtMouseButtonPressed && mouse.x >= 932
            && mouse.x <= 1027 && mouse.y >= 439 && mouse.y <= 470)
            x = 0;
    }
    return x;
}

int game_restart(affiche *sound, sfRenderWindow *window)
{
    affiche key = my_texture();
    int x = 1;
    sfVector2f res_scale = {0.7, 0.7};
    sfVector2f pos = {1920 / 2 - 100, 1080 / 2 - 150};
    sfVector2i mouse;
    sfEvent event;

    sound->texture = sfTexture_createFromFile("./restart.png", NULL);
    sound->sprite = sfSprite_create();
    sfSprite_setScale(sound->sprite, res_scale);
    sfSprite_setTexture(sound->sprite, sound->texture, sfTrue);
    sfSprite_setPosition(sound->sprite, pos);
    while (x == 1 && sfRenderWindow_isOpen(window)){
        x = cut_game_restart(sound, window, x, res_scale);
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, key.sprite, NULL);
        sfRenderWindow_drawSprite(window, sound->sprite, NULL);
        sfRenderWindow_display(window);
    }
}
