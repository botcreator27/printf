#include "main.h"

/**
 * print_num - prints out numbers recursively
 * @num: integer to be printed
 * Return: number of digits
 */

int print_num(int num)
{
/* deals with integer cases */

	int count = 0;
	char digit;
	int result;

	/* when num is 0 */
	if (num == 0)
	{
		write(1, "0", 1);
		count++;
		return (1);
	}
	if (num < 0)
	{
		write(1, "-", 1);
		num = num * -1;
		count++;
	}

	if (num / 10 > 0)
	{
		count += print_num(num / 10);

	}
	digit =  (num % 10) + '0';
	result = write(1, &digit, 1);
	count += result;

	return (count);
}

/**
 * _printf - prints out strings passed and substitues specifiers
 * @format: string passed
 * Return: number of characters printed
 *
 */

int _printf(const char *format, ...)
{
	int characters_printed = 0; /* counts the characters printed */
	const char *character;
	va_list arglist;

	va_start(arglist, format);

	if (format == NULL)
	{
		return (-1);
	}

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

			if (str == NULL)
			{
			str = "(null)";
			write(1, str, 1);
			}
			else
			{
			int str_length = strlen(str); /*calculate string length */

			write(1, str, str_length);
			characters_printed += str_length;
			}
		}
		else if (*character == '%')
		{
			write(1, character, 1);
			characters_printed++;
		}
		else if (*character == 'd' || *character == 'i')
		{
			int num = va_arg(arglist, int);
			characters_printed += print_num(num);
		}
		else
		{
			write(1, "%", 1);
			write(1, character, 1);
			characters_printed += 2;
		}
	}
	}
	va_end(arglist);
	return (characters_printed); /* returns total number of characters printed */
}
