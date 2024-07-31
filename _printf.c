#include "main.h"

/**
 * _printf - prints out passed strings to stdout
 * @format: format string passed.
 *
 * Return: the number of characters printed.
 */

int _printf(const char *format, ...)
{
	int characters_printed = 0; /* counts the characters printed */
	const char *character;
	va_list arglist;

	if (format == NULL)
	{
		return (0);
	}
	va_start(arglist, format);

	for (character = format; *character != '\0'; character++)
	{
	if (*character != '%')
	{
		write(1, character, 1); /* write character to stdout */
		characters_printed++; /* count character */
	}
	else /* if character is % */
	{
		character++; /* skip to next character */

		if (*character == 'c') /* case 'c' */
		{
			char c = va_arg(arglist, int);
			write(1, &c, 1);
			characters_printed++;
		}
		else if (*character == 's')
		{
			char *str = va_arg(arglist, char *);
			int str_length = strlen(str); /*calculate string length */
			write(1, str, str_length);
			characters_printed += str_length; /* count whole length of string */
		}
<<<<<<< HEAD
=======
		else if (*character == 'd')
		{
			characters_printed += print_integers(va_list arglist);
		}
>>>>>>> ead9504aaa8d113c1998fa34a85f163ee1133318
		else if (*character == '%')
		{
			write(1, character, 1);
			characters_printed++;
		}

	}
	}
	va_end(arglist);
	return (characters_printed); /* returns total number of characters printed */
}
