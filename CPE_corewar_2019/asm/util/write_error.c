/*
** EPITECH PROJECT, 2020
** navy
** File description:
** write on the error output
*/

#include <unistd.h>

int my_strlen(const char *str);

int write_error(const char *str)
{
    write(2, str, my_strlen(str));
    return (84);
}
