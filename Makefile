CC=gcc

.PHONY: KGScript

all: KGScript

C_SOURCES= \
	main.c \
	functions.c \
	lang/names.c \
	lang/lang.c \
	lang/lang_arg.c \
	lang/functions/lang_functions.c \
	lang/functions/lang_arg_functions.c \
	lang/err/lang_err.c \
	lang/err/names.c \
	err/err.c \
	bin/bin.c \
	bin/strhex.c

KGScript: $(C_SOURCES)
	$(CC) $(C_SOURCES) -o KGScript
	objcopy --remove-section .comment KGScript
	objcopy --remove-section .eh_frame KGScript