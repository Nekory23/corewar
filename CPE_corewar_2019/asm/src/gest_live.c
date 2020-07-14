/*
** EPITECH PROJECT, 2020
** corewar (asm)
** File description:
** check if the args given to live are correct
*/

#include "asm.h"

int gest_live(core_t *core, char *instr, int line)
{
    int nbr = get_nbr_args(core->data[line - 1], ',');

    if (nbr != 1)
        return (display_error(core, line, nbr, 1));
    return (FALSE);
}
