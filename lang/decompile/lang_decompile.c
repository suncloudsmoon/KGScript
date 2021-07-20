#include <stdio.h>

#include "../../decompile/decompile.h"
#include "../funcgen.h"

void lang_decompile(int function_code, char *str)
{
    printf("%s\n", funcgen(get_func(function_code), str));
}