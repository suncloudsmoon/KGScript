#ifndef _BIN_H
# define _BIN_H
#endif

#ifdef _BIN_H
extern void write_bin(char *filename, char *str);
extern void write_elf(char *filename, char *str, bool keep_tmp);
extern void read_bin(char *filename, bool decompile_bool);
extern void decompile_bin(char *filename);
#endif