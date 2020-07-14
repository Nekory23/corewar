/*
** EPITECH PROJECT, 2020
** corewar (asm)
** File description:
** gest for aff
*/

#include "asm.h"

int gest_aff(core_t *core, char *instr, int line)
{
    int nbr = get_nbr_args(core->data[line - 1], ',');

    if (nbr != 1)
        return (display_error(core, line, nbr, 1));
    return (FALSE);
}
