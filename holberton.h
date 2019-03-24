#ifndef _HOLBERTON_
#define _HOLBERTON_

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

/**
 * struct types - corresponds character to print function of matching type
 *
 * @typ: character of type (c = char, f = float, i = int, s = string)
 * @f: pointer to print function
 */
typedef struct types
{
	char typ;
	int (*f)();
} types;

int _printf(const char *format, ...);
int _print_sign(__attribute__((unused)) va_list param, unsigned int count);
int _putchar(char c);
unsigned int _strlen(char *s);
int print_sign(__attribute__((unused)) va_list param, unsigned int count);
int print_char(va_list param, unsigned int count);
int print_string(va_list param, unsigned int count);

#endif
