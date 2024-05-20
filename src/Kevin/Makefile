##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile><
##

SRC	=	animation.c \
		events_of_animation.c \
		scenario_1.c \
		poursuite1.c \
		scenario2.c \
		entre_dans_le_laby.c \
		cache_cache.c \
		courir_chambre.c \
		courir_couloir.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_spark

BONUS_NAME = 	my_radar_bonus

UNIT_TEST = unit_test

L_FLAGS = -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

all:	$(NAME) clean

$(NAME):	$(OBJ)
	gcc  $(SRC) $(L_FLAGS) -g3 -lm -o $(NAME)

clean :
	rm -f *vgcore.*
	rm -f $(OBJ)
	rm -f *.gcno
	rm -f *.gcda
	rm -f *~

fclean: clean
	rm -f coding-style-reports.log
	rm -f $(UNIT_TEST)
	rm -f $(NAME)
	rm -f coding-style-reports.log

re:	fclean all
