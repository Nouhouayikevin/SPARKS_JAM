/*
** EPITECH PROJECT, 2024
** my game function 2
** File description:
** This is for my game function
*/

#include "my.h"
#include <SFML/Graphics.h>
#include "my.h"
#include <stdio.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdlib.h>
affiche *sprite2(sfRenderWindow *w, affiche *li, sfVector2f l, sfVector2f lp)
{
    li[6].texture = sfTexture_createFromFile("./OLD/VIDA_0.png", NULL);
    li[6].sprite = sfSprite_create();
    sfSprite_setTexture(li[6].sprite, li[6].texture, sfTrue);
    sfSprite_setScale(li[6].sprite, l);
    sfSprite_setPosition(li[6].sprite, lp);
    return li;
}

affiche *lsprite(sfRenderWindow *w, affiche *li, sfVector2f ls, sfVector2f lp)
{
    li[3].texture = sfTexture_createFromFile("./OLD/VIDA_4.png", NULL);
    li[3].sprite = sfSprite_create();
    sfSprite_setTexture(li[3].sprite, li[3].texture, sfTrue);
    sfSprite_setScale(li[3].sprite, ls);
    sfSprite_setPosition(li[3].sprite, lp);
    li[4].texture = sfTexture_createFromFile("./OLD/VIDA_2.png", NULL);
    li[4].sprite = sfSprite_create();
    sfSprite_setTexture(li[4].sprite, li[4].texture, sfTrue);
    sfSprite_setScale(li[4].sprite, ls);
    sfSprite_setPosition(li[4].sprite, lp);
    li[5].texture = sfTexture_createFromFile("./OLD/VIDA_1.png", NULL);
    li[5].sprite = sfSprite_create();
    sfSprite_setTexture(li[5].sprite, li[5].texture, sfTrue);
    sfSprite_setScale(li[5].sprite, ls);
    sfSprite_setPosition(li[5].sprite, lp);
    return li;
}

affiche *life_sprite(sfRenderWindow *window, sfVector2f lp, sfVector2f l)
{
    affiche *life = malloc(sizeof(affiche) * 8);

    life[0].texture = sfTexture_createFromFile("./OLD/VIDA_10.png", NULL);
    life[0].sprite = sfSprite_create();
    sfSprite_setTexture(life[0].sprite, life[0].texture, sfTrue);
    sfSprite_setScale(life[0].sprite, l);
    sfSprite_setPosition(life[0].sprite, lp);
    life[1].texture = sfTexture_createFromFile("./OLD/VIDA_8.png", NULL);
    life[1].sprite = sfSprite_create();
    sfSprite_setTexture(life[1].sprite, life[1].texture, sfTrue);
    sfSprite_setScale(life[1].sprite, l);
    sfSprite_setPosition(life[1].sprite, lp);
    life[2].texture = sfTexture_createFromFile("./OLD/VIDA_6.png", NULL);
    life[2].sprite = sfSprite_create();
    sfSprite_setTexture(life[2].sprite, life[2].texture, sfTrue);
    sfSprite_setScale(life[2].sprite, l);
    sfSprite_setPosition(life[2].sprite, lp);
    life = lsprite(window, life, l, lp);
    life = sprite2(window, life, l, lp);
    return life;
}

void move_rect(sfIntRect *rect, int offset, int max_value)
{
    if (rect->left < max_value)
        rect->left += offset;
    else
        rect->left = 0;
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
