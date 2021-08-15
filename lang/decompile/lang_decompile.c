#include <stdio.h>

#include <lang/funcgen.h>
#include <lang/decompile.h>

void lang_decompile(int function_code, char *str)
{
    printf("%s\n", funcgen(get_func(function_code), str));
}