#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <functions.h>

#include <lang/constants.h>
#include <lang/lang_err.h>

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

void lang_printi(int value)
{
    printf("%d\n", value);
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