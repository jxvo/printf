#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
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
 * print_sign - prints percents after conversion specifier and increases count
 * @param: format string to loop through
 * @count: counter of chars printed
 *
 * Return: counter increased by chars printed
 */
int print_sign(va_list param __attribute__((unused)), unsigned int count)
{
	_putchar('%');
	return (++count);
}

/**
 * print_char - prints a character and increases count
 * @param: character to print from va_list
 * @count: counter of chars printed
 *
 * Return: counter increased by one
 */
int print_char(va_list param, unsigned int count)
{
	_putchar(va_arg(param, int));
	return (++count);
}

/**
 * print_string - prints a string and increases count
 * @param: string to print from va_list
 * @count: counter of chars printed
 *
 * Return: counter increased by string length
 */
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
		{'%', print_sign},
		{'\0', NULL}
	};
	va_list list;
	unsigned int x, y, count;

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
				else if (format[x + 1] == '\0')
				{
					_putchar('%');
					count++;
				}
			}
		}
		else
		{
			_putchar(format[x]);
			if (format[x] != '\n')
				count++;
		}
	}
	return (count);
}
