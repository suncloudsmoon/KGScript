#include <string.h>

#include <lang/err.h>
#include <lang/err/names.h>

char *get_err(err_code err)
{
    return err_names[err];
}