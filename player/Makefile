##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

SRC	=	my_player.c	\
		move_player.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_radar

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(SRC) -lcsfml-graphics -lcsfml-window -lcsfml-system	\
	-lcsfml-audio -lm -g3

clean :
	rm -f $(OBJ)

fclean: clean
	rm -rf coding-style-reports.log
	rm -f $(NAME)
	rm -f *~

re:	fclean all
