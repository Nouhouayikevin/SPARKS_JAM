/*
** EPITECH PROJECT, 2024
** init
** File description:
** init variables
*/

#include "../include/my.h"

void init_rect_and_mode(data *data)
{
    data->rect.top = 0;
    data->rect.left = 0;
    data->rect.width = 220;
    data->rect.height = 220;
    data->pos.x = 0;
    data->pos.y = 0;
    data->pos_c.x = 0;
    data->pos_c.y = 0;
    data->scale.x = 0.35;
    data->scale.y = 0.3;
    data->scale_visor.x = 0.25;
    data->scale_visor.y = 0.2;
    data->mode.width = 1920;
    data->mode.height = 1080;
    data->mode.bitsPerPixel = 32;
    data->sound = sfSound_create();
    data->musique = sfSoundBuffer_createFromFile("musique/song.ogg");
    sfSound_setBuffer(data->sound, data->musique);
}

void init_variables(data *data)
{
    init_rect_and_mode(data);
    data->window = WINDOW(data->mode, "Hunt", sfResize | sfClose, NULL);
    data->clock = sfClock_create();
    data->background = sfSprite_create();
    data->birds = sfSprite_create();
    data->cursor = sfSprite_create();
    data->nv = sfSprite_create();
    data->t_nv = FILE("img/nv.png", NULL);
    data->t_background = FILE("img/menu/enter/enter.jpeg", NULL);
    data->t_birds = FILE("img/birdsrect.png", NULL);
    data->t_cursor = FILE("img/viseur.png", NULL);
    sfSprite_setTexture(data->background, data->t_background, sfTrue);
    sfSprite_setScale(data->background, data->scale);
    sfSprite_setScale(data->cursor, data->scale_visor);
    sfSprite_setTexture(data->birds, data->t_birds, sfTrue);
    sfSprite_setTexture(data->cursor, data->t_cursor, sfTrue);
    sfSprite_setTextureRect(data->birds, data->rect);
    sfSprite_setTexture(data->nv, data->t_nv, sfTrue);
}

void destroy(data *data)
{
    sfSprite_destroy(data->background);
    sfTexture_destroy(data->t_background);
    sfSprite_destroy(data->cursor);
    sfTexture_destroy(data->t_cursor);
    sfSprite_destroy(data->birds);
    sfTexture_destroy(data->t_birds);
    sfSprite_destroy(data->nv);
    sfTexture_destroy(data->t_nv);
    sfClock_destroy(data->clock);
    sfSound_destroy(data->sound);
    sfRenderWindow_destroy(data->window);
}

void display(data *data)
{
    sfSprite_setPosition(data->cursor, data->pos_c);
    sfSprite_setTextureRect(data->birds, data->rect);
    sfRenderWindow_clear(data->window, sfWhite);
    sfRenderWindow_drawSprite(data->window, data->nv, NULL);
    sfRenderWindow_drawSprite(data->window, data->cursor, NULL);
    sfRenderWindow_drawSprite(data->window, data->background, NULL);
    sfRenderWindow_drawSprite(data->window, data->cursor, NULL);
    sfRenderWindow_drawSprite(data->window, data->birds, NULL);
    sfRenderWindow_display(data->window);
    sfSprite_setPosition(data->birds, data->pos);
}
