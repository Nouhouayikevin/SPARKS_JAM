/*
** EPITECH PROJECT, 2024
** fin
** File description:
** dans le labyrinthe
*/

#include "../../include/jam.h"
/*****************************entre dans le labyrinthe****/
void entree_dans_le_labyrinthe(sfRenderWindow *win)
{
   anime_t image_f1;
//clock et backgroud
    image_f1.a.c = sfClock_create();
    image_f1.a.key = sfSprite_create();
    image_f1.a.T = sfTexture_createFromFile("./src/Kevin/images/entre_labyrinthe.png", NULL);
    sfSprite_setTexture(image_f1.a.key,image_f1.a.T,sfTrue);
    sfSprite_setScale(image_f1.a.key, (sfVector2f){1, 0.95});
//personnage monte
    image_f1.b.c = sfClock_create();
    image_f1.b.rect = (sfIntRect) {0, 0, 48, 64};
    image_f1.b.key = sfSprite_create();
    image_f1.b.T = sfTexture_createFromFile("./src/Kevin/pictures_jam/personnage.png", NULL);
    sfSprite_setTexture(image_f1.b.key,image_f1.b.T,sfTrue);
    sfSprite_setTextureRect(image_f1.b.key, image_f1.b.rect);
    sfSprite_setPosition(image_f1.b.key, (sfVector2f){600, 500});
    sfVector2f vec = (sfVector2f){9, 9};
    sfSprite_setScale(image_f1.b.key, vec);
// phantome
    /*********phantom__1**/
    image_f1.c.c = sfClock_create();
    image_f1.c.rect = (sfIntRect) {0, 0, 128, 128};
    image_f1.c.key = sfSprite_create();
    image_f1.c.T = sfTexture_createFromFile("./src/Kevin/Yurei/Walk.png", NULL);
    sfSprite_setTexture(image_f1.c.key,image_f1.c.T,sfTrue);
    sfSprite_setTextureRect(image_f1.c.key, image_f1.c.rect);
    sfSprite_setPosition(image_f1.c.key, (sfVector2f){-450, 100});
    sfVector2f ve = (sfVector2f){7, 7};
    sfSprite_setScale(image_f1.c.key, ve);
    while (sfRenderWindow_isOpen(win)) {
        sfRenderWindow_clear(win, sfBlack);
        sfRenderWindow_drawSprite(win, image_f1.a.key ,NULL);
        while (sfRenderWindow_pollEvent(win, &image_f1.a.e)) {
            events(&image_f1.a, win);
        }
        if (elapsed_time(image_f1.a.c) < 2.5) {
            vec = (sfVector2f) {vec.x  -0.1, vec.y -0.1};
        sfSprite_setScale(image_f1.b.key, vec);
        animation_courir_vers_gauche(&image_f1.b, 0.1, image_f1.b.c);
        sfSprite_move(image_f1.b.key,(sfVector2f){5, -2});
        sfRenderWindow_drawSprite(win, image_f1.b.key ,NULL);
        }
        if (elapsed_time(image_f1.a.c) > 2.0 && elapsed_time(image_f1.a.c) < 4.0) {
            sfSprite_move(image_f1.c.key,(sfVector2f){10, 0});
            animation_phantom_vers_la_droite(&image_f1.c, 0.4, image_f1.c.c);
            sfRenderWindow_drawSprite(win, image_f1.c.key ,NULL);
        }
        if (elapsed_time(image_f1.a.c) > 4.0 && elapsed_time(image_f1.a.c) < 5.0) {
            ve.x -= 0.12;
            ve.y -= 0.12;
            sfSprite_setScale(image_f1.c.key, ve);
            sfSprite_move(image_f1.c.key,(sfVector2f){20, -0.07});
            animation_phantom_vers_la_droite(&image_f1.c, 0.4, image_f1.c.c);
            sfRenderWindow_drawSprite(win, image_f1.c.key ,NULL);
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

    sfSprite_destroy(image_f1.c.key);
    sfTexture_destroy(image_f1.c.T);
    sfClock_destroy(image_f1.c.c);
}