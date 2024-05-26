/*
** EPITECH PROJECT, 2024
** Window
** File description:
** Day13
*/
#include "../../include/jam.h"
int nuit = 230;
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
    sfVector2f size = {1920, 1080};
    sfVector2f pos = {0, 0};
    sfIntRect p_rect = sfSprite_getTextureRect(p.sprite);
    p_rect.height += -400;
    p_rect.width += -400;
    p_rect.left += -400;
    p_rect.top += -400;
    key.monde = sfRectangleShape_create();
    sfRectangleShape_setPosition(key.monde, pos);
    sfRectangleShape_setSize(key.monde, size);
    sfRectangleShape_setFillColor(key.monde, sfColor_fromRGBA(0,0,0, 230));
    key.texture = sfTexture_createFromFile("./src/Tobi/lab.jpg", NULL);
    key.sprite = sfSprite_create();
    sfSprite_setTexture(key.sprite, key.texture, sfTrue);
    sfSprite_setScale(key.sprite, scale);
    return key;
}

void draw_fire_rectangles(sfRenderWindow *window, flame_t flames[], int num_flames)
{
    sfRectangleShape *rectangle;
    sfVector2f position;
    sfVector2f size = {40, 40};

    for (int i = 0; i < num_flames; i++) {
        rectangle = sfRectangleShape_create();
        position = sfSprite_getPosition(flames[i].sprite);
        position.x += 30;
        position.y += 56;
        sfRectangleShape_setPosition(rectangle, position);
        sfRectangleShape_setSize(rectangle, size);
        sfRectangleShape_setFillColor(rectangle, sfTransparent);
        sfRectangleShape_setOutlineColor(rectangle, sfGreen);
        sfRectangleShape_setOutlineThickness(rectangle, 1.0);
        sfRenderWindow_drawRectangleShape(window, rectangle, NULL);
        sfRectangleShape_destroy(rectangle);
    }
}


void draw_sprite(affiche key)
{
    sfRenderWindow_drawSprite(key.window, key.sprite, NULL);
}

