##
## EPITECH PROJECT, 2024
## makefile
## File description:
## makefile
##

NAME	=	sparks

SRC	=	main.c	\
		src/Ramdon/menu.c	\

OBJ	=	$(SRC:.c=.o)


all	:	$(OBJ)
		gcc -o $(NAME) $(SRC) -lcsfml-graphics -lcsfml-window \
	-lcsfml-system -lcsfml-audio -lm

clean	:
		rm -f $(OBJ)

fclean 	:	clean
		rm -f $(NAME)

re	:	fclean all
