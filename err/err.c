#include <string.h>

#include "../lang/constants.h"
#include "../lang/err/names.h"
#include "err.h"

char *get_err(err_code err)
{
    return err_names[err];
}