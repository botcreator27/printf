#include "main.h"

/*
 * _printf - prints to stdout
 * @format: format string
 * Return: number of characters printed
 *
 */

int _printf(const char *format, ...)
{
	const char *character;
	va_list(arglist);
	int count = 0;
	char buffer[20];

	if (format == NULL)
	{
	return (-1);
	}

	va_start(arglist, format);

	for (character = format; *character != '\0'; character++)
	{
	if (*character != '%')
	{
		write(1, character, 1);
		count++;
	}
	else
	{
		character++;
		if (*character == 'd'|| *character == 'i')
		{
		int value = va_arg(arglist, int);
		int len_of_int = snprintf(buffer, sizeof(buffer), "d", value);
		write(1, buffer, len_of_int);
		count += len_of_int;       
		}
	}
	}
	va_end(arglist);
	return (count);
}

