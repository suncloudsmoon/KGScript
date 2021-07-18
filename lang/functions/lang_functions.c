#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../constants.h"
#include "../err/lang_err.h"
#include "../../functions.h"

void lang_prints(char *s)
{
    char output[MAX_STRING_LENGTH] = "\0";
    if (is_string(s))
    {
        strr(s, output, 0, strlen(s) - 1);
        printf("%s\n", output);
    }
    else
    {
        lang_err(not_string);
    }
}

void lang_printi(int i)
{
    printf("%d\n", i);
}

void lang_system(char *s)
{
    char output[MAX_STRING_LENGTH] = "\0";
    if (is_string(s))
    {
        strr(s, output, 0, strlen(s) - 1);
        system(output);
    }
    else
    {
        lang_err(not_string);
    }
}