#ifndef _HOLBERTON_
#define _HOLBERTON_

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
#endif
