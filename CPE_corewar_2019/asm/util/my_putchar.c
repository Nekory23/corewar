/*
** EPITECH PROJECT, 2019
** CPool_Day03_2019
** File description:
** my_putchar
*/

#include <unistd.h>

void my_putchar_error(char c)
{
    write(2, &c, 1);
}

void my_putchar(char c)
{
    write(1, &c, 1);
}
