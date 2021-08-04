#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include <string.h>

#include "../functions.h"
#include "../decompile/decompile.h"
#include "../lang/constants.h"
#include "../lang/names.h"
#include "../lang/lang.h"
#include "../lang/decompile/lang_decompile.h"
#include "../lang/funcgen.h"
#include "ltoc.h"
#include "strhex.h"

int __function_code__;

char __function_arg__[MAX_FUNCTION_ARG_LENGTH] = "\0";

void write_bin(char *filename, char *str)
{
    FILE *fp = fopen(filename, "wb");
    int i, j;
    int output_length = 0;
    int tmp_int;
    int tmp_index = -1;
    char function_name[MAX_FUNCTION_NAME_LENGTH] = "\0";
    char function_arg[MAX_FUNCTION_ARG_LENGTH] = "\0";
    char tmp_function_arg[MAX_FUNCTION_ARG_LENGTH] = "\0";
    char tmp_str[2 * MAX_FILE_LENGTH] = "\0";
    char _tmp_str_[MAX_FILE_LENGTH] = "\0";
    char tmp_hex[2 * MAX_FILE_LENGTH] = "\0";
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
                    tmp_index += 3;
                    output_length++;
                    tmp_output[0] = ((i + 1) / 256) + 1;
                    output_length++;
                    tmp_output[1] = i + 1;
                    output_length++;
                    tmp_output[2] = 1;
                    output_length++;
                    tmp_output[3] = (int)(((float)(strlen(tmp_str)) / 2) + 0.5);
                    output_length += (int)(((float)(strlen(tmp_str)) / 2) + 0.5);
                    for (j = 0; j < (int)(((float)(strlen(tmp_str)) / 2) + 0.5); j++)
                    {
                        strr(tmp_str, tmp_hex, (2 * j) - 1, 2 * (j + 1));
                        tmp_index++;
                        tmp_int = strtol(tmp_hex, NULL, 16);
                        tmp_output[tmp_index] = tmp_int;
                    }
                }
                else if (is_string(function_arg))
                {
                    tmp_index += 3;
                    output_length++;
                    tmp_output[0] = ((i + 1) / 256) + 1;
                    output_length++;
                    tmp_output[1] = i + 1;
                    output_length++;
                    tmp_output[2] = 2;
                    output_length++;
                    tmp_output[3] = strlen(tmp_str);
                    strr(function_arg, _tmp_str_, 0, strlen(function_arg) - 1);
                    equstr(strhex(_tmp_str_), tmp_str);
                    output_length += strlen(tmp_str);
                    for (j = 0; j < strlen(tmp_str); j++)
                    {
                        tmp_index++;
                        tmp_output[tmp_index] = tmp_str[j];
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

void write_elf(char *filename, char *str, bool keep_tmp)
{
    char tmp_str[MAX_FILE_LENGTH] = "\0";
    char tmp_output[MAX_FILE_LENGTH] = "\0";
    sprintf(tmp_output, "%s", ltoc(str));
    char output[strlen(tmp_output)];
    equstr(tmp_output, output);
    FILE *fp = fopen("tmp.c", "wb");
    fwrite(output, sizeof(output), 1, fp);
    fclose(fp);
    sprintf(tmp_str, "gcc tmp.c -o %s", filename);
    system(tmp_str);
    if (keep_tmp == false)
    {
        remove("tmp.c");
    }
}

void read_bin(char *filename, bool decompile_bool)
{
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL)
    {
        perror(filename);
        exit(EXIT_FAILURE);
    }
    int i;
    int function_code;
    char function_arg[MAX_FUNCTION_ARG_LENGTH] = "\0";
    char tmp_function_arg[MAX_FUNCTION_ARG_LENGTH] = "\0";
    char tmp_hex[MAX_FILE_LENGTH] = "\0";
    char hex_array[MAX_FILE_LENGTH][3];
    char file_str[MAX_FILE_LENGTH] = "\0";
    fread(file_str, sizeof(file_str), 1, fp);
    fclose(fp);
    for (i = 0; i < strlen(file_str); i++)
    {
        sprintf(tmp_hex, "%02x", file_str[i]);
        hex_array[i][0] = tmp_hex[0];
        hex_array[i][1] = tmp_hex[1];
    }
    for (i = 0; i < strtol(hex_array[2], NULL, 16); i++)
    {
        tmp_function_arg[(2 * i) - i] = hex_array[i + 3][0];
        tmp_function_arg[(2 * i) - i + 1] = hex_array[i + 3][1];
    }
    switch (strtol(hex_array[1], NULL, 16))
    {
        case 1:
            itoa(strtol(tmp_function_arg, NULL, 16), function_arg, 10);
            break;
        case 2:
            break;
    }
    function_code = strtol(hex_array[0], NULL, 16) - 1;
    if (decompile_bool == false)
    {
        lang(function_code, function_arg);
    }
    else
    {
        __function_code__ = function_code;
        equstr(function_arg, __function_arg__);
    }
}

void decompile_bin(char *filename)
{
    read_bin(filename, true);
    lang_decompile(__function_code__, __function_arg__);
}