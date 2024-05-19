/*
** EPITECH PROJECT, 2024
** JAM: Flame
** File description:
** move_player_t.c
*/

#include "../../include/jam.h"

// Use this Function to initialize the flame structure (Atôtô gbé)

flame_t initialize_flame_struct(void)
{
    flame_t f;
    f.rect.top = 0;
    f.rect.left = 0;
    f.rect.width = 96;
    f.rect.height = 96;
    f.sprite = sfSprite_create();
    f.texture = sfTexture_createFromFile("./pictures/fire.png", NULL);
    sfSprite_setTexture(f.sprite, f.texture, sfFalse);
    return f;
}

// Use this function before displaying the window (Atôtô gbé)

flame_t pixels_flame(sfRenderWindow *window, flame_t f, sfVector2f pos)
{
    if (f.rect.top < 450) {
        if (f.rect.left < 350) {
            sfSprite_setTextureRect(f.sprite, f.rect);
            sfRenderWindow_drawSprite(window, f.sprite, NULL);
            f.rect.left += 96;
        }
        if (f.rect.left > 350) {
            f.rect.left = 0;
            f.rect.top += 96;
        }
    }
    f.rect.top = (f.rect.top > 450) ? 0 : f.rect.top;
    sfSprite_setPosition(f.sprite, pos);
    sfSprite_setTextureRect(f.sprite, f.rect);
    sfRenderWindow_drawSprite(window, f.sprite, NULL);
    return f;
}

// (Atôtô gbé wê là)
