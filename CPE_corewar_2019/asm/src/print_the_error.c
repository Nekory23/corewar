/*
** EPITECH PROJECT, 2020
** corewar (asm)
** File description:
** print the error
*/

#include "asm.h"

void my_error(core_t *core, int i, const char *error)
{
    write_error("asm, ");
    write_error(core->file);
    write_error(", line ");
    my_put_nbr_error(i);
    write_error(error);
}
