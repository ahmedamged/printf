#include "main.h"

/**
 * handle_int_to_binary - stdout function
 * @i: integer to print
 * @old_count: number of chars printed
 * before calling this function
 * Return: the new count of chars printed
 */
int handle_int_to_binary(unsigned int i, int old_count)
{
	char buff[34];
	int charPrinted = 0;
	int o = 0;
	int m = 0;

	if (i == 0)
	{
		_putchar('0');
		return (old_count + 1);
	}

	while (i > 0)
	{
		buff[o++] = '0' + (i % 2);
		i /= 2;
		charPrinted++;
	}

	m = o - 1;
	while (m >= 0)
	{
		_putchar(buff[m]);
		m--;
	}
	old_count += charPrinted;
	return (old_count);
}
