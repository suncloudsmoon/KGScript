#ifndef _FUNCTIONS_H
# define _FUNCTIONS_H
#endif

#ifdef _FUNCTIONS_H
extern char *itoa(int value, char *str, int base);
extern char *strg(char *str, char c);
extern char *strga(char *str, char c);
extern char *strgn(char *str, char c, int n);
extern int strgnl(char *str, char c);
extern char *strr(char *str, char *output, int x, int y);
extern char *equstr(char *str, char *output);
extern void clear_str(char *str);
extern int is_string(char *str);
extern int is_sint(char *str);
extern int is_soperator(char *str);
#endif