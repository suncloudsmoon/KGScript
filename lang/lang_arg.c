#include <stdlib.h>
#include <string.h>

#include "../constants.h"
#include "../functions.h"

char *lang_arg_lens(char *s)
{
    char *output = malloc(MAX_STRING_LENGTH);
    if (is_string(s))
    {
        itoa(strlen(s) - 2, output, 10);
    }
    return output;
}
