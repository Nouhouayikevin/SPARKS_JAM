/*
** EPITECH PROJECT, 2024
** scene 3
** File description:
** scene 3
*/

#include "animation.h"

/********************************poursuite 2*/
void poursuite2(sfRenderWindow *win)
{
       anime_t image_f1;
//clock et backgroud
    image_f1.a.c = sfClock_create();
    image_f1.a.key = sfSprite_create();
    image_f1.a.T = sfTexture_createFromFile("pictures_jam/courir_2.png", NULL);
    sfSprite_setTexture(image_f1.a.key,image_f1.a.T,sfTrue);
    sfSprite_setScale(image_f1.a.key, (sfVector2f){1, 0.95});
//partie du personage
    image_f1.b.c = sfClock_create();
    image_f1.b.rect = (sfIntRect) {0, 192, 48, 64};
    image_f1.b.key = sfSprite_create();
    image_f1.b.T = sfTexture_createFromFile("pictures_jam/personnage.png", NULL);
    sfSprite_setTexture(image_f1.b.key,image_f1.b.T,sfTrue);
    sfSprite_setTextureRect(image_f1.b.key, image_f1.b.rect);
    sfSprite_setPosition(image_f1.b.key, (sfVector2f){1950, 430});
    sfSprite_setScale(image_f1.b.key, (sfVector2f){9, 9});
//flamme
    image_f1.c.c = sfClock_create();
    image_f1.c.rect = (sfIntRect) {0, 0, 115, 173};
    image_f1.c.key = sfSprite_create();
    image_f1.c.T = sfTexture_createFromFile("pictures_jam/flamme.png", NULL);
    sfSprite_setTexture(image_f1.c.key,image_f1.c.T,sfTrue);
    sfSprite_setTextureRect(image_f1.c.key, image_f1.c.rect);
    sfSprite_setPosition(image_f1.c.key, (sfVector2f){-200,0});
    sfSprite_setScale(image_f1.c.key, (sfVector2f){7, 7});
//phantome
    image_f1.d.c = sfClock_create();
    image_f1.d.rect = (sfIntRect) {128, 0, 135, 2000};
    image_f1.d.key = sfSprite_create();
    image_f1.d.T = sfTexture_createFromFile("Yurei/run_back.png", NULL);
    sfSprite_setTexture(image_f1.d.key,image_f1.d.T,sfTrue);
    sfSprite_setTextureRect(image_f1.d.key, image_f1.d.rect);
    sfSprite_setPosition(image_f1.d.key, (sfVector2f){1800, 300});
    sfSprite_setScale(image_f1.d.key, (sfVector2f){2, 2});
    while (sfRenderWindow_isOpen(win)) {
        sfRenderWindow_clear(win, sfBlack);
        sfRenderWindow_drawSprite(win, image_f1.a.key ,NULL);
        while (sfRenderWindow_pollEvent(win, &image_f1.a.e)) {
            events(&image_f1.a, win);
        }
        if (elapsed_time(image_f1.a.c) < 3.0) {
        animation_courir_vers_gauche(&image_f1.b, 0.1, image_f1.b.c);
        sfSprite_move(image_f1.b.key,(sfVector2f){-28, 0});
        sfRenderWindow_drawSprite(win, image_f1.b.key ,NULL);
        }
        if (elapsed_time(image_f1.a.c) < 4 && elapsed_time(image_f1.a.c) > 2.0) {
            sfRenderWindow_drawSprite(win, image_f1.d.key ,NULL);
            sfSprite_move(image_f1.d.key,(sfVector2f){-42, 0});
        }
        if (elapsed_time(image_f1.a.c) > 4)
            break;
        sfRenderWindow_display(win);
    }
    sfSprite_destroy(image_f1.a.key);
    sfTexture_destroy(image_f1.a.T);
    sfClock_destroy(image_f1.a.c);

    sfSprite_destroy(image_f1.b.key);
    sfTexture_destroy(image_f1.b.T);
    sfClock_destroy(image_f1.b.c);

    sfSprite_destroy(image_f1.c.key);
    sfTexture_destroy(image_f1.c.T);
    sfClock_destroy(image_f1.c.c);

    sfSprite_destroy(image_f1.d.key);
    sfTexture_destroy(image_f1.d.T);
    sfClock_destroy(image_f1.d.c); 
}