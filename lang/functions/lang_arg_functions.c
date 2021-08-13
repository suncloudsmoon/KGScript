#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../constants.h"
#include "../err/lang_err.h"
#include "../../functions.h"

char *lang_arg_lens(char *s)
{
    char *output = malloc(MAX_STRING_LENGTH);
    if (is_string(s))
    {
        itoa(strlen(s) - 2, output, 10);
    }
    else
    {
        lang_err(not_string);
    }
    return output;
    free(output);
}

char *lang_arg_addi(char *s)
{
    int i;
    int tmp_output = 0;
    char *output = malloc(MAX_STRING_LENGTH);
    for (i = 0; i < strgnl(s, ',') + 1; i++)
    {
        tmp_output += atoi(strgn(s, ',', i));
    }
    itoa(tmp_output, output, 10);
    return output;
    free(output);
}

char *lang_arg_subi(char *s)
{
    int i;
    int tmp_output = atoi(strgn(s, ',', 0));
    char *output = malloc(MAX_STRING_LENGTH);
    for (i = 0; i < strgnl(s, ','); i++)
    {
        tmp_output -= atoi(strgn(s, ',', i + 1));
    }
    itoa(tmp_output, output, 10);
    return output;
    free(output);
}

char *lang_arg_muli(char *s)
{
    int i;
    int tmp_output = atoi(strgn(s, ',', 0));
    char *output = malloc(MAX_STRING_LENGTH);
    for (i = 0; i < strgnl(s, ','); i++)
    {
        tmp_output *= atoi(strgn(s, ',', i + 1));
    }
    itoa(tmp_output, output, 10);
    return output;
    free(output);
}

char *lang_arg_divi(char *s)
{
    int i;
    int tmp_output = atoi(strgn(s, ',', 0));
    char *output = malloc(MAX_STRING_LENGTH);
    for (i = 0; i < strgnl(s, ','); i++)
    {
        tmp_output /= atoi(strgn(s, ',', i + 1));
    }
    itoa(tmp_output, output, 10);
    return output;
    free(output);
}