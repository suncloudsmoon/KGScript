CC=gcc

.PHONY: KGScript

all: KGScript

C_SOURCES= \
	main.c \
	functions.c \
	lang/lang.c \
	lang/lang_arg.c

KGScript: $(C_SOURCES)
	$(CC) $(C_SOURCES) -o KGScript
	objcopy --remove-section .comment KGScript
	objcopy --remove-section .eh_frame KGScript
