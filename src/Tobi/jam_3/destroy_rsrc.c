/*
** EPITECH PROJECT, 2024
** opening_a_window2.c
** File description:
** Like his name is for opening window
*/
#include <SFML/Graphics.h>
#include "my.h"
#include <stdio.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <SFML/System.h>

void destroy_resource(affiche key)
{
    sfSprite_destroy(key.sprite);
    sfRenderWindow_destroy(key.window);
    sfTexture_destroy(key.texture);
}

void destroy_resource_help(affiche help)
{
    sfSprite_destroy(help.sprite);
    sfTexture_destroy(help.texture);
}

void destroy_resource_life(affiche corbeau, affiche *life, affiche *sound)
{
    int i = 0;

    sfClock_destroy(corbeau.clock);
    while (i < 7){
        if (i < 2){
            sfSound_destroy(sound[i].sound);
        }
        sfSprite_destroy(life[i].sprite);
        sfTexture_destroy(life[i].texture);
        i++;
    }
}
