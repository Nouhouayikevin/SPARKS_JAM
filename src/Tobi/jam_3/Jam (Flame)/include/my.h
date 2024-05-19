/*
** EPITECH PROJECT, 2024
** JAM: Flame
** File description:
** my.h
*/

#ifndef MY_H_
    #define MY_H_
    #include <stdlib.h>
    #include <SFML/Graphics.h>
    #include <SFML/Graphics.h>

typedef struct {
    sfIntRect rect;
    sfVector2f pos;
    sfVector2f scale;
    sfSprite* sprite;
    sfTexture* texture;
    sfVector2f outline_size;
    sfRectangleShape *outline;
} move_player_t;

#endif /* MY_H_ */
