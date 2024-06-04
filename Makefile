##
## EPITECH PROJECT, 2024
## makefile
## File description:
## makefile
##

NAME	=	sparks

SRC	=	main.c	\
		src/Ramdon/menu.c	\
		src/Tobi/opening_a_window.c	\
		src/Tobi/rectangle.c	\
		src/Tobi/move_player.c	\
		src/Tobi/collide.c	\
		src/Joseph/animate_flame.c	\
		src/Kevin/cache_cache.c	\
		src/Kevin/courir_chambre.c	\
		src/Kevin/courir_couloir.c	\
		src/Kevin/entre_dans_le_laby.c	\
		src/Kevin/events_of_animation.c	\
		src/Kevin/poursuite1.c	\
		src/Kevin/scenario_1.c	\
		src/Kevin/scenario2.c	\
		src/Kevin/animation.c	\
		src/Julci/victory.c	\

OBJ	=	$(SRC:.c=.o)


all	:	$(OBJ)
		gcc -o $(NAME) $(SRC) -lcsfml-graphics -lcsfml-window \
	-lcsfml-system -lcsfml-audio -lm

clean	:
		rm -f $(OBJ)

fclean 	:	clean
		rm -f $(NAME)

re	:	fclean all
