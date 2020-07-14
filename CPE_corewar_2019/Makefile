##
## EPITECH PROJECT, 2020
## corewar
## File description:
## Makefile root
##

ASM	=	asm/

COREWAR	=	corewar/

all	:	$(OBJ)
		make -C $(ASM)
		make -C $(COREWAR)

clean	:
		make clean -C $(ASM)
		make clean -C $(COREWAR)

fclean	:	clean
		make fclean -C $(ASM)
		make fclean -C $(COREWAR)

re	:	fclean all

.PHONY	:	all clean fclean re
