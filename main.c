#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "functions.h"
#include "lang/constants.h"
#include "lang/names.h"
#include "lang/lang.h"
#include "lang/lang_arg.h"
#include "lang/err/lang_err.h"
#include "bin/bin.h"

int main(int argc, char **argv)
{
    int i, j;
    bool tmp_bool = false;
    char str[MAX_STRING_LENGTH] = "\0";
    char function_name[MAX_FUNCTION_NAME_LENGTH] = "\0";
    char function_arg[MAX_FUNCTION_ARG_LENGTH] = "\0";
    char tmp_function_arg[MAX_FUNCTION_ARG_LENGTH] = "\0";
    char function_arg_function_name[MAX_FUNCTION_NAME_LENGTH] = "\0";
    char old_function_arg[MAX_FUNCTION_ARG_LENGTH] = "\0";
    if (argc > 1)
    {
        FILE *fp = fopen(argv[1], "r");
        fread(str, sizeof(str), 1, fp);
        if (argc == 4 && strcmp(argv[2], "write_bin") == false)
        {
            write_bin(argv[3], str);
        }
        else if (argc == 4 && strcmp(argv[2], "read_bin") == false)
        {
            read_bin(argv[3]);
        }
        else if (argc == 2)
        {
            for (i = 0; i < FUNCTION_NAME_COUNT; i++)
            {
                clear_str(function_name);
                strr(str, function_name, -1, strlen(function_names[i]));
                strr(str, function_arg, strlen(function_names[i]), strlen(str) - 1);
                if (strcmp(function_name, function_names[i]) == false)
                {
                    tmp_bool = true;
                    if (str[strlen(function_name)] == '(' && str[strlen(function_name) + strlen(function_arg) + 1] == ')')
                    {
                        for (j = 0; j < FUNCTION_ARG_FUNCTION_NAME_COUNT; j++)
                        {
                            if (strcmp(old_function_arg, "\0") == false)
                            {
                                equstr(function_arg, old_function_arg);
                            }
                            clear_str(function_arg);
                            clear_str(function_arg_function_name);
                            strr(function_arg, function_arg_function_name, -1, strlen(function_arg_function_names[j]));
                            strr(old_function_arg, function_arg, strlen(function_arg_function_names[j]), strlen(old_function_arg) - 1);
                            strr(old_function_arg, function_arg_function_name, -1, strlen(function_arg_function_names[j]));
                            if (strcmp(function_arg_function_name, function_arg_function_names[j]) == false)
                            {
                                if (old_function_arg[strlen(function_arg_function_name)] == '(' && old_function_arg[strlen(function_arg_function_name) + strlen(function_arg) + 1] == ')')
                                {
                                    lang_arg(j, function_arg);
                                }
                            }
                            else
                            {
                                clear_str(function_arg);
                                equstr(old_function_arg, function_arg);
                            }
                        }
                        lang(i, function_arg);
                    }
                }
                else if (i == FUNCTION_NAME_COUNT - 1 && tmp_bool == false)
                {
                    lang_err(function_not_found);
                    break;
                }
            }
        }
        fclose(fp);
    }
}