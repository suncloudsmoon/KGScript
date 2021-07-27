#ifndef _LANG_FUNCTIONS_H
# define _LANG_FUNCTIONS_H
#endif

#ifdef _LANG_FUNCTIONS_H
# include "constants.h"
extern char function_names[FUNCTION_NAME_COUNT][MAX_FUNCTION_NAME_LENGTH];
extern char function_arg_function_names[FUNCTION_ARG_FUNCTION_NAME_COUNT][MAX_FUNCTION_NAME_LENGTH];
extern char cfunctions[FUNCTION_NAME_COUNT + 2][MAX_STRING_LENGTH / (FUNCTION_NAME_COUNT + 2)];
#endif