#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include "holberton.h"

/*
char *_itoa(int num)
{
	int result = num;
	unsigned int i, size = 0;
	char *arr;

	while (result)
	{
		result = result / 10;
		size++;
	}
	arr = malloc();


}
*/
/* string length */
unsigned int _strlen(char *s)
{
	unsigned int x;

	for (x = 0; s[x] != '\0'; x++)
		;
	return (x);
}

int _putchar(char c)
{
	return(write(1, &c, 1));
}

int print_char(va_list param, unsigned int count)
{
	_putchar(va_arg(param, int));
	return (++count);
}

int print_string(va_list param, unsigned int count)
{
	unsigned int x, len = 0;
	char *print = va_arg(param, char *);
	len = _strlen(print);

	for (x = 0; x < len; x++)
	{
		_putchar(print[x]);
	}
	return (count + len);
}

/**
 * _printf - produces output according to a format
 * @format: string to search through for conversion specifiers, and print
 *
 * Return: integer number of characters printed, excluding NULL byte
 */
int _printf(const char *format, ...)
{
	types arr[] = {
		{'c', print_char},
		{'s', print_string},
		{'\0', NULL}
	};
	va_list list;
	unsigned int x, y, count = 0;

	va_start(list, format);
	for (x = 0; format != NULL && format[x] != '\0'; x++)
	{
		if (format[x] == '%')
		{
			for (y = 0; arr[y].typ != '\0'; y++)
			{
				if (format[x + 1] == arr[y].typ)
				{
					count = arr[y].f(list, count);
					x++;
				}
				else if (format[x + 1] == '%')
				{
					_putchar('%');
					count++;
					x++;
					if (format[x + 2] == arr[y].typ)
						x--;
				}
				else if (format[x + 1] == '\0')
				{
					_putchar('%');
					count++;
					}
			}

		}
		/*else if (format[x] == ' ')
		{
			_putchar(' ');
			count++;
			}*/
		else
		{
			_putchar(format[x]);
			if (format[x] != '\n')
				count++;
		}
	}
	return (count);
}
