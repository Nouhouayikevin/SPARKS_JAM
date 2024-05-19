/*
** EPITECH PROJECT, 2024
** collide.c
** File description:
** THis is my collision checker
*/

#include "../../include/jam.h"

int rect_col(sfRectangleShape *rect2, sfVector2f pos, sfVector2f pos_size)
{
    sfVector2f pos2;
    sfVector2f size;

    pos2 = sfRectangleShape_getPosition(rect2);
    size = sfRectangleShape_getSize(rect2);
    printf("pos_size.x = %.2f\n", pos_size.x);
    printf("size.x = %.2f\n", size.x);
    if ((pos.x + 18 < pos2.x || pos.y + 18 < pos2.y) ||
    (pos.x > pos2.x + size.x || pos.y > pos2.y + size.y))
       return 1;
    return 0;
}


int in_collide(rect_t *rectangle, move_player_t p, int x, int y)
{
    int i = 0;
    sfVector2f pos = sfRectangleShape_getPosition(p.outline);
    pos.x += x;
    pos.y += y;

    printf("pos.x = %.2f && pos.y = %.2f\n", pos.x, pos.y);
    while (rectangle[i].rect != NULL){
        if (rect_col(rectangle[i].rect, pos, sfRectangleShape_getSize(p.outline)) == 0) {
            return 0;
        }
        i++;
    }
    return 1;
}