int launch_labyrinth(sfRenderWindow *window, sfSound *song)
{
    sfClock *clock1 = sfClock_create();
    sfClock *clock2 = sfClock_create();
    sfClock *clock3 = sfClock_create();
    sfClock *clock4 = sfClock_create();
    sfClock *clock5 = sfClock_create();
    sfClock *clock6 = sfClock_create();
    sfVector2f scale = {0.4, 0.35};
    sfVector2f life_pos = {1700, 10};
    sfVideoMode m = {1920, 1080, 32};
    rect_t *rectangle = my_rectangle(rectangle);
    move_player_t p = init_move_player_t_struct(p);
    int i = 0;
    affiche key = my_texture(p);
    flame_t f1 = initialize_flame_struct();
    flame_t f2 = initialize_flame_struct();
    flame_t f3 = initialize_flame_struct();
    flame_t f4 = initialize_flame_struct();
    flame_t f5 = initialize_flame_struct();
    flame_t f6 = initialize_flame_struct();

    flame_t flames[] = {f1, f2, f3, f4, f5, f6};

    key.window = window;
    rect_t *fire_angle = create_rectangle(fire_angle);
    sfRenderWindow_setFramerateLimit(key.window, 700);
    while (sfRenderWindow_isOpen(key.window)){
        if (sfSound_getStatus(song) == sfStopped) {
        sfSound_play(song);
    }
        p = event_handler(key.event, key.window, scale, p, rectangle);
        sfRenderWindow_clear(key.window, sfBlack);
        draw_sprite(key);
        sfRenderWindow_drawRectangleShape(key.window, key.monde, NULL);
        for (i = 0; fire_angle[i].rect != NULL; i++)
            sfRenderWindow_drawRectangleShape(key.window, fire_angle[i].rect, NULL);
        i = 0;
        while (rectangle[i].rect != NULL){
            sfRenderWindow_drawRectangleShape(key.window, rectangle[i].rect, NULL);
            i++;
        }
        sfIntRect p_rect = sfSprite_getTextureRect(p.sprite);
        p_rect.height += -400;
        p_rect.width += -400;
        p_rect.left += -400;
        p_rect.top += -400;
        sfVector2f pos = {500 , 0};
        sfVector2f scale = {0.5, 0.5};
        sfSprite_setPosition(p.sprite, pos);
        set_and_draw_player(p, key.window);
        if (f1.f == 0)
            f1 = pixels_clock(key.window, f1, (sfVector2f){200, 787}, clock1);
        if (rect_col(fire_angle[0].rect, sfRectangleShape_getPosition(p.outline), sfRectangleShape_getSize(p.outline)) == 0 && f1.f == 0){
            f1.f = 1;
            nuit += -7;
            sfRectangleShape_setFillColor(key.monde, sfColor_fromRGBA(0,0,0,nuit));
        }
        if (f2.f == 0)
            f2 = pixels_clock(key.window, f2, (sfVector2f){180, 80}, clock2);
        if (rect_col(fire_angle[1].rect, sfRectangleShape_getPosition(p.outline), sfRectangleShape_getSize(p.outline)) == 0 && f2.f == 0){
            f2.f = 1;
            nuit += -9;
            sfRectangleShape_setFillColor(key.monde, sfColor_fromRGBA(0,0,0,nuit));
        }
        if (f3.f == 0)
            f3 = pixels_clock(key.window, f3, (sfVector2f){980, 420}, clock3);
        if (rect_col(fire_angle[2].rect, sfRectangleShape_getPosition(p.outline), sfRectangleShape_getSize(p.outline)) == 0 && f3.f == 0){
            f3.f = 1;
            nuit += -11;
            sfRectangleShape_setFillColor(key.monde, sfColor_fromRGBA(0,0,0,nuit));
        }
        if (f4.f == 0)
            f4 = pixels_clock(key.window, f4, (sfVector2f){970, 715}, clock4);
        if (rect_col(fire_angle[3].rect, sfRectangleShape_getPosition(p.outline), sfRectangleShape_getSize(p.outline)) == 0 && f4.f == 0){
            f4.f = 1;
            nuit += -13;
            sfRectangleShape_setFillColor(key.monde, sfColor_fromRGBA(0,0,0,nuit));
        }
        if (f5.f == 0)
            f5 = pixels_clock(key.window, f5, (sfVector2f){1600, 50}, clock5);
        if (rect_col(fire_angle[4].rect, sfRectangleShape_getPosition(p.outline), sfRectangleShape_getSize(p.outline)) == 0 && f5.f == 0){
            f5.f = 1;
            nuit += -15;
            sfRectangleShape_setFillColor(key.monde, sfColor_fromRGBA(0,0,0,nuit));
        }
        if (f6.f == 0)
            f6 = pixels_clock(key.window, f6, (sfVector2f){1780, 860}, clock6);
        if (rect_col(fire_angle[5].rect, sfRectangleShape_getPosition(p.outline), sfRectangleShape_getSize(p.outline)) == 0 && f6.f == 0){
            f6.f = 1;
            nuit += -15;
            sfRectangleShape_setFillColor(key.monde, sfColor_fromRGBA(0,0,0,nuit));
        }
        sfRenderWindow_display(key.window);sfRenderWindow_display(key.window);
    }
    for (i = 0; rectangle[i].rect != NULL; i++)
        sfRectangleShape_destroy(rectangle[i].rect);
        sfSprite_destroy(key.sprite);
        destroy_player_val(p);
    sfClock_destroy(clock1);
    sfClock_destroy(clock2);
    sfClock_destroy(clock3);
    sfClock_destroy(clock4);
    sfClock_destroy(clock5);
    sfClock_destroy(clock6);
}
