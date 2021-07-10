/*
 * Copyright (c) 2021, the KGScript Authors.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

/*
 * interpreter.c
 *
 *  Created on: Jul 9, 2021
 *      Author: suncloudsmoon
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "interpreter.h"

// Global Variables Here
//const char function_names[FUNCTION_NAME_COUNT][MAX_FUNCTION_NAME_LENGTH] =
//{ "prints", "printi", "system" };

// Static Functions Here
static char* string_cpyvalueof(char *hello, interpreter_t *i);

// Very Simple String library //
static char* string_cpyvalueof(char *hello, interpreter_t *i)
{
	// Safety
	if (hello == NULL)
		throw_exception(NULL_POINTER_EXCEPTION, i);

	int length = strlen(hello);
	char *new = (char*) calloc(length, sizeof(char));
	strncpy(new, hello, length);

	return new;
}

// Very Simple Exception System //
void throw_exception(runtime_exception e, interpreter_t *i)
{
	switch (e)
	{
	case NULL_POINTER_EXCEPTION:
		printf("At line %d: A Null Pointer Exception occurred!\n", i->lineNum);
		break;
	default:
		break;
	}
}

interpreter_t* interpreter_init()
{
	interpreter_t *vm = (interpreter_t*) calloc(1, sizeof(interpreter_t));
	// Not sure if "vm->printi_function_name = "hello"" by itself will create a memory leak
	vm->lineNum = 0;
	vm->function_names = (char**) calloc(FUNCTION_NAME_COUNT, sizeof(char*));

	vm->function_names[0] = string_cpyvalueof("prints", vm);
	vm->function_names[1] = string_cpyvalueof("printi", vm);
	vm->function_names[2] = string_cpyvalueof("system", vm);

	return vm;
}

void free_interpreter(interpreter_t *interpreter)
{
	for (int i = 0; i < FUNCTION_NAME_COUNT; i++)
		free(interpreter->function_names[i]);

	free(interpreter); // I don't know if this is necessary; I need to research about this!
}

void start_interpreter(interpreter_t *interpreter)
{
	int i, j;

	char function_arg_function_names[FUNCTION_ARG_FUNCTION_NAME_COUNT][MAX_FUNCTION_NAME_LENGTH] =
	{ "lens" };

	// For debugging, a constant value is set to input
	char input[MAX_STRING_LENGTH];
	char function_name[MAX_FUNCTION_NAME_LENGTH] = "\0";
	char function_arg[MAX_FUNCTION_ARG_LENGTH] = "\0";
	char tmp_function_arg[MAX_FUNCTION_ARG_LENGTH] = "\0";
	char function_arg_function_name[MAX_FUNCTION_NAME_LENGTH] = "\0";
	char old_function_arg[MAX_FUNCTION_ARG_LENGTH] = "\0";

	printf("> ");
	// For debugging, it is commented out
	scanf("%[^\n]", input);

	for (i = 0; i < FUNCTION_NAME_COUNT; i++)
	{
		clear_str(function_name);
		strr(input, function_name, -1, strlen(interpreter->function_names[i]));
		strr(input, function_arg, strlen(interpreter->function_names[i]),
				strlen(input) - 1);
		if (strcmp(function_name, interpreter->function_names[i]) == FALSE)
		{
			if (input[strlen(function_name)] == '('
					& input[strlen(function_name) + strlen(function_arg) + 1]
							== ')')
			{
				for (j = 0; j < FUNCTION_ARG_FUNCTION_NAME_COUNT; j++)
				{
					if (strcmp(old_function_arg, "\0") == FALSE)
					{
						equstr(function_arg, old_function_arg);
					}
					clear_str(function_arg);
					clear_str(function_arg_function_name);
					strr(function_arg, function_arg_function_name, -1,
							strlen(function_arg_function_names[j]));
					strr(old_function_arg, function_arg,
							strlen(function_arg_function_names[j]),
							strlen(old_function_arg) - 1);
					strr(old_function_arg, function_arg_function_name, -1,
							strlen(function_arg_function_names[j]));
					if (strcmp(function_arg_function_name,
							function_arg_function_names[j]) == FALSE)
					{
						if (old_function_arg[strlen(function_arg_function_name)]
								== '('
								& old_function_arg[strlen(
										function_arg_function_name)
										+ strlen(function_arg) + 1] == ')')
						{
							switch (j)
							{
							case 0:
								equstr(function_arg, tmp_function_arg);
								clear_str(function_arg);
								equstr(lang_arg_lens(tmp_function_arg),
										function_arg);
								break;
							}
						}
					}
					else
					{
						clear_str(function_arg);
						equstr(old_function_arg, function_arg);
					}
				}
				switch (i)
				{
				case 0:
					lang_prints(function_arg);
					break;
				case 1:
					if (is_sint(function_arg))
					{
						// Strtol is better than atoi because it returns a long
						lang_printi(strtol(function_arg, NULL, 10));
					}
					break;
				case 2:
					lang_system(function_arg);
					break;
				}
			}
		}
	}

	// Free resources

}

char* itoa(int value, char *str, int base)
{
	char *output;
	char *ptr;
	char *low;
	if (base < 2 | base > 36)
	{
		*str = '\0';
		return str;
	}
	output = ptr = str;
	if (value < 0 & base == 10)
	{
		*ptr++ = '-';
	}
	low = ptr;
	do
	{
		*ptr++ =
				"zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrstuvwxyz"[35
						+ value % base];
		value /= base;
	} while (value);
	*ptr-- = '\0';
	while (low < ptr)
	{
		char tmp = *low;
		*low++ = *ptr;
		*ptr-- = tmp;
	}
	return output;
}

char* strr(char *str, char *output, int x, int y)
{
	int i;
	for (i = x + 1; i < y; i++)
	{
		output[i - (x + 1)] = str[i];
	}
	return output;
}

char* equstr(char *str, char *output)
{
	int i = 0;
	while (str[i])
	{
		output[i] = str[i];
		i++;
	}
	return output;
}

void clear_str(char *str)
{
	int i = 0;
	while (str[i])
	{
		str[i] = '\0';
		i++;
	}
}

int is_string(char *str)
{
	if (str[0] == '"' & str[strlen(str) - 1] == '"')
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

int is_sint(char *str)
{
	int i = 0;
	while (str[i])
	{
		if (str[i] >= '0' & str[i] <= '9')
		{
			return TRUE;
		}
		else
		{
			return FALSE;
			break;
		}
	}
}

void lang_prints(char *s)
{
	char output[MAX_STRING_LENGTH] = "\0";
	if (is_string(s))
	{
		strr(s, output, 0, strlen(s) - 1);
		printf("%s\n", output);
	}
}

void lang_printi(int i)
{
	printf("%d\n", i);
}

void lang_system(char *s)
{
	char output[MAX_STRING_LENGTH] = "\0";
	if (is_string(s))
	{
		strr(s, output, 0, strlen(s) - 1);
		system(output);
	}
}

char* lang_arg_lens(char *s)
{
	char *output = malloc(MAX_STRING_LENGTH);
	if (is_string(s))
	{
		itoa(strlen(s) - 2, output, 10);
	}
	return output;
}
