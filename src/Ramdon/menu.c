/*
** EPITECH PROJECT, 2024
** menu
** File description:
** menu
*/
#include "../../include/jam.h"

int x;
int i;
int stop_animation = 0;
sfText *text_to_draw = NULL;
sfFont *font;
menu_t *ptr;
flame_t f1;
flame_t f2;
flame_t f3;
sfTexture *texture = NULL;
sfSprite *sprite = NULL;
sfSound *song;

sfSound *sound()
{
    sfSound *sound;
    sfSoundBuffer *musique;
    sound = sfSound_create();
    musique = sfSoundBuffer_createFromFile("./audio/camelot.ogg");
    sfSound_setBuffer(sound, musique);
    sfSound_play(sound);
    return sound;
}

void init_menu()
{
    ptr = malloc(sizeof(menu_t));
    if (ptr == NULL) {
    printf("Allocation error.\n");
    return;
    }
    ptr->images = malloc(sizeof(char *) * 4);
    if (ptr->images == NULL) {
        printf("Allocation error.\n");
        return;
    }
    ptr->flames = malloc(sizeof(char *) * 19);
    if (ptr->flames == NULL) {
        printf("Allocation error.\n");
        return;
    }
    font = sfFont_createFromFile("./font/font.ttf");

    ptr->images[0] = "./pictures/image1.png";
    ptr->images[1] = "./pictures/image2.png";
    ptr->images[2] = "./pictures/image3.png";
    ptr->images[3] = NULL;

    ptr->flames[0] = "./pictures/flame1.png";
    ptr->flames[1] = "./pictures/flame2.png";
    ptr->flames[2] = "./pictures/flame3.png";
    ptr->flames[3] = "./pictures/flame4.png";
    ptr->flames[4] = "./pictures/flame5.png";
    ptr->flames[5] = "./pictures/flame6.png";
    ptr->flames[6] = "./pictures/flame7.png";
    ptr->flames[7] = "./pictures/flame8.png";
    ptr->flames[8] = "./pictures/flame9.png";
    ptr->flames[9] = "./pictures/flame10.png";
    ptr->flames[10] = "./pictures/flame11.png";
    ptr->flames[11] = "./pictures/flame12.png";
    ptr->flames[12] = "./pictures/flame13.png";
    ptr->flames[13] = "./pictures/flame14.png";
    ptr->flames[14] = "./pictures/flame15.png";
    ptr->flames[15] = "./pictures/flame16.png";
    ptr->flames[16] = "./pictures/flame17.png";
    ptr->flames[17] = "./pictures/flame18.png";
    ptr->flames[18] = NULL;
}

void free_menu()
{
    if (ptr != NULL) {
        if (ptr->images != NULL) {
            free(ptr->images);
        }
        if (ptr->flames != NULL) {
            free(ptr->flames);
        }
        free(ptr);
    }
    if (font != NULL) {
        sfFont_destroy(font);
    }
}

void draw_static_text(sfRenderWindow *window, char *str, sfVector2f position)
{
    sfText *quit;

    quit = sfText_create();
    sfText_setString(quit, str);
    sfText_setFont(quit, font);
    sfText_setCharacterSize(quit, 25);
    sfText_setPosition(quit, position);

    sfFloatRect text_rect = sfText_getGlobalBounds(quit);

    sfVector2i mouse_position = sfMouse_getPositionRenderWindow(window);
    if (mouse_position.x >= text_rect.left && mouse_position.x <= text_rect.left + text_rect.width &&
        mouse_position.y >= text_rect.top && mouse_position.y <= text_rect.top + text_rect.height) {
        sfText_setCharacterSize(quit, 30);
        sfText_setColor(quit, sfGreen);
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            if (strcmp(str, "START") == 0) {
                //hystory_debut(window, song);
                launch_labyrinth(window, song);
            }
            if (strcmp(str, "SETTING") == 0) {
            }
            if (strcmp(str, "QUIT") == 0) {
                sfRenderWindow_close(window);
                exit(0);
            }
        }
    } else {
        sfText_setCharacterSize(quit, 25);
        sfText_setColor(quit, sfWhite);
    }

    sfRenderWindow_drawText(window, quit, NULL);
}

void draw_text(sfRenderWindow *window, char *text, sfVector2f position)
{
    sfText *sf_text;

    sf_text = sfText_create();
    sfText_setString(sf_text, text);
    sfText_setFont(sf_text, font);
    sfText_setCharacterSize(sf_text, 35);
    sfText_setPosition(sf_text, position);

    sfRenderWindow_drawText(window, sf_text, NULL);
}

void draw_text_char_by_char(sfRenderWindow *window, char *text, sfVector2f position)
{
   /*int len = strlen(text);
    char *temp_text = malloc(len + 1);

    for (int i = 0; i < len; i++) {
        temp_text[i] = text[i];
        temp_text[i + 1] = '\0';
        if (text[i] == 'E' && text[i + 1] == '\0')
            break;
        if (text_to_draw != NULL) {
            sfText_destroy(text_to_draw);
        }
        if (stop_animation == 1)
            break;
        draw_text(window, temp_text, position);
        sfRenderWindow_display(window);
        sfSleep(sfMilliseconds(100));
    }
    free(temp_text);*/
}

