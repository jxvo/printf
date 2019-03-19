#ifndef _HOLBERTON_
#define _HOLBERTON_

typedef struct types
{
	char typ;
	int (*f)();
} types;

int _printf(const char *format, ...);
#endif
