/*
** EPITECH PROJECT, 2020
** corewar
** File description:
** get data
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include "asm.h"

static int compare_with_label_chars(char c)
{
    for (int i = 0; LABEL_CHARS[i] != '\0'; i++)
        if (c == LABEL_CHARS[i])
            return (TRUE);
    switch (c) {
    case COMMENT_CHAR :
        return (TRUE);
    case LABEL_CHAR :
        return (TRUE);
    case DIRECT_CHAR :
        return (TRUE);
    case SEPARATOR_CHAR :
        return (TRUE);
    case '\n' :
        return (TRUE);
    case ' ' :
        return (TRUE);
    }
    return (FALSE);
}

static int check_all_lines(char **split, core_t *core)
{
    for (int i = 0; split[i] != NULL; i++) {
        for (int j = 0; split[i][j] != '\0'; j++) {
            if (split[i][0] == '#' || split[i][0] == '.')
                break;
            if (compare_with_label_chars(split[i][j]))
                continue;
            else {
                my_error(core, i, STR_ERROR_CHAR);
                return (TRUE);
            }
        }
    }
    return (FALSE);
}

static char **malloc_str(char *file)
{
    int fd = open(file, O_RDONLY);
    char buff;
    char *stock = malloc(sizeof(char) * 2);
    int j = 0;
    char **str;

    if (fd == -1 || stock == NULL)
        return (NULL);
    for (int i = 0; read(fd, &buff, 1) != 0; i++) {
        stock[i] = buff;
        stock[i + 1] = '\0';
        stock = realloc(stock, sizeof(char) * (my_strlen(stock) + 2));
    }
    for (int i = 0; stock[i] != '\0'; i++)
        if (stock[i] == '\n')
            j++;
    str = malloc(sizeof(char *) * (j + 2));
    str[j + 1] = NULL;
    free(stock);
    close(fd);
    return (str);
}

char **get_data(char *file, core_t *core)
{
    char **str = malloc_str(file);
    size_t size = 10;
    char *buff = malloc(sizeof(char) * size);
    FILE *src = fopen(file, "r");
    int i = 0;

    if (str == NULL || buff == NULL)
        return (NULL);
    for (; getline(&buff, &size, src) != -1; i++) {
        str[i] = malloc(sizeof(char) * (my_strlen(buff) + 1));
        for (int j = 0; buff[j] != '\0'; j++)
            str[i][j] = buff[j];
        str[i][my_strlen(buff)] = '\0';
    }
    str[i] = NULL;
    if (i == 0 || check_all_lines(str, core))
        return (NULL);
    return (str);
}
