/*
** EPITECH PROJECT, 2024
** courir
** File description:
** chambre
*/

#include "../../include/jam.h"


void courir_chambre(sfRenderWindow *win)
{
    anime_t image_f1;
//clock et backgroud
    image_f1.a.c = sfClock_create();
    image_f1.a.key = sfSprite_create();
    image_f1.a.T = sfTexture_createFromFile("./src/Kevin/images/courir_chambre.png", NULL);
    sfSprite_setTexture(image_f1.a.key,image_f1.a.T,sfTrue);
    sfSprite_setScale(image_f1.a.key, (sfVector2f){1, 0.95});
//partie du personage
    image_f1.b.c = sfClock_create();
    image_f1.b.rect = (sfIntRect) {0, 64, 48, 64};
    image_f1.b.key = sfSprite_create();
    image_f1.b.T = sfTexture_createFromFile("./src/Kevin/pictures_jam/personnage.png", NULL);
    sfSprite_setTexture(image_f1.b.key,image_f1.b.T,sfTrue);
    sfSprite_setTextureRect(image_f1.b.key, image_f1.b.rect);
    sfSprite_setPosition(image_f1.b.key, (sfVector2f){200, 200});
    sfSprite_setScale(image_f1.b.key, (sfVector2f){9, 9});
        /*********phantom__1**/
    image_f1.e.c = sfClock_create();
    image_f1.e.rect = (sfIntRect) {0, 0, 128, 128};
    image_f1.e.key = sfSprite_create();
    image_f1.e.T = sfTexture_createFromFile("./src/Kevin/Yurei/Walk.png", NULL);
    sfSprite_setTexture(image_f1.e.key,image_f1.e.T,sfTrue);
    sfSprite_setTextureRect(image_f1.e.key, image_f1.e.rect);
    sfSprite_setPosition(image_f1.e.key, (sfVector2f){200, 0});
    sfSprite_setScale(image_f1.e.key, (sfVector2f){7, 7});
    while (sfRenderWindow_isOpen(win)) {
        sfRenderWindow_clear(win, sfBlack);
        sfRenderWindow_drawSprite(win, image_f1.a.key ,NULL);
        while (sfRenderWindow_pollEvent(win, &image_f1.a.e)) {
            events(&image_f1.a, win);
        }
        if (elapsed_time(image_f1.a.c) < 2 /*&& elapsed_time(image_f1.a.c) < 7.5*/) {
            animation_courir_vers_gauche(&image_f1.b, 0.1, image_f1.b.c);
            sfSprite_move(image_f1.b.key,(sfVector2f){28, 5});
            sfRenderWindow_drawSprite(win, image_f1.b.key ,NULL);
        }
        if (elapsed_time(image_f1.a.c) > 2 && elapsed_time(image_f1.a.c) < 5) {
            sfSprite_move(image_f1.e.key,(sfVector2f){15, 2});
            animation_phantom_vers_la_droite(&image_f1.e, 0.4, image_f1.e.c);
            sfRenderWindow_drawSprite(win, image_f1.e.key ,NULL);
        }
        if (elapsed_time(image_f1.a.c) > 5)
         break;
        sfRenderWindow_display(win);
    }
    sfSprite_destroy(image_f1.a.key);
    sfTexture_destroy(image_f1.a.T);
    sfClock_destroy(image_f1.a.c);

    sfSprite_destroy(image_f1.b.key);
    sfTexture_destroy(image_f1.b.T);
    sfClock_destroy(image_f1.b.c);

    sfSprite_destroy(image_f1.e.key);
    sfTexture_destroy(image_f1.e.T);
    sfClock_destroy(image_f1.e.c);
}