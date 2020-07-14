/*
** EPITECH PROJECT, 2020
** corewar (asm)
** File description:
** check if the instruction exists
*/

#include <stdlib.h>
#include "asm.h"

static char **fill_inst(char **instr)
{
    instr[0] = "live\0";
    instr[1] = "ld\0";
    instr[2] = "st\0";
    instr[3] = "add\0";
    instr[4] = "sub\0";
    instr[5] = "and\0";
    instr[6] = "or\0";
    instr[7] = "xor\0";
    instr[8] = "zjmp\0";
    instr[9] = "ldi\0";
    instr[10] = "sti\0";
    instr[11] = "fork\0";
    instr[12] = "lld\0";
    instr[13] = "lldi\0";
    instr[14] = "lfork\0";
    instr[15] = "aff\0";
    instr[16] = NULL;
    return (instr);
}

static int name_or_comment(char *instr)
{
    if (my_strcmp(NAME_CMD_STRING, instr))
        return (TRUE);
    if (my_strcmp(COMMENT_CMD_STRING, instr))
        return (TRUE);
    return (FALSE);
}

static int is_label(char *instr)
{
    int len = my_strlen(instr);

    if (instr[len - 1] == ':' || instr[len - 2] == ':')
        return (TRUE);
    return (FALSE);
}

int check_instruction(core_t *core, char *instr, int nbr)
{
    char **instructions = malloc(sizeof(char *) * 18);

    instructions = fill_inst(instructions);
    if (name_or_comment(instr))
        return (FALSE);
    if (is_label(instr))
        return (FALSE);
    for (int i = 0; instructions[i] != NULL; i++)
        if (my_strcmp(instr, instructions[i])) {
            free(instructions);
            return (check_args(core, instr, i, nbr));
        }
    free(instructions);
    my_error(core, nbr, STR_ERROR_INST);
    return (TRUE);
}
