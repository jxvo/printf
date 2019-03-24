#include "holberton.h"

/**
 * _strlen - returns the length of a string
 * @s: string to measure
 *
 * Return: unsigned int length
 */
unsigned int _strlen(char *s)
{
	unsigned int x;

	for (x = 0; s[x] != '\0'; x++)
		;
	return (x);
}

/**
 * _putchar - write a character to standard output
 * @c: ascii character to print
 *
 * Return: 1 on success
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
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
		{'%', print_sign},
		{'\0', NULL}
	};
	va_list list;
	unsigned int x, y, count = 0;

	if (format == NULL)
		return (-1);
	va_start(list, format);
	for (x = 0; format[x] != '\0'; x++)
	{
		if (format[x] == '%')
		{
			if (format[x + 1] == '\0' || format[x + 1] == '\n')
				if (count == 0)
					return (-1);
			for (y = 0; arr[y].typ != '\0'; y++)
			{
				if (format[x + 1] == arr[y].typ)
				{
					count = arr[y].f(list, count);
					x++;
					break;
				}
			}
			if (arr[y].typ == '\0' && format[x + 1] != '\0')
				count = print_sign(list, count);
		}
		else
		{
			_putchar(format[x]);
			count++;
		}
	}
	va_end(list);
	return (count);
}
