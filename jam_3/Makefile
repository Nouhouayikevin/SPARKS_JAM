##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Ceci est mon makefile
##

UNIT_TEST = unit_test

NAME =	dedal

SRC = 	src/opening_a_window.c	\
		src/rectangle.c	\
		src/move_player.c	\
		src/collide.c
OBJ =	$(SRC:.c=.o)

all: $(OBJ)
	gcc $(SRC) -o $(NAME) -lcsfml-audio -lcsfml-graphics \
	-lcsfml-window -lcsfml-system -lm

clean:
		rm $(OBJ)
		rm -f *.o
		rm -rf *#

fclean: clean
		rm -f $(NAME)

re: fclean all

# unit_tests: fclean all
# 	gcc -o $(UNIT_TEST) $(SRC) tests/test_neutrino.c	\
# 	--coverage -lcriterion -lgcov -lm

# tests_run:	re unit_tests
# 			./unit_test
# 			gcovr
# 			rm *.gcno
# 			rm -f *gc*
