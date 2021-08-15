#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <functions.h>

#include <lang/lang_operator.h>
#include <lang/lang_functions.h>

void lang(int function_code, char *str)
{
    switch (function_code)
    {
        case 0:
            lang_prints(str);
            break;
        case 1:
            if (is_sint(str))
            {
                lang_printi(atoi(str));
            }
            if (is_soperator(str))
            {
                lang_printi(lang_operator(str));
            }
            break;
        case 2:
            lang_system(str);
            break;
    }
}