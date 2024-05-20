/*
** EPITECH PROJECT, 2024
** cache
** File description:
** cache
*/

#include "../../include/jam.h"

void cache_cache(sfRenderWindow *win)
{
    anime_t image_f1;
//clock et backgroud
    image_f1.a.c = sfClock_create();
    image_f1.a.key = sfSprite_create();
    image_f1.a.T = sfTexture_createFromFile("./src/Kevin/images/cache.png", NULL);
    sfSprite_setTexture(image_f1.a.key,image_f1.a.T,sfTrue);
    sfSprite_setScale(image_f1.a.key, (sfVector2f){1, 0.95});
//partie du personage
    image_f1.b.c = sfClock_create();
    image_f1.b.rect = (sfIntRect) {0, 192, 48, 64};
    image_f1.b.key = sfSprite_create();
    image_f1.b.T = sfTexture_createFromFile("./src/Kevin/pictures_jam/personnage.png", NULL);
    sfSprite_setTexture(image_f1.b.key,image_f1.b.T,sfTrue);
    sfSprite_setTextureRect(image_f1.b.key, image_f1.b.rect);
    sfSprite_setPosition(image_f1.b.key, (sfVector2f){1950, 430});
    sfSprite_setScale(image_f1.b.key, (sfVector2f){9, 9});
//personnage monte
    image_f1.c.c = sfClock_create();
    image_f1.c.rect = (sfIntRect) {0, 0, 48, 64};
    image_f1.c.key = sfSprite_create();
    image_f1.c.T = sfTexture_createFromFile("./src/Kevin/pictures_jam/personnage.png", NULL);
    sfSprite_setTexture(image_f1.c.key,image_f1.c.T,sfTrue);
    sfSprite_setTextureRect(image_f1.c.key, image_f1.c.rect);
    sfSprite_setPosition(image_f1.c.key, (sfVector2f){600, 500});
    sfVector2f vec = (sfVector2f){9, 9};
    sfSprite_setScale(image_f1.c.key, vec);
//phantome
    image_f1.d.c = sfClock_create();
    image_f1.d.rect = (sfIntRect) {128, 0, 135, 2000};
    image_f1.d.key = sfSprite_create();
    image_f1.d.T = sfTexture_createFromFile("./src/Kevin/Yurei/run_back.png", NULL);
    sfSprite_setTexture(image_f1.d.key,image_f1.d.T,sfTrue);
    sfSprite_setTextureRect(image_f1.d.key, image_f1.d.rect);
    sfSprite_setPosition(image_f1.d.key, (sfVector2f){1800, 300});
    sfSprite_setScale(image_f1.d.key, (sfVector2f){2, 2});
//phantome come back
    /*********phantom__1**/
    image_f1.e.c = sfClock_create();
    image_f1.e.rect = (sfIntRect) {0, 0, 128, 128};
    image_f1.e.key = sfSprite_create();
    image_f1.e.T = sfTexture_createFromFile("./src/Kevin/Yurei/Walk.png", NULL);
    sfSprite_setTexture(image_f1.e.key,image_f1.e.T,sfTrue);
    sfSprite_setTextureRect(image_f1.e.key, image_f1.e.rect);
    sfSprite_setPosition(image_f1.e.key, (sfVector2f){550, 250});
    sfSprite_setScale(image_f1.e.key, (sfVector2f){4, 4});
    while (sfRenderWindow_isOpen(win)) {
        sfRenderWindow_clear(win, sfBlack);
        sfRenderWindow_drawSprite(win, image_f1.a.key ,NULL);
        while (sfRenderWindow_pollEvent(win, &image_f1.a.e)) {
            events(&image_f1.a, win);
        }
        if (elapsed_time(image_f1.a.c) < 1.5) {
        animation_courir_vers_gauche(&image_f1.b, 0.1, image_f1.b.c);
        sfSprite_move(image_f1.b.key,(sfVector2f){-28, 0});
        sfRenderWindow_drawSprite(win, image_f1.b.key ,NULL);
        }
        if (elapsed_time(image_f1.a.c) > 1.5 && elapsed_time(image_f1.a.c) < 2.80) {
            vec = (sfVector2f) {vec.x  -0.1, vec.y -0.1};
        sfSprite_setScale(image_f1.c.key, vec);
        animation_courir_vers_gauche(&image_f1.c, 0.1, image_f1.c.c);
        sfSprite_move(image_f1.c.key,(sfVector2f){5, -2});
        sfRenderWindow_drawSprite(win, image_f1.c.key ,NULL);
        }
        if (elapsed_time(image_f1.a.c) > 2.8 && elapsed_time(image_f1.a.c) < 5) {
            image_f1.b.rect = (sfIntRect) {0, 64, 48, 64};
            sfSprite_setTexture(image_f1.b.key,image_f1.b.T,sfTrue);
            sfSprite_setTextureRect(image_f1.b.key, image_f1.b.rect);
            sfSprite_setScale(image_f1.b.key, vec);
            sfSprite_setPosition(image_f1.b.key, (sfVector2f){780, 400});
            sfRenderWindow_drawSprite(win, image_f1.b.key ,NULL);
            sfRenderWindow_drawSprite(win, image_f1.d.key ,NULL);
            sfSprite_move(image_f1.d.key,(sfVector2f){-42, 0});
        }
        if (elapsed_time(image_f1.a.c) > 5 && elapsed_time(image_f1.a.c) < 7.5) {
            animation_courir_vers_gauche(&image_f1.b, 0.1, image_f1.b.c);
            sfSprite_move(image_f1.b.key,(sfVector2f){28, 5});
            sfRenderWindow_drawSprite(win, image_f1.b.key ,NULL);
        }
        if (elapsed_time(image_f1.a.c) > 5.5 && elapsed_time(image_f1.a.c) < 8) {
            sfSprite_move(image_f1.e.key,(sfVector2f){15, 4});
            animation_phantom_vers_la_droite(&image_f1.e, 0.4, image_f1.e.c);
            sfRenderWindow_drawSprite(win, image_f1.e.key ,NULL);
        }
         if (elapsed_time(image_f1.a.c) > 8)
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

    sfSprite_destroy(image_f1.e.key);
    sfTexture_destroy(image_f1.e.T);
    sfClock_destroy(image_f1.e.c);
}