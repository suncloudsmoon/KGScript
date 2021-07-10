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
 * interpreter.h
 *
 *  Created on: Jul 9, 2021
 *      Author: suncloudsmoon
 */

#ifndef SRC_INTERPRETER_H_
#define SRC_INTERPRETER_H_

// All the defines in one file!
#define TRUE (1 == 1)
#define FALSE (1 == 0)

#define FUNCTION_NAME_COUNT 3
#define FUNCTION_ARG_FUNCTION_NAME_COUNT 1
#define MAX_FUNCTION_NAME_LENGTH 247
#define MAX_FUNCTION_ARG_LENGTH 127

#define MAX_STRING_LENGTH 2048

/*
 * Defines what an exception is.
 */
typedef enum
{
	NULL_POINTER_EXCEPTION = -1
} runtime_exception;

/*
 * Stores all the variables that will be used throughout the process of the interpreter, like line number, etc.
 */
typedef struct
{
	// Functions name that could be changed at runtime if the user pleases, like "#define" in C, making the language more flexible
	char **function_names;

	// Where the interpreter should read the instructions of the script
	FILE *stream; // TODO: implement a function to do this?

	int lineNum;
} interpreter_t;

void throw_exception(runtime_exception e, interpreter_t *i);

interpreter_t* interpreter_init();
void free_interpreter(interpreter_t *i);
/*
 * The file stream can even be stdin (or standard input)... "File s = stdin"
 */
void start_interpreter(interpreter_t *interpreter);
char* itoa(int value, char *str, int base);
char* strr(char *str, char *output, int x, int y);
char* equstr(char *str, char *output);
void clear_str(char *str);
int is_string(char *str);
int is_sint(char *str);
void lang_prints(char *s);
void lang_printi(int i);
void lang_system(char *s);
char* lang_arg_lens(char *s);

#endif /* SRC_INTERPRETER_H_ */
