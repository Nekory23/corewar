/*
** EPITECH PROJECT, 2020
** corewar (asm)
** File description:
** check the arguments
*/

#include "asm.h"

static int check_args_four(core_t *core, char *instr, int inst_nbr, int line)
{
    int ret = FALSE;

    switch (inst_nbr) {
    case 15 :
        ret = gest_aff(core, instr, line);
        break;
    }
    return (ret);
}

static int check_args_ter(core_t *core, char *instr, int inst_nbr, int line)
{
    int ret = FALSE;

    switch (inst_nbr) {
    case 10 :
        ret = gest_sti(core, instr, line);
        break;
    case 11 :
        ret = gest_fork_lld_lldi_lfork(core, instr, line);
        break;
    case 12 :
        ret = gest_fork_lld_lldi_lfork(core, instr, line);
        break;
    case 13 :
        ret = gest_fork_lld_lldi_lfork(core, instr, line);
        break;
    case 14 :
        ret = gest_fork_lld_lldi_lfork(core, instr, line);
        break;
    }
    ret = check_args_four(core, instr, inst_nbr, line);
    return (ret);
}

static int check_args_bis(core_t *core, char *instr, int inst_nbr, int line)
{
    int ret = FALSE;

    switch (inst_nbr) {
    case 5 :
        ret = gest_and_or_xor(core, instr, line);
        break;
    case 6 :
        ret = gest_and_or_xor(core, instr, line);
        break;
    case 7 :
        ret = gest_and_or_xor(core, instr, line);
        break;
    case 8 :
        ret = gest_zjmp(core, instr, line);
        break;
    case 9 :
        ret = gest_ldi(core, instr, line);
        break;
    }
    ret = check_args_ter(core, instr, inst_nbr, line);
    return (ret);
}

int check_args(core_t *core, char *instr, int inst_nbr, int line)
{
    int ret = FALSE;

    switch (inst_nbr) {
    case 0 :
        ret = gest_live(core, instr, line);
        break;
    case 1 :
        ret = gest_ld(core, instr, line);
        break;
    case 2 :
        ret = gest_st(core, instr, line);
        break;
    case 3 :
        ret = gest_add_sub(core, instr, line);
        break;
    case 4 :
        ret = gest_add_sub(core, instr, line);
        break;
    }
    ret = check_args_bis(core, instr, inst_nbr, line);
    return (ret);
}
