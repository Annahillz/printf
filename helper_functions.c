#include "main.h"
#include <stdlib.h>
#include <unistd.h>

/**
 * _putchar - writes the character c to
 * standard output
 * @c: the character to print
 *
 * Return: on success 1
 * on error, -1 is returned, and errno is set appropriately
 */

int _putchar(char c)
{
	return (write(1, &c, 1));

}

/**
 * _puts - prints a string to standard output
 * @str: pointer to address value
 *
 * Return: void
 */

void _puts(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		_putchar(str[i]);
	}
}

/**
 * _strlen - returns the length of a string
 * @s: pointer with the address value
 *
 * Return: void
 */

int _strlen(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
	{
		;
	}
	return (i);
}

/**
 * convert_to_format - convert from a format to another
 * @number: unsigned int
 * @base: base representation
 * Return: is a pointer to string
 */

char *convert_to_format(unsigned int number, int base)
{
	char *str;

	char representation[] = "0123456789ABCDEF";

	static char buffer[128];

	int mod = 0;

	str = &buffer[127];

	*str = '\0';

	do {
		mod = number % base;
		*--str = representation[mod];
		number /= base;
	} while (number != 0);
	return (str);
}
