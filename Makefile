CC=gcc

.PHONY: KGScript

all: KGScript

KGScript: main.c
	$(CC) main.c -o KGScript
	objcopy --remove-section .comment KGScript
	objcopy --remove-section .eh_frame KGScript
