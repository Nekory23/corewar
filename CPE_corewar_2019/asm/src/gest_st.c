/*
** EPITECH PROJECT, 2020
** corewar (asm)
** File description:
** gest_st
*/

#include "asm.h"

int gest_st(core_t *core, char *instr, int line)
{
    int nbr = get_nbr_args(core->data[line - 1], ',');

    if (nbr != 2)
        return (display_error(core, line, nbr, 2));
    return (FALSE);
}
