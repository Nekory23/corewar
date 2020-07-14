/*
** EPITECH PROJECT, 2020
** corewar (asm)
** File description:
** check if the lines are correct
*/

#include <stdlib.h>
#include "asm.h"

static int is_empty_or_a_comment(char *str)
{
    if (str[0] == '#')
        return (TRUE);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
            continue;
        return (FALSE);
    }
    return (TRUE);
}

static char *get_instruction(char *line)
{
    char *temp = malloc(sizeof(char) * (my_strlen(line) + 2));
    int i = 0;

    for (i = 0; line[i] != '\0'; i++) {
        if (line[i] == ' ')
            break;
        temp[i] = line[i];
    }
    temp[i] = '\0';
    return (temp);
}

static int check_line(core_t *core, char *line, int nbr)
{
    char *inst;

    if (is_empty_or_a_comment(line))
        return (FALSE);
    inst = get_instruction(line);
    if (check_instruction(core, inst, nbr))
        return (TRUE);
    free(inst);
    return (FALSE);
}

int check_prog(core_t *core)
{
    for (int i = 0; core->data[i] != NULL; i++)
        if (check_line(core, core->data[i], (i + 1)))
            return (TRUE);
    return (FALSE);
}
