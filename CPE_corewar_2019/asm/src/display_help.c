/*
** EPITECH PROJECT, 2020
** corewar
** File description:
** display the help (asm)
*/

#include "asm.h"

int display_help(void)
{
    my_putstr("USAGE\n./asm file_name[.s]\n");
    my_putstr("DESCRIPTION\nfile_name in assembly language ");
    my_putstr("to be converted into file_name.cor, an executable ");
    my_putstr("in the virtual Machine.\n");
    return (SUCCESS);
}
