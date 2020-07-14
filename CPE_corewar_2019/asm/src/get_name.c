/*
** EPITECH PROJECT, 2020
** corewar
** File description:
** get name
*/

#include <stdlib.h>
#include "asm.h"

static char *copy_name(char *file, int temp, int size)
{
    char *name = malloc(sizeof(char) * (size + 2));

    if (name == NULL)
        return (NULL);
    for (int i = 0; file[temp] != '\0'; i++, temp++)
        name[i] = file[temp];
    name[size + 1] = '\0';
    return (name);
}

static char *without_path(char *file)
{
    int nbr = 0;
    int temp = 0;
    char *name;

    for (int i = 0; file[i] != '\0'; i++)
        if (file[i] == '/')
            nbr++;
    if (nbr == 0)
        return (file);
    for (int j = 0; j != nbr; temp++)
        if (file[temp] == '/')
            j++;
    for (nbr = temp; file[nbr] != '\0'; nbr++);
    nbr -= temp;
    name = copy_name(file, temp, nbr);
    if (name == NULL)
        return (NULL);
    return (name);
}

char *get_name(char *file)
{
    char *name;
    int i = 0;

    if ((file = without_path(file)) == NULL)
        return (NULL);
    if ((name = malloc(sizeof(char) * (my_strlen(file) + 6))) == NULL)
        return (NULL);
    for (i = 0; file[i] != '\0'; i++)
        if (file[i] == '.')
            break;
        else
            name[i] = file[i];
    name[i] = '.';
    name[i + 1] = 'c';
    name[i + 2] = 'o';
    name[i + 3] = 'r';
    name[i + 4] = '\0';
    return (name);
}
