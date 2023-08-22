#include "main.h"
/**
 * handle_unsigned_int - stdout function
 * @i: integer to print
 * @old_count: number of chars printed
 * before calling this function
 * Return: the new count of chars printed
 */
int handle_unsigned_int(unsigned int i, int old_count)
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
/**
 * handle_int_to_octal - stdout function
 * @i: integer to print
 * @old_count: number of chars printed
 * before calling this function
 * Return: the new count of chars printed
 */
int handle_int_to_octal(unsigned int i, int old_count)
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
		buff[o++] = '0' + (i % 8);
		i /= 8;
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
/**
 * handle_int_to_hex - stdout function
 * @i: integer to print
 * @old_count: number of chars printed
 * @isCapital: if Letters show be Capital
 * before calling this function
 * Return: the new count of chars printed
 */
int handle_int_to_hex(unsigned int i, int old_count, bool isCapital)
{
	char buff[34];
	int charPrinted = 0, reminder, o = 0, m = 0;

	if (i == 0)
	{
		_putchar('0');
		return (old_count + 1);
	}

	while (i > 0)
	{
		reminder = i % 16;
		buff[o++] = reminder < 10 ? '0' + reminder : isCapital ? 'A' + reminder - 10
															   : 'a' + reminder - 10;
		i /= 16;
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
