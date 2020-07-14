/*
** EPITECH PROJECT, 2020
** corewar (asm)
** File description:
** gest_and_or_xor
*/

#include "asm.h"

int gest_and_or_xor(core_t *core, char *instr, int line)
{
    int nbr = get_nbr_args(core->data[line - 1], ',');

    if (nbr != 3)
        return (display_error(core, line, nbr, 3));
    return (FALSE);
}
