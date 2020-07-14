/*
** EPITECH PROJECT, 2020
** corewar
** File description:
** get the comment
*/

#include <stdlib.h>
#include "asm.h"

static void del_double_quote(header_t *head)
{
    int k = 0;

    for (int i = 0; head->comment[i] != '\0'; i++)
        if (head->comment[i] == '"')
            for (int j = i; head->comment[j + 1] != '\0'; j++)
                head->comment[j] = head->comment[j + 1];
    for (int i = 0; head->comment[i] != '\0'; i++)
        if (head->comment[i] == '\n')
            head->comment[i] = '\0';
}

static int comp_comment(char *str)
{
    int i = 0;

    if (str[0] != '.')
        return (FALSE);
    for (i = 0; str[i] != ' '; i++)
        if (str[i + 1] == '\0')
            return (FALSE);
    if (i != my_strlen(COMMENT_CMD_STRING))
        return (FALSE);
    for (int j = 0; COMMENT_CMD_STRING[j] != '\0'; j++)
        if (str[j] != COMMENT_CMD_STRING[j])
            return (FALSE);
    return (TRUE);
}

static int get_pos_comment(char **str)
{
    int i = 0;

    for (; str[i][0] != '.'; i++)
        if (str[i + 1] == NULL)
            return (-1);
    for (; str[i] != NULL; i++)
        if (comp_comment(str[i]))
            break;
    if (str[i] == NULL)
        return (-1);
    return (i);
}

static int gest_warning(core_t *core, int pos)
{
    my_error(core, pos, STR_ERROR_TOOLONGCOM);
    core->head->comment[0] = '\0';
    return (FALSE);
}

int get_comment(core_t *core)
{
    int pos = get_pos_comment(core->data);
    int k = 0;
    char *comment;

    if (pos < 0) {
        my_error(core, 1, STR_WAR_NOCOMMENT);
        return (TRUE);
    }
    comment = malloc(sizeof(char) * my_strlen(core->data[pos]));
    if (comment == NULL)
        return (TRUE);
    for (int j = 9; core->data[pos][j] != '\0'; j++, k++)
        comment[k] = core->data[pos][j];
    comment[k] = '\0';
    if ((my_strlen(comment) - 2) > COMMENT_LENGTH)
        return (gest_warning(core, pos));
    for (int j = 0; comment[j] != '\0'; j++)
        core->head->comment[j] = comment[j];
    del_double_quote(core->head);
    return (FALSE);
}
