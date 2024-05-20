/*
** EPITECH PROJECT, 2024
** courir
** File description:
** course poursuite
*/

#include "../../include/jam.h"

/*************************poursuite 1************************************/
void explosion(anim_t *R, double timelaspe, sfClock *clock)
{
    sfTime time;
    float seconds;

    time = sfClock_getElapsedTime(clock);
    seconds = time.microseconds / 1000000.0;
        if (seconds > timelaspe) {
            move_rect_courir(&R->rect, 125, 540);
            sfClock_restart(clock);
        }
    sfSprite_setTextureRect(R->key, (R->rect));
}

void move_rect_ghost_back(sfIntRect *rect, int offset, int max_value)
{
    if (rect->left <= max_value) {
        rect->left += offset;
    } else {
        rect->left = 125;
    }
}

void phantom_hidle_back(anim_t *R, double timelaspe, sfClock *clock)
{
    sfTime time;
    float seconds;

    time = sfClock_getElapsedTime(clock);
    seconds = time.microseconds / 1000000.0;
        if (seconds > timelaspe) {
            move_rect_ghost_back(&R->rect, 195, 600);
            sfClock_restart(clock);
        }
    sfSprite_setTextureRect(R->key, (R->rect));
}

void poursuite1(sfRenderWindow *win)
{
    anime_t image_f1;
//clock et backgroud
    image_f1.a.c = sfClock_create();
    image_f1.a.key = sfSprite_create();
    image_f1.a.T = sfTexture_createFromFile("./src/Kevin/pictures_jam/courir_1.png", NULL);
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
//flamme
    image_f1.c.c = sfClock_create();
    image_f1.c.rect = (sfIntRect) {0, 0, 115, 173};
    image_f1.c.key = sfSprite_create();
    image_f1.c.T = sfTexture_createFromFile("./src/Kevin/pictures_jam/flamme.png", NULL);
    sfSprite_setTexture(image_f1.c.key,image_f1.c.T,sfTrue);
    sfSprite_setTextureRect(image_f1.c.key, image_f1.c.rect);
    sfSprite_setPosition(image_f1.c.key, (sfVector2f){1600, -50});
    sfSprite_setScale(image_f1.c.key, (sfVector2f){7, 7});
//phantome
    image_f1.d.c = sfClock_create();
    image_f1.d.rect = (sfIntRect) {128, 0, 135, 2000};
    image_f1.d.key = sfSprite_create();
    image_f1.d.T = sfTexture_createFromFile("./src/Kevin/Yurei/run_back.png", NULL);
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
        if (elapsed_time(image_f1.a.c) < 4.5 && elapsed_time(image_f1.a.c) > 1.5) {
            explosion(&image_f1.c,0.5,image_f1.c.c);
            sfRenderWindow_drawSprite(win, image_f1.c.key ,NULL);
        }
        if (elapsed_time(image_f1.a.c) < 5 && elapsed_time(image_f1.a.c) > 2.8) {
            sfRenderWindow_drawSprite(win, image_f1.d.key ,NULL);
            sfSprite_move(image_f1.d.key,(sfVector2f){-42, 0});
        }
        if (elapsed_time(image_f1.a.c) > 4.5)
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