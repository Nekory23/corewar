/*
** EPITECH PROJECT, 2020
** corewar (asm)
** File description:
** gest_zjmp
*/

#include <stdlib.h>
#include "asm.h"

static char *get_the_arg(char *instr, char *str)
{
    int len = my_strlen(str);
    char *arg = malloc(sizeof(char) * (len + 2));

    for (int i = len + 1, j = 0; str[i] != '\0'; i++, j++)
        arg[j] = str[i];
    return (arg);
}

int gest_zjmp(core_t *core, char *instr, int line)
{
    int nbr = get_nbr_args(core->data[line - 1], ',');
    char *arg;

    if (nbr != 1)
        return (display_error(core, line, nbr, 1));
    arg = get_the_arg(instr, core->data[line - 1]);
    free(arg);
    return (FALSE);
}
