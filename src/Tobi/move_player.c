/*
** EPITECH PROJECT, 2024
** JAM: Flame
** File description:
** move_player_t.c
*/

#include "../../include/jam.h"

move_player_t init_move_player_t_struct(move_player_t player)
{
    player.pos = (sfVector2f){130, 910};
    player.sprite = sfSprite_create();
    player.scale = (sfVector2f){0.8, 0.7};
    player.rect = (sfIntRect){0, 640, 64, 64};
    player.outline_size = (sfVector2f){18, 18};
    player.outline = sfRectangleShape_create();
    sfSprite_setScale(player.sprite, player.scale);
    sfRectangleShape_setScale(player.outline, player.scale);
    sfRectangleShape_setOutlineColor(player.outline, sfTransparent);
    sfRectangleShape_setOutlineThickness(player.outline, 2.0);
    player.texture = sfTexture_createFromFile("./src/Tobi/male.png", NULL);
    sfSprite_setTexture(player.sprite, player.texture, sfFalse);
    sfRectangleShape_setFillColor(player.outline, sfTransparent);
    sfRectangleShape_setSize(player.outline, player.outline_size);
    return player;
}

/*move_player_t cut_player_move(move_player_t p, sfEvent event, rect_t *rectangle)
{
    is_movable = true;
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyUp) {
        p.rect.top = 512;
        p.rect.left = (p.rect.left < 500) ? p.rect.left + 64 : 0;
        in_collide(rectangle, p, 0, -5.5);
        //if (in_collide(rectangle, p, 0, -5.5) == 1)
        if (is_movable == true)
            p.pos.y -= 5.5;
    }
    is_movable = true;
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyDown) {
        p.rect.top = 640;
        p.rect.left = (p.rect.left < 500) ? p.rect.left + 64 : 0;
        in_collide(rectangle, p, 0, 5.5);
        //if (in_collide(rectangle, p, 0, 5.5) == 1)
        if (is_movable == true)
            p.pos.y += 5.5;
    }
    is_movable = true;
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyLeft) {
        p.rect.top = 576;
        p.rect.left = (p.rect.left < 500) ? p.rect.left + 64 : 0;
        in_collide(rectangle, p, -5.5, 0);
        //if (in_collide(rectangle, p, -5.5, 0) == 1)
        if (is_movable == true) 
            p.pos.x -= 5.5;
    }
    is_movable = true;
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyRight) {
        p.rect.top = 704;
        p.rect.left = (p.rect.left < 500) ? p.rect.left + 64 : 0;
        in_collide(rectangle, p, 5.5, 0);
        //if (in_collide(rectangle, p, 5.5, 0) == 1)
        if (is_movable == true)
            p.pos.x += 5.5;
    }
    return p;
}*/

move_player_t cut_player_move(move_player_t p, sfEvent event, rect_t *rectangle)
{
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyUp) {
        p.rect.top = 512;
        p.rect.left = (p.rect.left < 500) ? p.rect.left + 64 : 0;
        if (in_collide(rectangle, p, 5.5, -5.5) == 1)
            p.pos.y -= 5.5;
    }
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyDown) {
        p.rect.top = 640;
        p.rect.left = (p.rect.left < 500) ? p.rect.left + 64 : 0;
        if (in_collide(rectangle, p, 5.5, 5.5) == 1)
            p.pos.y += 5.5;
    }
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyLeft) {
        p.rect.top = 576;
        p.rect.left = (p.rect.left < 500) ? p.rect.left + 64 : 0;
        if (in_collide(rectangle, p, -5.5, 5.5) == 1)
            p.pos.x -= 5.5;
    }
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyRight) {
        p.rect.top = 704;
        p.rect.left = (p.rect.left < 500) ? p.rect.left + 64 : 0;
        if (in_collide(rectangle, p, 5.5, 5.5) == 1)
            p.pos.x += 5.5;
    }
    return p;
}

void set_and_draw_player(move_player_t p, sfRenderWindow *window)
{
    sfSprite_setPosition(p.sprite, p.pos);
    sfSprite_setTextureRect(p.sprite, p.rect);
    sfRectangleShape_setPosition(p.outline,
    (sfVector2f){p.pos.x + 10, p.pos.y + 20});
    sfRenderWindow_drawSprite(window, p.sprite, NULL);
    sfRenderWindow_drawRectangleShape(window, p.outline, NULL);
    return;
}

void destroy_player_val(move_player_t p)
{
    sfSprite_destroy(p.sprite);
    sfTexture_destroy(p.texture);
    sfRectangleShape_destroy(p.outline);
    return;
}
/*
int main(void)
{
    sfEvent event;
    sfRenderWindow *window;
    sfVideoMode mode = {1920, 1080, 32};
    move_player_t p = init_move_player_t_struct(p);

    window = sfRenderWindow_create(mode, "SFML window", sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window, 30);
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfBlack);
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
            p = cut_player_move(p, event);
        }
        set_and_draw_player(p, window);
        sfRenderWindow_display(window);
    }
    destroy_player_val(p);
    return EXIT_SUCCESS;
}
*/