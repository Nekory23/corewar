/*
** EPITECH PROJECT, 2020
** corewar (asm)
** File description:
** checks the args for forl, lld, lldi and lfork
*/

#include "asm.h"

int gest_fork_lld_lldi_lfork(core_t *core, char *instr, int line)
{
    int nbr = get_nbr_args(core->data[line - 1], ',');

    if (nbr != 1)
        return (display_error(core, line, nbr, 1));
    return (FALSE);
}
