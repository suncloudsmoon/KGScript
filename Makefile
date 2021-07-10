CC=gcc

.PHONY: KGScript

all: KGScript

KGScript: main.c interpreter.c
	$(CC) main.c interpreter.c -o KGScript
	objcopy --remove-section .comment KGScript
	objcopy --remove-section .eh_frame KGScript
