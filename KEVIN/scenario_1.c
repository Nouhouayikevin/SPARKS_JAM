/*
** EPITECH PROJECT, 2024
** scenario1
** File description:
** pour script1
*/

#include "animation.h"

/********************************|VU DU TRESOR animation|************************************************************/
void move_rect_courir(sfIntRect *rect, int offset, int max_value)
{
    if (rect->left <= max_value) {
        rect->left += offset;
    } else {
        rect->left = 0;
    }
}

void animation_courir_vers_gauche(anim_t *R, double timelaspe, sfClock *clock)
{
    sfTime time;
    float seconds;

    time = sfClock_getElapsedTime(clock);
    seconds = time.microseconds / 1000000.0;
        if (seconds > timelaspe) {
            move_rect_courir(&R->rect, 48, 90);
            sfClock_restart(clock);
        }
    sfSprite_setTextureRect(R->key, (R->rect));
}
void animation_phantom_vers_la_droite(anim_t *R, double timelaspe, sfClock *clock)
{
    sfTime time;
    float seconds;

    time = sfClock_getElapsedTime(clock);
    seconds = time.microseconds / 1000000.0;
        if (seconds > timelaspe) {
            move_rect_courir(&R->rect, 128, 384);
            sfClock_restart(clock);
        }
    sfSprite_setTextureRect(R->key, (R->rect));
}
void animation_phantom_attack2(anim_t *R, double timelaspe, sfClock *clock)
{
    sfTime time;
    float seconds;

    time = sfClock_getElapsedTime(clock);
    seconds = time.microseconds / 1000000.0;
        if (seconds > timelaspe) {
            move_rect_courir(&R->rect, 128, 512);
            sfClock_restart(clock);
        }
    sfSprite_setTextureRect(R->key, (R->rect));
}
void vu_du_tresor(sfRenderWindow *win)
{
    anime_t image_f1;
    image_f1.a.c = sfClock_create();
//clock
    image_f1.a.key = sfSprite_create();
    image_f1.a.T = sfTexture_createFromFile("pictures_jam/tresor.jpg", NULL);
    sfSprite_setTexture(image_f1.a.key,image_f1.a.T,sfTrue);
    sfSprite_setScale(image_f1.a.key, (sfVector2f){1, 1});
/*image de tresor*/
image_f1.b.c = sfClock_create();
    image_f1.b.rect = (sfIntRect) {0, 192, 48, 64};
    image_f1.b.key = sfSprite_create();
    image_f1.b.T = sfTexture_createFromFile("pictures_jam/personnage.png", NULL);
    sfSprite_setTexture(image_f1.b.key,image_f1.b.T,sfTrue);
    sfSprite_setTextureRect(image_f1.b.key, image_f1.b.rect);
    sfSprite_setPosition(image_f1.b.key, (sfVector2f){1500, 400});
    sfSprite_setScale(image_f1.b.key, (sfVector2f){9, 9});
    /*****setting dialog 1*************/
    image_f1.c.key = sfSprite_create();
    image_f1.c.T = sfTexture_createFromFile("pictures_jam/dialog1.png", NULL);
    sfSprite_setTexture(image_f1.c.key,image_f1.c.T,sfTrue);
    sfSprite_setScale(image_f1.c.key, (sfVector2f){0.2, 0.2});
    sfSprite_setPosition(image_f1.c.key, (sfVector2f){1100, 400});
    /*****setting dialog2**************/
    image_f1.d.key = sfSprite_create();
    image_f1.d.T = sfTexture_createFromFile("pictures_jam/dialog2.png", NULL);
    sfSprite_setTexture(image_f1.d.key,image_f1.d.T,sfTrue);
    sfSprite_setScale(image_f1.d.key, (sfVector2f){0.2, 0.2});
    sfSprite_setPosition(image_f1.d.key, (sfVector2f){1100, 400});
/*********phantom__1**/
    image_f1.e.c = sfClock_create();
    image_f1.e.rect = (sfIntRect) {0, 0, 128, 128};
    image_f1.e.key = sfSprite_create();
    image_f1.e.T = sfTexture_createFromFile("Yurei/Walk.png", NULL);
    sfSprite_setTexture(image_f1.e.key,image_f1.e.T,sfTrue);
    sfSprite_setTextureRect(image_f1.e.key, image_f1.e.rect);
    sfSprite_setPosition(image_f1.e.key, (sfVector2f){-450, 100});
    sfSprite_setScale(image_f1.e.key, (sfVector2f){7, 7});
/**********phantom__2*/
    image_f1.f.rect = (sfIntRect) {0, 0, 128, 128};
    image_f1.f.key = sfSprite_create();
    image_f1.f.T = sfTexture_createFromFile("Yurei/Attack_4.png", NULL);
    sfSprite_setTexture(image_f1.f.key,image_f1.f.T,sfTrue);
    sfSprite_setTextureRect(image_f1.f.key, image_f1.f.rect);
    sfSprite_setPosition(image_f1.f.key, (sfVector2f){0, 100});
    sfSprite_setScale(image_f1.f.key, (sfVector2f){7, 7});
    while (sfRenderWindow_isOpen(win)) {
        sfRenderWindow_clear(win, sfBlack);
        sfRenderWindow_drawSprite(win, image_f1.a.key ,NULL);
        sfRenderWindow_drawSprite(win,image_f1.b.key, NULL);
        while (sfRenderWindow_pollEvent(win, &image_f1.a.e)) {
            events(&image_f1.a, win);
        }
        if (elapsed_time(image_f1.a.c) < 3.0) {
        animation_courir_vers_gauche(&image_f1.b, 0.4, image_f1.b.c);
        sfSprite_move(image_f1.b.key,(sfVector2f){-2, 0});
        }
        if (elapsed_time(image_f1.a.c) < 6.0 && elapsed_time(image_f1.a.c) > 3.0) {
            sfRenderWindow_drawSprite(win, image_f1.c.key ,NULL);
        }
        if (elapsed_time(image_f1.a.c) > 6.0 && elapsed_time(image_f1.a.c) < 14.0) {
            if (elapsed_time(image_f1.a.c) > 7.0 && elapsed_time(image_f1.a.c) < 10.0) {
                sfSprite_move(image_f1.e.key,(sfVector2f){5, 0});
                animation_phantom_vers_la_droite(&image_f1.e, 0.4, image_f1.e.c);
                sfRenderWindow_drawSprite(win, image_f1.e.key ,NULL);
            }
            if (elapsed_time(image_f1.a.c) > 10.0 && elapsed_time(image_f1.a.c) < 12.0) {
                animation_phantom_attack2(&image_f1.f, 3, image_f1.f.c);
                sfRenderWindow_drawSprite(win, image_f1.f.key ,NULL);
            }
        }
        if (elapsed_time(image_f1.a.c) < 15.0 && elapsed_time(image_f1.a.c) > 12.0) {
            animation_courir_vers_gauche(&image_f1.b, 0.4, image_f1.b.c);
            sfSprite_move(image_f1.b.key,(sfVector2f){5, 0});
            sfSprite_move(image_f1.d.key,(sfVector2f){5, 0});
            sfRenderWindow_drawSprite(win, image_f1.b.key ,NULL);
            sfRenderWindow_drawSprite(win, image_f1.d.key ,NULL);
            sfRenderWindow_drawSprite(win, image_f1.f.key ,NULL);
        }
        if (elapsed_time(image_f1.a.c) > 15.0)
            break;
        sfRenderWindow_display(win);
    }
    sfSprite_destroy(image_f1.a.key);
    sfTexture_destroy(image_f1.a.T);

    sfSprite_destroy(image_f1.b.key);
    sfTexture_destroy(image_f1.b.T);
    
    sfSprite_destroy(image_f1.c.key);
    sfTexture_destroy(image_f1.c.T);

    sfSprite_destroy(image_f1.d.key);
    sfTexture_destroy(image_f1.d.T);
    
    sfSprite_destroy(image_f1.e.key);
    sfTexture_destroy(image_f1.e.T);

    sfClock_destroy(image_f1.a.c);
    sfClock_destroy(image_f1.b.c);
    sfClock_destroy(image_f1.e.c);
}
/******************************************************************************************/
