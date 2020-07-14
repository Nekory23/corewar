/*
** EPITECH PROJECT, 2020
** corewar
** File description:
** corewar main
*/

#include "corewar.h"

int main(int ac, char **av)
{
    if (my_strcmp(av[1], "-h"))
        return (display_help());
    return (SUCCESS);
}
