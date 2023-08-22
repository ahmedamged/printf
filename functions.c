#include "main.h"

/**
 * handle_int - stdout function
 * @i: integer to print
 * @old_count: number of chars printed
 * before calling this function
 * Return: the new count of chars printed
 */
int handle_int(int i, int old_count)
{
	char buff[32];
	int charPrinted = 0;
	int o = 0;
	int m = 0;

	if (i < 0)
	{
		_putchar('-');
		charPrinted++;
		i = -i;
	}

	while (i > 0)
	{
		buff[o++] = '0' + (i % 10);
		i /= 10;
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
