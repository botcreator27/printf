#include "main.h"

/**
 * print_integer - prints an integer
 * @arglist: argument list
 *
 * Return: number of characters printed.
 */
int print_integers(va_list arglist)
{
	int n = va_arg(arglist, int);
	int count = 0;
	char buffer[50];
	int i = 0, j, negative = 0;

	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}

	if (n < 0)
	{
		negative = 1;
		n = -n;
	}

	while (n != 0)
	{
		buffer[i++] = (n % 10) + '0';
		n /= 10;
	}
	if (negative)
	{
		buffer[i++] = '-';
	}
	for (j = i -1; j >= 0; j--)
	{
		write(1, &buffer[j], 1);
		count++;
	}
	return (count);
}