void flame_animation(sfRenderWindow **window, int flame_index)
{
    sfTexture *flame_text = NULL;
    sfSprite *flame_sprite = NULL;
    sfVector2f position = {890, 380};

    flame_text = sfTexture_createFromFile(ptr->flames[flame_index], NULL);
    if (!flame_text) {
        printf("The texture failed to load\n");
        return;
    }
    flame_sprite = sfSprite_create();
    sfSprite_setTexture(flame_sprite, flame_text, sfTrue);
    sfSprite_setPosition(flame_sprite, position);
    sfRenderWindow_drawSprite(*window, flame_sprite, NULL);
    sfSprite_destroy(flame_sprite);
    sfTexture_destroy(flame_text);
}

void display_menu(sfRenderWindow *window, int image_index)
{
    if (texture == NULL) {
        texture = sfTexture_createFromFile(ptr->images[image_index], NULL);
        sprite = sfSprite_create();
        sfSprite_setTexture(sprite, texture, sfTrue);
    }
    else {
        sfTexture_destroy(texture);
        texture = sfTexture_createFromFile(ptr->images[image_index], NULL);
        sfSprite_setTexture(sprite, texture, sfTrue);
    }
    if (image_index == 1) {
        sfVector2f scale = {1.005, 1.002};
        sfSprite_setScale(sprite, scale);
    }
    sfRenderWindow_drawSprite(window, sprite, NULL);
    if (image_index == 2) {
        if (song == NULL) {
            song = sound();
        } else if (sfSound_getStatus(song) == sfStopped) {
            sfSound_play(song);
        }
        sfVector2f scale = {1.250, 1.150};
        sfVector2f scale_flammes = {1.9, 1.9};
        sfSprite_setScale(sprite, scale);
        sfSprite_setScale(f1.sprite, scale_flammes);
        sfSprite_setScale(f2.sprite, scale_flammes);
        sfSprite_setScale(f3.sprite, scale_flammes);
        sfRenderWindow_drawSprite(window, sprite, NULL);
        f1 = pixels_flame(window, f1, (sfVector2f){527, 412});
        f2 = pixels_flame(window, f2, (sfVector2f){1215, 418});
        f3 = pixels_flame(window, f3, (sfVector2f){282, 587});
        draw_static_text(window, "START", (sfVector2f){932, 531});
        draw_static_text(window, "SETTING", (sfVector2f){932, 605});
        draw_static_text(window, "QUIT", (sfVector2f){932, 680});
        } else {
        if (song != NULL) {
            sfSound_stop(song);
            sfSound_destroy(song);
            song = NULL;
        }
    }

    if (image_index == 0) {
        if (text_to_draw == NULL) {
        draw_text_char_by_char(window, "REALISE PAR :", (sfVector2f){730, 90});
        draw_text_char_by_char(window, "BEHANZIN Joseph", (sfVector2f){500, 400});
        draw_text_char_by_char(window, "OKE Julcinia", (sfVector2f){500, 500});
        draw_text_char_by_char(window, "AGONGBONON Tobi", (sfVector2f){500, 600});
        draw_text_char_by_char(window, "OGOUYOMI Ramdon", (sfVector2f){1050, 400});
        draw_text_char_by_char(window, "NOUHOUAYI Kevin", (sfVector2f){1050, 500});
        draw_text_char_by_char(window, "VIGNON Renaud-Marie", (sfVector2f){1050, 600});
        } else {
            sfRenderWindow_drawText(window, text_to_draw, NULL);
        }
        for (int flame_index = 0; flame_index < 18; flame_index++) {
            flame_animation(&window, flame_index);
            sfRenderWindow_display(window);
            sfSleep(sfMilliseconds(100));
            if (stop_animation == 1) {
                stop_animation = 0;
                break;
            }
        }
    }
}

int menu_event(sfRenderWindow *window, sfEvent event, int *image_index)
{
    sfVector2i mouse = sfMouse_getPosition((const sfWindow*)window);

    if (event.type == sfEvtClosed) {
        sfRenderWindow_close(window);
        exit(0);
    }
    if (event.type == sfEvtMouseButtonPressed) {
	x = 1;
	i = 1;
    stop_animation = 1;
        return 1;
    }
    return 0;
}

void menu(sfRenderWindow* window)
{
    sfEvent event;
    int image_index = 0;
    x = 0;
    i = 0;

    f1 = initialize_flame_struct();
    f2 = initialize_flame_struct();
    f3 = initialize_flame_struct();
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            menu_event(window, event, &image_index);
        }
        sfRenderWindow_clear(window, sfBlack);
        if (x == 0) {
            display_menu(window, image_index);
            sfRenderWindow_display(window);
            sfSleep(sfMilliseconds(1300));
            image_index = (image_index + 1) % 3;
        } else if (x == 1) {
            display_menu(window, image_index);
            sfRenderWindow_display(window);
            image_index = (i == 1) ? (image_index + 1) % 3: image_index;
        }
        i = 0;
    }
}

void launch_menu(sfRenderWindow *window)
{
    init_menu();
    if (ptr == NULL || ptr->images == NULL || ptr->flames == NULL) {
        printf("The menu failed to load.\n");
        return;
    }
    menu(window);
    free_menu();
}
