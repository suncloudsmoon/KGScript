#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE (1 == 1)
#define FALSE (1 == 0)

#define FUNCTION_COUNT 3
#define MAX_FUNCTION_NAME_LENGTH 247
#define MAX_FUNCTION_ARG_LENGTH 127

#define MAX_STRING_LENGTH 2048

char *strr(char *str, char *output, int x, int y)
{
    int i;
    for (i = x + 1; i < y; i++)
    {
        output[i - (x + 1)] = str[i];
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

void lang_lens(char *s)
{
    char output[MAX_STRING_LENGTH] = "\0";
    if (is_string(s))
    {
        strr(s, output, 0, strlen(s) - 1);
        printf("%ld\n", strlen(output));
    }
}

int main()
{
    int i;
    char function_names[FUNCTION_COUNT][MAX_FUNCTION_NAME_LENGTH] = {
        "prints",
        "printi",
        "lens"
    };
    char input[MAX_STRING_LENGTH];
    char function_name[MAX_FUNCTION_NAME_LENGTH] = "\0";
    char function_arg[MAX_FUNCTION_ARG_LENGTH] = "\0";
    printf("> ");
    scanf("%s", input);
    for (i = 0; i < FUNCTION_COUNT; i++)
    {
        clear_str(function_name);
        strr(input, function_name, -1, strlen(function_names[i]));
        strr(input, function_arg, strlen(function_names[i]), strlen(input) - 1);
        if (strcmp(function_name, function_names[i]) == FALSE)
        {
            if (input[strlen(function_name)] == '(' & input[strlen(function_name) + strlen(function_arg) + 1] == ')')
            {
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
                        lang_lens(function_arg);
                        break;
                }
            }
        }
    }
}
