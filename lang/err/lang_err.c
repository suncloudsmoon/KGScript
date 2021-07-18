#include <stdio.h>

#include "../../err/err.h"

void lang_err(err_code err)
{
    fprintf(stderr, "Error: %s\nError Code: %d\n", get_err(err), err);
}