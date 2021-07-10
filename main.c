#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "constants.h"
#include "functions.h"
#include "lang/lang.h"
#include "lang/lang_arg.h"

int main()
{
    int i, j;
    char function_names[FUNCTION_NAME_COUNT][MAX_FUNCTION_NAME_LENGTH] = {
        "prints",
        "printi",
        "system"
    };
    char function_arg_function_names[FUNCTION_ARG_FUNCTION_NAME_COUNT][MAX_FUNCTION_NAME_LENGTH] = {
        "lens"
    };
    char input[MAX_STRING_LENGTH];
    char function_name[MAX_FUNCTION_NAME_LENGTH] = "\0";
    char function_arg[MAX_FUNCTION_ARG_LENGTH] = "\0";
    char tmp_function_arg[MAX_FUNCTION_ARG_LENGTH] = "\0";
    char function_arg_function_name[MAX_FUNCTION_NAME_LENGTH] = "\0";
    char old_function_arg[MAX_FUNCTION_ARG_LENGTH] = "\0";
    printf("> ");
    scanf("%[^\n]", input);
    for (i = 0; i < FUNCTION_NAME_COUNT; i++)
    {
        clear_str(function_name);
        strr(input, function_name, -1, strlen(function_names[i]));
        strr(input, function_arg, strlen(function_names[i]), strlen(input) - 1);
        if (strcmp(function_name, function_names[i]) == FALSE)
        {
            if (input[strlen(function_name)] == '(' & input[strlen(function_name) + strlen(function_arg) + 1] == ')')
            {
                for (j = 0; j < FUNCTION_ARG_FUNCTION_NAME_COUNT; j++)
                {
                    if (strcmp(old_function_arg, "\0") == FALSE)
                    {
                        equstr(function_arg, old_function_arg);
                    }
                    clear_str(function_arg);
                    clear_str(function_arg_function_name);
                    strr(function_arg, function_arg_function_name, -1, strlen(function_arg_function_names[j]));
                    strr(old_function_arg, function_arg, strlen(function_arg_function_names[j]), strlen(old_function_arg) - 1);
                    strr(old_function_arg, function_arg_function_name, -1, strlen(function_arg_function_names[j]));
                    if (strcmp(function_arg_function_name, function_arg_function_names[j]) == FALSE)
                    {
                        if (old_function_arg[strlen(function_arg_function_name)] == '(' & old_function_arg[strlen(function_arg_function_name) + strlen(function_arg) + 1] == ')')
                        {
                            switch (j)
                            {
                                case 0:
                                    equstr(function_arg, tmp_function_arg);
                                    clear_str(function_arg);
                                    equstr(lang_arg_lens(tmp_function_arg), function_arg);
                                    break;
                            }
                        }
                    }
                    else
                    {
                        clear_str(function_arg);
                        equstr(old_function_arg, function_arg);
                    }
                }
                switch (i)
                {
                    case 0:
                        lang_prints(function_arg);
                        break;
                    case 1:
                        if (is_sint(function_arg))
                        {
                            lang_printi(atoi(function_arg));
                        }
                        break;
                    case 2:
                        lang_system(function_arg);
                        break;
                }
            }
        }
    }
}
