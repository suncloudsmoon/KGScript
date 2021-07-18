#ifndef _ERR_ERR_H
# define _ERR_ERR_H
#endif

#ifdef _ERR_ERR_H
typedef enum {
    function_not_found = 0,
    not_string = 1
} err_code;

extern char *get_err(err_code err);
#endif