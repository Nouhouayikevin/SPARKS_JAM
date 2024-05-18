/*
** EPITECH PROJECT, 2024
** my_player.c
** File description:
** my_player.c
*/

#include "my.h"
sfRectangleShape *create_rectangle(void)
{
    sfVector2f size = {35, 35};
    sfRectangleShape *rectangle = sfRectangleShape_create();

    sfRectangleShape_setFillColor(rectangle, sfTransparent);
    sfRectangleShape_setOutlineColor(rectangle, sfYellow);
    sfRectangleShape_setOutlineThickness(rectangle, 1.6);
    sfRectangleShape_setSize(rectangle, size);
    return rectangle;
}
void move_rect(sfIntRect * rect , int offset, int max_value)
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
}

void creator(new_struct *hunter)
{
    sfVideoMode mode = {1920, 1080, 64};
    hunter->win = sfRenderWindow_create(mode, "RMV", sfResize | sfClose, NULL);
    hunter->game = sfTexture_createFromFile("res/black.jpg", NULL);
    hunter->sprite_game = sfSprite_create();
    sfSprite_setTexture(hunter->sprite_game, hunter->game, sfTrue);
}

int create_player(player *gamer)
{
    gamer ->p_texture = sfTexture_createFromFile("luffy.png", NULL);
    if (!gamer ->p_texture)
        return EXIT_FAILURE;
    gamer ->player = sfSprite_create();
    gamer->clock = sfClock_create();
    //sfVector2f origin ={ 0 , 0};
    sfSprite_setTexture(gamer ->player, gamer ->p_texture, sfTrue);
    sfVector2f scale = {0.8, 0.8};
    //fSprite_setOrigin(gamer->player,origin);
    sfSprite_setScale(gamer -> player, scale);
}

void menu_and_game_launch(new_struct *hunter , player *game, sfIntRect rect, sfRectangleShape *renaud)
{
    renaud = create_rectangle();
    while (sfRenderWindow_isOpen(hunter->win)){
    game ->time = sfClock_getElapsedTime(game ->clock);
    game ->seconds = game->time.microseconds / 1000000.0;
        while (sfRenderWindow_pollEvent(hunter->win, &(hunter->event))){
              if (hunter->event.type == sfEvtClosed){
            sfRenderWindow_close(hunter->win);
        }
                rect = player_func(rect, game);
        }
        sfRectangleShape_setPosition(renaud, game->mouve);
        sfRenderWindow_drawSprite(hunter->win, hunter->sprite_game, NULL);
        sfRenderWindow_drawSprite(hunter->win, game->player, NULL);
        sfRenderWindow_drawRectangleShape(hunter->win, renaud, NULL);
        sfRenderWindow_display(hunter->win);
    }
    sfTexture_destroy(hunter->game);
    sfSprite_destroy(hunter->sprite_game);
    sfClock_destroy(hunter->clock);
    sfRenderWindow_destroy(hunter->win);
}


int main(int ac, char *av)
{
    new_struct *hunter = malloc(sizeof(new_struct));
    player *game  = malloc(sizeof(player));
    sfRectangleShape *renaud;
    sfIntRect rect = {0, 0, 40, 40};
    creator(hunter);
    create_player(game);
    menu_and_game_launch(hunter ,game, rect,renaud);
}