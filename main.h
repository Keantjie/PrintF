#ifndef _MAIN_H_
#define _MAIN_H_

/* begin standard C header files */
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>
#include <stdio.h>

/* macros */

#define BUFSIZE 1024
#define TRUE (1 == 1)
#define FALSE !TRUE
#define LOWHEX 0
#define UPHEX 1

/* structs */
/**
 * struct list_s - inventory of common variables needed
 * @fmt: the input format string
 * @i: index to traverse the format string
 * @args: the variadic arguments list of input arguments
 * @buffer: buffer to be written to before writing to stdout
 * @buf_index: index to traverse the buffer, also total chars written
 * @flag: notifies if there was a modifier flag
 * @space: notifies if space was printed
 * @c0: character to be written to buffer
 * @c1: character checking after % character
 * @c2: character to check 2 spaces after % symbol
 * @c3: unused for now, but may become a third specifier
 * @error: indicates error or not (0 no error, 1 error)
 */
typedef struct list_s
{
	const char *fmt;
	int i;
	va_list *args;
	char *buffer;
	int buf_index;
	int flag;
	int space;
	char c0;
	char c1;
	char c2;
	char c3;
	int error;
} list_g;

/**
 * struct matches_s - printf specifiers and paired function
 * @ch: the specifier
 * @func: pointer to the conversion specifier function
 */
typedef struct matches_s
{
	char ch;
	void (*func)(list_g *inv);
} matches_g;

/* initializing and ending functions */
int _printf(const char *format, ...);
list_g *build_list(va_list *args_list, const char *format);
int end_func(list_g *arg_inv);

/* custom memory allocation and buffer */
void *_calloc(unsigned int nmemb, unsigned int size);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void write_buffer(list_g *inv);
void puts_buffer(list_g *inv, char *str);

/* string functions */
void rev_string(char *s);
int _strlen(char *s);
int _strlenconst(const char *s);
int _putchar(char c);
void puts_mod(char *str, unsigned int l);

/* parse and match functionality */
void (*match_specifier(list_g *inv))(list_g *inv);
void parse_specifiers(list_g *inv);

/* hexadecimal */
void print_hex(list_g *inv, unsigned long int n, int hexcase, int size);
void p_longlowhex(list_g *inv);
void p_longuphex(list_g *inv);
void p_lowhex(list_g *inv);
void p_uphex(list_g *inv);

/* integers */
void print_integers(list_g *inv, long int n);
void p_int(list_g *inv);
void p_longint(list_g *inv);
void print_unsign(list_g *inv, unsigned long int n);
void p_uint(list_g *inv);
void p_ulongint(list_g *inv);

/* octals */
void print_oct(list_g *inv, unsigned long int n, int size);
void p_oct(list_g *inv);
void p_longoct(list_g *inv);

/* handles specifier functions */
void p_char(list_g *inv);
void p_string(list_g *inv);
void p_string_hex(list_g *inv);
void p_pointer(list_g *inv);
void p_rev_string(list_g *inv);
void p_rot13(list_g *inv);
void p_percent(list_g *inv);
void p_binary(list_g *inv);

#endif
