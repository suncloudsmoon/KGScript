#include <string.h>
#include "constants.h"

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
