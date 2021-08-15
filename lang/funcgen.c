#include <stdlib.h>
#include <string.h>

#include <lang/constants.h>

char *funcgen(char *s1, char *s2)
{
    int i;
    int tmp_int = 0;
    int __tmp_int__ = 0;
    char *output = malloc(MAX_STRING_LENGTH);
    for (i = 0; i < strlen(s1); i++)
    {
        output[i] = s1[i];
        tmp_int++;
    }
    output[tmp_int] = '(';
    tmp_int++;
    for (i = 0; i < strlen(s2); i++)
    {
        output[i + tmp_int] = s2[i];
        __tmp_int__++;
    }
    output[tmp_int + __tmp_int__] = ')';
    return output;
    free(output);
}