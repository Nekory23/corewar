/*
** EPITECH PROJECT, 2020
** corewar
** File description:
** display the help (corewar)
*/

#include "corewar.h"

int display_help(void)
{
    my_putstr("USAGE\n./corewar [-dump nbr_cycle] [[-n prog_number]");
    my_putstr(" [-a load_address] prog_name] ...\n");
    my_putstr("DESCRPTION\n-dump nbr_cycle dumps the memory after ");
    my_putstr("the nbr_cycle execution (if the round isn't already over)");
    my_putstr(" with the following format: 32 bytes/line in hexadecimal ");
    my_putstr("(A0BCDEFE1DD3...)\n-n prog_number sets the next program's ");
    my_putstr("number. By default, the first free number in the parameter ");
    my_putstr("order\n-a load_address sets the next program's loading address");
    my_putstr(". When no address is specified, optimize the addresses so that");
    my_putstr(" the processes are as far away from each other as possible. ");
    my_putstr("The addresses are MEM_SIZE modulo.\n");
    return (SUCCESS);
}
