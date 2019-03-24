#include "holberton.h"

/**
 * print_sign - prints percents after conversion specifier and increases count
 * @param: format string to loop through
 * @count: counter of chars printed
 *
 * Return: counter increased by chars printed
 */
int print_sign(__attribute__((unused)) va_list param, unsigned int count)
{
	_putchar('%');
	return (++count);
}

/**
 * print_char - prints a character and increases count
 * @param: character param to print from va_list
 * @count: current count of chars printed
 *
 * @param: character param to print from va_list
 * @count: current count of chars printed
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
 * @param: current string param to print from va_list
 * @count: current count of chars printed
 *
 * Return: counter increased by string length
 */
int print_string(va_list param, unsigned int count)
{
	unsigned int c, len = 0;
	char *str = va_arg(param, char *);

	if (str == NULL)
	{
		str = "(null)";
	}
	len = _strlen(str);
	for (c = 0; c < len; c++)
	{
		_putchar(str[c]);
	}
	return (count + c);
}
