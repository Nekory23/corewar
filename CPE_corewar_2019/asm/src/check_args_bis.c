/*
** EPITECH PROJECT, 2020
** corewar
** File description:
** check the args of the instructions
*/

#include <unistd.h>
#include "asm.h"

int get_nbr_args(char *str, char sep)
{
    int nbr = 1;

    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == sep)
            nbr++;
    return (nbr);
}

int display_error(core_t *core, int line, int nbr, int max)
{
    if (nbr < max) {
        my_error(core, line, STR_ERROR_FEW);
        write(2, STR_ERROR_FEW2, my_strlen(STR_ERROR_FEW2));
    } else {
        my_error(core, line, STR_ERROR_MANY);
        write(2, STR_ERROR_MANY2, my_strlen(STR_ERROR_MANY2));
    }
    return (TRUE);
}
