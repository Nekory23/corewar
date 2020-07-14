##
## EPITECH PROJECT, 2020
## corewar
## File description:
## Makefile asm
##

NAME	=	asm

SRC	=	src/main.c 			\
		src/display_help.c		\
		src/get_name.c			\
		src/get_data.c			\
		src/get_champ.c			\
		src/get_comment.c		\
		src/check_lines.c		\
		src/check_instructions.c	\
		src/check_args.c		\
		src/check_args_bis.c		\
		src/gest_live.c			\
		src/gest_sti.c			\
		src/gest_aff.c			\
		src/gest_fork_lld_lldi_lfork.c	\
		src/gest_ldi.c			\
		src/gest_add_sub.c		\
		src/gest_and_or_xor.c		\
		src/gest_st.c			\
		src/gest_ld.c			\
		src/gest_zjmp.c			\
		src/print_the_error.c		\
		$(wildcard util/*.c)

CC	?=	gcc

CFLAGS	=	-W -Wextra -Wall

CPPFLAGS	=	-I./include/

CFFLAGS	=	tests/unit_tests.c -I./include --coverage -lcriterion

OBJ	=	$(SRC:.c=.o)

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(CPPFLAGS) $(LDFLAGS)

tests_run	:
		$(CC) -o unit_tests src/*.c $(CFFLAGS)

debug	:	CFLAGS += -g
debug	:	re

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
