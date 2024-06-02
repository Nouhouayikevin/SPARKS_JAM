##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

SRC	=	victory.c	\
		defeat.c

OBJ	=	$(SRC:.c=.o)

NAME	=	julci

UNIT_TEST = unit_test

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(SRC) -lcsfml-graphics \
	-lcsfml-system -lcsfml-audio -lcsfml-window

clean :
	rm -f $(OBJ)
	rm -f *.gcno
	rm -f *.gcda
	rm -f *~

fclean: clean
	rm -f coding-style-reports.log
	rm -f $(UNIT_TEST)
	rm -f $(NAME)

re:	fclean all

unit_tests:	fclean $(NAME)
	gcc -o $(UNIT_TEST) $(SRC) tests/tests_of_my_printf.c	\
	--coverage -lcriterion -lgcov

tests_run:	unit_tests
		./$(UNIT_TEST)
		gcovr
