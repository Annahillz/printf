#include "main.h"

/**
 * print_character - prints a character
 * @arg: is a va_list type
 * Return: 1
 */

int print_character(va_list arg)
{
	int i;

	i = va_arg(arg, int);
	_putchar(i);
	return (1);
}

/**
 * print_signInt - print sign
 * @arg: is a va_list argument
 * @base: e.g., base 10
 * Return: count of digits printed
 */

int print_signInt(va_list arg, int base)
{
	int i = 0, count = 0;

	char *s;

	i = va_arg(arg, int);
	if  (i < 0)
	{
		i = -(i);
		count += _putchar('-');
		s = convert_to_format(i, base);
		_puts(s);
		count += _strlen(s);
		return (count);
	}
}


/**
 * print_unsignedInt - print unsigned
 * @arg: is a va_list parameter
 * @base: is an integer
 * Return: is a count of printed characters
 */

int print_unsignedInt(va_list arg, int base)
{
	unsigned int i;

	char *s;

	int count = 0;

	i = va_arg(arg, int);
	s = convert_to_format(i, base);
	_puts(s);
	count += _strlen(s);
	return (count);

