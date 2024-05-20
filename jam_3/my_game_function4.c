/*
** EPITECH PROJECT, 2024
** my_game_function4.c
** File description:
** This is for handling the coding style
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

affiche background(sfRenderWindow *window, sfVector2f scale)
{
    affiche key;

    key.texture = sfTexture_createFromFile("./house.jpg", NULL);
    key.sprite = sfSprite_create();
    sfSprite_setTexture(key.sprite, key.texture, sfTrue);
    sfSprite_setScale(key.sprite, scale);
    return key;
}

affiche menu_button(void)
{
    affiche button;
    sfVector2f button_pos = {1920 - 1050, 1080 / 2};
    sfVector2f scale = {0.5, 0.5};

    button.texture = sfTexture_createFromFile("./menu.png", NULL);
    button.sprite = sfSprite_create();
    sfSprite_setTexture(button.sprite, button.texture, sfTrue);
    sfSprite_setScale(button.sprite, scale);
    sfSprite_setPosition(button.sprite, button_pos);
    return button;
}