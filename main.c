#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE (1 == 1)
#define FALSE (1 == 0)

#define FUNCTION_NAME_COUNT 2
#define FUNCTION_ARG_FUNCTION_NAME_COUNT 1
#define MAX_FUNCTION_NAME_LENGTH 247
#define MAX_FUNCTION_ARG_LENGTH 127

#define MAX_STRING_LENGTH 2048

char *itoa(int value, char *str, int base)
{
    char *output;
    char *ptr;
    char *low;
    if (base < 2 | base > 36)
    {
        *str = '\0';
        return str;
    }
    output = ptr = str;
    if (value < 0 & base == 10)
    {
        *ptr++ = '-';
    }
    low = ptr;
    do
    {
        *ptr++ = "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrstuvwxyz"[35 + value % base];
        value /= base;
    }
    while (value);
    *ptr-- = '\0';
    while (low < ptr)
    {
        char tmp = *low;
        *low++ = *ptr;
        *ptr-- = tmp;
    }
    return output;
}

char *strr(char *str, char *output, int x, int y)
{
    int i;
    for (i = x + 1; i < y; i++)
    {
        output[i - (x + 1)] = str[i];
    }
    return output;
}

char *equstr(char *str, char *output)
{
    int i = 0;
    while (str[i])
    {
        output[i] = str[i];
        i++;
    }
    return output;
}

void clear_str(char *str)
{
    int i = 0;
    while (str[i])
    {
        str[i] = '\0';
        i++;
    }
}

int is_string(char *str)
{
    if (str[0] == '"' & str[strlen(str) - 1] == '"')
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

int is_sint(char *str)
{
    int i = 0;
    while (str[i])
    {
        if (str[i] >= '0' & str[i] <= '9')
        {
            return TRUE;
        }
        else
        {
            return FALSE;
            break;
        }
    }
}

void lang_prints(char *s)
{
    char output[MAX_STRING_LENGTH] = "\0";
    if (is_string(s))
    {
        strr(s, output, 0, strlen(s) - 1);
        printf("%s\n", output);
    }
}

void lang_printi(int i)
{
    printf("%d\n", i);
}

char *lang_arg_lens(char *s)
{
    char *output = malloc(MAX_STRING_LENGTH);
    if (is_string(s))
    {
        itoa(strlen(s) - 2, output, 10);
        return output;
    }
}

int main()
{
    int i, j;
    char function_names[FUNCTION_NAME_COUNT][MAX_FUNCTION_NAME_LENGTH] = {
        "prints",
        "printi"
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
    scanf("%s", input);
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
                                    if (is_string(tmp_function_arg))
                                    {
                                        equstr(lang_arg_lens(tmp_function_arg), function_arg);
                                    }
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
                }
            }
        }
    }
}
