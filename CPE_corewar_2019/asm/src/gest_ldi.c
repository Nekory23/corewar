/*
** EPITECH PROJECT, 2020
** corewar (asm)
** File description:
** gest ldi
*/

#include "asm.h"

int gest_ldi(core_t *core, char *instr, int line)
{
    int nbr = get_nbr_args(core->data[line - 1], ',');

    if (nbr != 3)
        return (display_error(core, line, nbr, 3));
    return (FALSE);
}
