#include "constants.h"

char function_names[FUNCTION_NAME_COUNT][MAX_FUNCTION_NAME_LENGTH] = {
    "prints",
    "printi",
    "system"
};
char function_arg_function_names[FUNCTION_ARG_FUNCTION_NAME_COUNT][MAX_FUNCTION_NAME_LENGTH] = {
    "lens"
};

char cfunctions[FUNCTION_NAME_COUNT + 2][MAX_STRING_LENGTH / (FUNCTION_NAME_COUNT + 2)] = {
    "#include <stdio.h>",
    "void prints(char *s) { puts(s); }",
    "void printi(int i) { printf(\"%d\\n\", i); }",
    "void system(char *s) { system(s); }"
};