/*
** EPITECH PROJECT, 2020
** corewar
** File description:
** get_champ
*/

#include <stdlib.h>
#include "asm.h"

static void del_double_quote(header_t *head)
{
    int k = 0;

    for (int i = 0; head->prog_name[i] != '\0'; i++)
        if (head->prog_name[i] == '"')
            for (int j = i; head->prog_name[j + 1] != '\0'; j++)
                head->prog_name[j] = head->prog_name[j + 1];
    for (int i = 0; head->prog_name[i] != '\0'; i++)
        if (head->prog_name[i] == '\n')
            head->prog_name[i] = '\0';
}

static int display_errors(core_t *core, int i)
{
    if (i == -1)
        my_error(core, 1, STR_ERROR_INST);
    else if (i == -2)
        my_error(core, 1, STR_ERROR_NONAME);
    else
        my_error(core, i, STR_ERROR_NAME);
    return (TRUE);
}

static int my_spe_cmp(char *str)
{
    int i = 0;

    if (str[0] != '.')
        return (FALSE);
    for (i = 0; str[i] != ' '; i++)
        if (str[i + 1] == '\0')
            return (FALSE);
    if (i != my_strlen(NAME_CMD_STRING))
        return (FALSE);
    for (int j = 0; NAME_CMD_STRING[j] != '\0'; j++)
        if (str[j] != NAME_CMD_STRING[j])
            return (FALSE);
    return (TRUE);
}

static int check_pos_name(char **str)
{
    int i = 0;

    for (; str[i][0] != '.'; i++)
        if (str[i + 1] == NULL)
            return (-1);
    for (; str[i] != NULL; i++)
        if (my_spe_cmp(str[i]))
            break;
    if (str[i] == NULL)
        return (-2);
    return (i);
}

int get_champ(core_t *core)
{
    int i = check_pos_name(core->data);
    int k = 0;
    char *name;

    if (i < 0)
        return (display_errors(core, i));
    name = malloc(sizeof(char) * my_strlen(core->data[i]));
    if (name == NULL)
        return (TRUE);
    for (int j = 6; core->data[i][j] != '\0'; j++, k++)
        name[k] = core->data[i][j];
    name[k] = '\0';
    k = 0;
    if ((my_strlen(name) - 2) > PROG_NAME_LENGTH)
        return (display_errors(core, -3));
    for (int j = 0; name[j] != '\0'; j++, k++)
        core->head->prog_name[j] = name[j];
    core->head->prog_name[k] = '\0';
    del_double_quote(core->head);
    free(name);
    return (FALSE);
}
