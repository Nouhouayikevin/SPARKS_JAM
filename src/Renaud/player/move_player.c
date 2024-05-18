/*
** EPITECH PROJECT, 2024
** move_player.c
** File description:
** move_player.c
*/

#include "my.h"

/*void move_rect(sfIntRect * rect , int offset, int max_value)
{
    if (rect->left < max_value) {
        rect->left += offset;
    } else {
        rect->left = 0;
    }
}

sfIntRect new_condition(sfIntRect rect, player *gamer)
{
    if (gamer->seconds > 0.1) {
        move_rect(&rect, 40, 160);
        sfSprite_setTextureRect(gamer->player, rect);
        sfClock_restart(gamer ->clock);
    }
    return rect;
}

sfIntRect condition1(sfIntRect rect,player *g)
{
    if (sfKeyboard_isKeyPressed(sfKeyDown)) {
        rect.top = 0; g ->mouve.y = g ->mouve.y + 1.5;
        rect = new_condition(rect, g);
        sfSprite_setPosition(g ->player,g ->mouve);
    } if (sfKeyboard_isKeyPressed(sfKeyLeft)) {
        rect.top = 40; g ->mouve.x = g ->mouve.x - 1.5;
        rect = new_condition(rect, g);
        sfSprite_setPosition(g ->player,g ->mouve);
    }
    return rect;
}

sfIntRect player_func(sfIntRect rect, player *gamer)
{
    gamer ->mouve = sfSprite_getPosition(gamer ->player);
    float x = (gamer ->mouve.x) / 40; float y = (gamer ->mouve.y) / 40;
    sfVector2i collision = {(int){x}, (int) {y}};
    rect = condition1(rect,gamer);
    if (sfKeyboard_isKeyPressed(sfKeyRight)) {
        rect.top = 80; gamer ->mouve.x = gamer ->mouve.x + 1.5;
        rect = new_condition(rect, gamer);
        sfSprite_setPosition(gamer ->player,gamer ->mouve);
    } if (sfKeyboard_isKeyPressed(sfKeyUp)) {
        rect.top = 120; gamer ->mouve.y = gamer ->mouve.y - 1.5;
        rect = new_condition(rect, gamer);
        sfSprite_setPosition(gamer ->player,gamer ->mouve);
    } return rect;
}*/
