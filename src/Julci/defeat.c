/*
** EPITECH PROJECT, 2024
** victory
** File description:
** victory
*/

int z = 0;

/*typedefstruct variables {
    sfSound *sound;
    sfSoundBuffer *musique;
    sfIntRect rect;
    sfVideoMode mode;
    sfRenderWindow* window;
    sfEvent event;
    sfVector2f scale;
    sfVector2f scale_visor;
    sfSprite *nv;
    sfSprite *background;
    sfSprite *birds;
    sfSprite *cursor;
    sfTexture *t_birds;
    sfTexture *t_cursor;
    sfTexture *t_nv;
    sfTexture *t_background;
    sfClock *clock;
    sfTime time;
    float seconds;
    sfVector2f pos;
    sfVector2f pos_c;
    sfVector2i position;
} data;*/

#include "../../include/jam.h"


/*void init_rect_and_mode(data *data)
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
    data->mode.bitsPerPixel =OB 32;
    data->sound = sfSound_create();
    //data->musique = sfSoundBuffer_createFromFile("musique/song.ogg");
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
void close_boucle_menu(menu *menu)
{
    while (sfRenderWindow_pollEvent(menu->window, &menu->event)) {
        if (menu->event.type == sfEvtClosed) {
            sfRenderWindow_close(menu->window);
        }
    }
}
*/

sfSound *sound()
{
    sfSound *sound;
    sfSoundBuffer *musique;
    sound = sfSound_create();
    musique = sfSoundBuffer_createFromFile("musique/song2.ogg");
    sfSound_setBuffer(sound, musique);
    sfSound_play(sound);
    return sound;
}

void move_rect(sfIntRect *rect)
{
    if (rect->left < 220) {
        rect->left = rect->left + 100;
    } else
        rect->left = 0;
}

void position(sfVector2f *pos)
{
    if (pos->x < 1920 && pos->y < 920 * 4) {
	pos->x += 50;
	pos->y += (z % 2) ? -1 * 50 : 70;
    } else {
	pos->x = 0;
	pos->y += (z % 2) ? -20 : 50;
	pos->y = (pos->y >= 400) ? 70 + 1 : pos->y; 
    }
}

void display(sfRenderWindow *window, int image_index)
{
    sfSprite *sprite;
    sfTexture *texture;
    menu_t *ptr = malloc(sizeof(menu_t));
    ptr->images = malloc(sizeof(char *) * 9);
    ptr->images[0] = "./'treasure chest'/'treasure chest0000.png'";
    ptr->images[1] = "./'treasure chest'/'treasure chest0001.png'";
    ptr->images[2] = "./'treasure chest'/'treasure chest0002.png'";
    ptr->images[3] = "./'treasure chest'/'treasure chest0003.png'";
    ptr->images[4] = "./'treasure chest'/'treasure chest0004.png'";
    ptr->images[5] = "./'treasure chest'/'treasure chest0005.png'";
    ptr->images[6] = "./'treasure chest'/'treasure chest0006.png'";
    ptr->images[7] = "./'treasure chest'/'treasure chest0007.png'";
    texture = sfTexture_createFromFile(ptr->images[image_index], NULL);
    if (!texture) {
        printf("The texture failed to load\n");
        return;
    }
    sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfRenderWindow_drawSprite(window, sprite, NULL);
    sfSprite_destroy(sprite);
    sfTexture_destroy(texture);
}

int menu_event(sfRenderWindow *window, sfEvent event, int *image_index)
{
    sfVector2i mouse = sfMouse_getPosition((const sfWindow*)window);

    if (event.type == sfEvtClosed)
        sfRenderWindow_close(window);
    if (event.type == sfEvtMouseButtonPressed) {
        return 1;
    }
    return 0;
}

void defeat(sfRenderWindow* window)
{
    sfVector2f scale = {4, 4};
    sfVector2f pos = {0, 20};
    sfSprite *sprite;
    sfSprite *sprite1;
    sfSprite *lose;
    sfSprite *crane;
    sfTexture *texture;
    sfTime time;
    float seconds;
    sfTexture *texture1;
    sfClock *clock = sfClock_create();
    sfEvent event;
    sfIntRect rect = {5, 5, 97, 150};
    int image_index = 0;
    menu_t *ptr = malloc(sizeof(menu_t));
    ptr->images = malloc(sizeof(char *) * 4);

    ptr->images[0] = "images/ghosts.png";
    ptr->images[1] = "images/defaite.png";
    texture = sfTexture_createFromFile(ptr->images[0], NULL);
    texture1 = sfTexture_createFromFile(ptr->images[1], NULL);
    sprite = sfSprite_create();
    sprite1 = sfSprite_create();
    lose = sfSprite_create();
    crane = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setTexture(sprite1, texture1, sfTrue);
    texture1 = sfTexture_createFromFile("images/crâne.png", NULL);
    sfSprite_setTexture(crane, texture1, sfTrue);
    texture1 = sfTexture_createFromFile("images/you_lose.jpeg", NULL);
    sfSprite_setTexture(lose, texture1, sfTrue);
    sfSound *song = sound();
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            menu_event(window, event, &image_index);
        }
        sfRenderWindow_clear(window, sfBlack);
	time = sfClock_getElapsedTime(clock);
	seconds = time.microseconds / 1000000.0;
	sfRenderWindow_drawSprite(window, sprite1, NULL);
	sfSprite_setPosition(lose,  (sfVector2f){500, 200});
	//sfSprite_setPosition(crane,  (sfVector2f){767, 585});
	sfSprite_setScale(lose, (sfVector2f){1.6, 1.6}); 
	sfRenderWindow_drawSprite(window, lose, NULL);
	//sfRenderWindow_drawSprite(window, crane, NULL);
	if (seconds > 0.10) { 
	    move_rect(&rect);
	    position(&pos);
	    sfSprite_setPosition(sprite, pos);
	    sfSprite_setTextureRect(sprite, rect);
	    sfSprite_setScale(sprite, scale); 
	    sfRenderWindow_drawSprite(window, sprite, NULL); 
	    z++; 
	    sfClock_restart(clock);
	} 
	sfSleep(sfMilliseconds(380));
	sfRenderWindow_display(window);
    }
}

/*int main(void)
{
    sfRenderWindow* window;
    sfVideoMode mode = {1920, 1080};
    window = sfRenderWindow_create(mode, "defeat", sfResize | sfClose, NULL);
    defeat(window);
    }*/
