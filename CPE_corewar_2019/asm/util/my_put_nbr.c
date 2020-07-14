/*
** EPITECH PROJECT, 2019
** my_put_nbr.c
** File description:
** put_nbr
*/

#include "asm.h"

int my_put_nbr_error(int nb)
{
    if (nb < 0) {
        nb = -nb;
        write_error("-");
    }
    if (nb >= 0 && nb <= 9)
        my_putchar_error(48 + nb);
    else {
        my_put_nbr_error(nb / 10);
        my_put_nbr_error(nb % 10);
    }
    return (0);
}

int my_put_nbr(int nb)
{
    if (nb < 0) {
        nb = -nb;
        my_putchar('-');
    }
    if (nb >= 0 && nb <= 9)
        my_putchar(48 + nb);
    else {
        my_put_nbr(nb / 10);
        my_put_nbr(nb % 10);
    }
    return (0);
}
