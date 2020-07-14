##
## EPITECH PROJECT, 2020
## corewar
## File description:
## Makefile corewar
##

NAME	=	corewar

SRC	=	src/main.c 		\
		src/display_help.c	\
		util/my_putchar.c	\
		util/my_putstr.c	\
		util/my_strlen.c	\
		util/my_strcmp.c	\
		util/write_error.c	\

CC	?=	gcc

CFLAGS	=	-W -Wextra -Wall

CPPFLAGS	=	-I./include/

CFFLAGS	=	tests/unit_tests.c -I./include --coverage -lcriterion

OBJ	=	$(SRC:.c=.o)

all	:	$(OBJ)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(CPPFLAGS) $(LDFLAGS)

tests_run	:
		$(CC) -o unit_tests src/*.c $(CFFLAGS)

clean	:
		rm -f $(OBJ)

fclean	:	clean
		rm -f $(NAME)		\
		rm -f *# 		\
		rm -f src/*# 		\
		rm -f include/*# 	\
		rm -f *~ 		\
		rm -f src/*~ 		\
		rm -f include/*~ 	\
		rm -f *.gcda 		\
		rm -f *.gcno		\

re	:	fclean all

.PHONY	:	all debug tests_run clean fclean re
