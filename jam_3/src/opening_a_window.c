/*
** EPITECH PROJECT, 2024
** Window
** File description:
** Day13
*/

#include <SFML/Graphics.h>
#include "../my.h"
#include <stdio.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <SFML/System.h>

move_player_t event_handler(sfEvent e, sfRenderWindow *w, sfVector2f sc, move_player_t p, rect_t *rectangle)
{
    sfVector2i mouse = sfMouse_getPosition((const sfWindow *)w);

    while (sfRenderWindow_pollEvent(w, &e)) {
        if (e.type == sfEvtClosed)
            sfRenderWindow_close(w);
        p = cut_player_move(p, e, rectangle);
    }
    return p;
}

affiche my_texture(move_player_t p)
{
    affiche key;
    sfVector2f scale = {1, 0.55};

    sfVector2f pos = sfRectangleShape_getPosition(p.outline);
    sfIntRect rectangle = {pos.x, pos.y, 100, 100}; 
    key.texture = sfTexture_createFromFile("./lab.jpg", NULL);
    key.sprite = sfSprite_create();
    sfSprite_setTexture(key.sprite, key.texture, sfTrue);
    sfSprite_setScale(key.sprite, scale);
    return key;
}

void draw_sprite(affiche key)
{
    sfRenderWindow_drawSprite(key.window, key.sprite, NULL);
}

int main(int ac, char **av)
{
    sfVector2f scale = {0.4, 0.35};
    sfVector2f life_pos = {1700, 10};
    sfVideoMode m = {1920, 1080, 32};
    rect_t *rectangle = my_rectangle(rectangle);
    move_player_t p = init_move_player_t_struct(p);
    affiche key = my_texture(p);
    int i = 0;
    sfCircleShape *circle = sfCircleShape_create();
    sfCircleShape_setOutlineColor(circle, sfBlack);
    sfCircleShape_setRadius(circle, 120);
    //sfCircleShape_setFillColor(circle, sfTransparent);
    sfCircleShape_setOutlineThickness(circle, 1.6);
    sfVector2f posi;
    key.window = sfRenderWindow_create(m, "MH", sfDefaultStyle, NULL);
    sfRenderWindow_setFramerateLimit(key.window, 700);
    while (sfRenderWindow_isOpen(key.window)){
        p = event_handler(key.event, key.window, scale, p, rectangle);
        sfRenderWindow_clear(key.window, sfBlack);
        draw_sprite(key);
        sfVector2f pos = sfSprite_getPosition(p.sprite);
        posi = sfSprite_getPosition(p.sprite);
        //sfCircleShape_setPosition(circle, posi);
        //sfCircleShape_setTexture(circle, key.texture, sfFalse);
        sfIntRect rectang = {posi.x, posi.y, 350, 350};
        //sfIntRect rectang = {pos.x - 50, pos.y + 675, 215, 385};
        //sfCircleShape_setTextureRect(circle, rectang);
        //sfRenderWindow_drawCircleShape(key.window, circle, NULL);
        sfSprite_setPosition(key.sprite, pos);
        sfSprite_setTextureRect(key.sprite, rectang);
        i = 0;
        while (rectangle[i].rect != NULL){
            sfRenderWindow_drawRectangleShape(key.window, rectangle[i].rect, NULL);
            i++;
        }
        set_and_draw_player(p, key.window);
        sfRenderWindow_display(key.window);
    }
    destroy_player_val(p);
}
