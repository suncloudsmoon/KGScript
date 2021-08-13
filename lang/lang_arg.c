#include <stdlib.h>
#include <string.h>

#include "constants.h"
#include "../functions.h"
#include "functions/lang_arg_functions.h"

void lang_arg(int function_code, char *str)
{
    char tmp_str[MAX_STRING_LENGTH] = "\0";
    switch (function_code)
    {
        case 0:
            equstr(str, tmp_str);
            clear_str(str);
            equstr(lang_arg_lens(tmp_str), str);
            break;
        case 1:
            equstr(str, tmp_str);
            clear_str(str);
            equstr(lang_arg_addi(tmp_str), str);
            break;
        case 2:
            equstr(str, tmp_str);
            clear_str(str);
            equstr(lang_arg_subi(tmp_str), str);
            break;
        case 3:
            equstr(str, tmp_str);
            clear_str(str);
            equstr(lang_arg_muli(tmp_str), str);
            break;
        case 4:
            equstr(str, tmp_str);
            clear_str(str);
            equstr(lang_arg_divi(tmp_str), str);
            break;
    }
}