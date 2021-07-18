#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "../functions.h"
#include "strhex.h"
#include "../lang/constants.h"
#include "../lang/names.h"

void write_bin(char *filename, char *str)
{
    FILE *fp = fopen(filename, "wb");
    int i, j;
    int output_length = 0;
    int tmp_int;
    int tmp_index = -1;
    char *ptr;
    char function_name[MAX_FUNCTION_NAME_LENGTH] = "\0";
    char function_arg[MAX_FUNCTION_ARG_LENGTH] = "\0";
    char tmp_function_arg[MAX_FUNCTION_ARG_LENGTH] = "\0";
    char _tmp_str_[MAX_STRING_LENGTH] = "\0";
    char tmp_str[2 * MAX_STRING_LENGTH] = "\0";
    char tmp_hex[2 * MAX_STRING_LENGTH] = "\0";
    char tmp_output[MAX_FILE_LENGTH] = "\0";
    for (i = 0; i < FUNCTION_NAME_COUNT; i++)
    {
        clear_str(function_name);
        strr(str, function_name, -1, strlen(function_names[i]));
        strr(str, function_arg, strlen(function_names[i]), strlen(str) - 1);
        if (strcmp(function_name, function_names[i]) == false)
        {
            if (str[strlen(function_name)] == '(' && str[strlen(function_name) + strlen(function_arg) + 1] == ')')
            {
                itoa(atoi(function_arg), tmp_function_arg, 10);
                if (strcmp(function_arg, tmp_function_arg) == false)
                {
                    itoa(atoi(function_arg), tmp_str, 16);
                    tmp_index += 2;
                    output_length++;
                    tmp_output[0] = 0;
                    output_length++;
                    tmp_output[1] = i + 1;
                    output_length += (int)(((float)(strlen(tmp_str)) / 2) + 0.5);
                    for (j = 0; j < (int)(((float)(strlen(tmp_str)) / 2) + 0.5); j++)
                    {
                        strr(tmp_str, tmp_hex, (2 * j) - 1, 2 * (j + 1));
                        tmp_index++;
                        tmp_int = strtol(tmp_hex, &ptr, 16);
                        tmp_output[tmp_index] = tmp_int;
                    }
                }
                else if (is_string(function_arg))
                {
                    tmp_index += 3;
                    output_length++;
                    tmp_output[0] = 0;
                    output_length++;
                    tmp_output[1] = i + 1;
                    strr(function_arg, _tmp_str_, 0, strlen(function_arg) - 1);
                    equstr(strhex(_tmp_str_), tmp_str);
                    output_length += strlen(tmp_str);
                    for (j = 0; j < strlen(tmp_str); j++)
                    {
                        tmp_output[tmp_index + j] = tmp_str[j];
                    }
                }
            }
        }
    }
    char output[output_length];
    for (i = 0; i < output_length; i++)
    {
        output[i] = tmp_output[i];
    }
    fwrite(output, sizeof(output), 1, fp);
    fclose(fp);
}

void read_bin(char *filename)
{
    char *file_str;
    FILE *fp = fopen(filename, "rb");
    fread(file_str, sizeof(file_str), 1, fp);
    fclose(fp);
}