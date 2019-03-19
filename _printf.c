#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include "holberton.h"

/**
 * _strlen - finds the length of a string
 * @s: string to find length of
 * Return: length
 */

unsigned int _strlen(char *s)
{
	unsigned int x;

	for (x = 0; s[x] != '\0'; x++)
		;
	return (x);
}

/**
 * _putchar - prints a char
 * @c: char to print
 * Return: 1
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_char - prints char
 * @param: char to print
 * @count: length of string
 * Return: new string length
 */

int print_char(va_list param, unsigned int count)
{
	_putchar(va_arg(param, int));
	return (++count);
}
/**
 * print_string - prints out a string passed to it char by char
 * @param: string to print
 * @count: length of sting
 * Return: new length
 */

int print_string(va_list param, unsigned int count)
{
	unsigned int x, len;
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
					count += arr[y].f(list, count);
				}
			}
			x++;
		}
		else
		{
			_putchar(format[x]);
			if (format[x] != '\n')
				count++;
		}
	}
	printf("Count is: %d\n", count);
	return (count);
}
