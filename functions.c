#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "functions.h"
#include "lang/constants.h"
#include "lang/operators/lang_operators.h"

char *itoa(int value, char *str, int base)
{
    char *output;
    char *ptr;
    char *low;
    if (base < 2 || base > 36)
    {
        *str = '\0';
        return str;
    }
    output = ptr = str;
    if (value < 0 && base == 10)
    {
        *ptr++ = '-';
    }
    low = ptr;
    do
    {
        *ptr++ = "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrstuvwxyz"[35 + value % base];
        value /= base;
    } while (value);
    *ptr-- = '\0';
    while (low < ptr)
    {
        char tmp = *low;
        *low++ = *ptr;
        *ptr-- = tmp;
    }
    return output;
}

char *strg(char *str, char c)
{
    int i = 0;
    char *output = malloc(sizeof(char *));
    while (str[i])
    {
        if (str[i] == c && str[i - 1] != c)
        {
            return output;
            break;
        }
        else
        {
            output[i] = str[i];
        }
        i++;
    }
}

char *strga(char *str, char c)
{
    int i = 0, j = 0;
    bool b = false;
    char *output = malloc(sizeof(char *));
    while (str[i])
    {
        if (str[i] == c && str[i - 1] != c && b == false)
        {
            b = true;
        }
        else if (b)
        {
            output[j] = str[i];
            j++;
        }
        i++;
    }
    return output;
}

char *strgn(char *str, char c, int n)
{
    int i = 0, j = 0, k = 0;
    char *output = malloc(MAX_STRING_LENGTH);
    while (str[i])
    {
        if (str[i] == c && str[i - 1] != c)
        {
            k++;
        }
        else if (n == k)
        {
            output[j] = str[i];
            j++;
        }
        i++;
    }
    return output;
    free(output);
}

int strgnl(char *str, char c)
{
    int i = 0;
    int output = 0;
    while (str[i])
    {
        if (str[i] == c && str[i - 1] != c)
        {
            output++;
        }
        i++;
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
    if (str[0] == '"' && str[strlen(str) - 1] == '"' && strlen(str) > 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int is_sint(char *str)
{
    int i = 0;
    while (str[i])
    {
        if (is_soperator(str))
        {
            return false;
            break;
        }
        else if (str[i] >= '0' && str[i] <= '9')
        {
            return true;
        }
        else
        {
            return false;
            break;
        }
    }
}

int is_coperator(char c)
{
    int i = 0;
    while (operators[i])
    {
        if (operators[i] == c)
        {
            return true;
        }
        i++;
    }
}

int is_soperator(char *str)
{
    int i = 0;
    bool b = false;
    while (str[i])
    {
        if (is_coperator(str[i]))
        {
            b = true;
        }
        if ((str[i] >= '0' && str[i] <= '9' && b) || (is_coperator(str[i])))
        {
            return true;
        }
        i++;
    }
}