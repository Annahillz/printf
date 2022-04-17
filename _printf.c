#include "main.h"

/**
 * _printf - function produces output according to a format.
 * @format: is a pointer to string
 * Return: is the count of printed characters
 */

int _printf(const char *format, ...)
{
	const char *string;

	int count = 0;

	va_list args;

	if (!format)
		return (-1);

	va_start(args, format);
	string = format;

	count = loop_format(string, args);

	va_end(args);

	return (count);
}

/**
 * loop_format - function is to print format
 * @format: is a pointer to string
 * @args: is a va_list args
 * Return: is an integer.
 */

int loop_format(const char *format, va_list args)
{
	int i = 0, counter = 0, flag = 0, check_flag = 0, f_counter = 0;

	while (i < _strlen(format) && *(format + i) != '\0')
	{
		char charac = format[i];

		if (charac == '%')
		{
			flag++, i++;
			charac = format[i];
			if (charac == '\0' && _strlen(format) == 1)
				return (-1);
			if (charac == '\0')
				return (counter);
			if (charac == '%')
				flag++;
			else
			{
				f_counter = func_service(charac, args);
				if (f_counter >= 0)
				{
					i++;
					charac = format[i];
					if (charac == '%')
						flag--;
					counter += f_counter;
				}
			}

		}
		check_flag = check_percent(&flag, charac);
		counter += check_flag;
		if (check_flag == 0 && charac != '%')
			counter += _putchar(charac), i++;
		flag = 0;
	}
	return (counter);
}


/**
 * check_percent - print a percentage
 * @flag: is address of an int
 * @charac: is a char
 * Return: is 1 if % was printed, 0 otherwise.
 */

int check_percent(int *flag, char charac)
{
	int count = 0;

	if (*flag == 2 && charac != '\0')
		count += _putchar('%');
	return (count);
}


/**
 * func_service - takes arguments and prints it accordingly
 * @charac: is a char or type determinant
 * @args: is a va_list
 * Return: is the number of characters printed
 */

int func_service(char charac, va_list args)
{
	int count = 0;

	count = _switch(charac, args);

	return (count);
}


/**
 * _switch - switch character to find arg
 * @arg: is a va_list argument
 * @c: is a char
 * Return: count of printed characters
 */

int _switch(char c, va_list arg)
{
	int count = 0;

	switch (c)
	{
		case 'c':
			count += print_character(arg);
			break;
		case 'd':
		case 'i':
			count += print_signInt(arg, 10);
			break;
		case 's':
			count += print_string(arg);
			break;
		case 'x':
			count += print_base16_toLower(arg);
			break;
		case 'X':
			count += print_base16_toUpper(arg);
			break;
		case 'p':
			count += print_addr(arg);
			break;
		case 'o':
			count += print_octal(arg, 8);
			break;
		case 'r':
			count += print_unknown(arg);
			break;
		case 'u':
			count += print_unsignInt(arg, 10);
			break;
		default:
			count = -1;
	}
	return (count);
}

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
	}
	s = convert_to_format(i, base);
	_puts(s);
	count += _strlen(s);
	return (count);
}

/**
 * print_unsignedInt - print unsigned
 * @arg: is a va_list parameter
 * @base: is an integer
 * Return: is a count of printed characters
 */

int print_unsignedInt(va_list arg, int base)
{
	int unsigned i;

	char *s;

	int count = 0;

	i = va_arg(arg, int);
	s = convert_to_format(i, base);
	_puts(s);
	count += _strlen(s);
	return (count);
}
