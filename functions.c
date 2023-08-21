#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
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

	if (i < 0)
	{
		putchar('-');
		charPrinted++;
		i = -i;
	}

	while (i > 0)
	{
		buff[o++] = '0' + (i % 10);
		i /= 10;
		charPrinted++;
	}

	for (int m = o - 1; m >= 0; m--)
	{
		putchar(buff[m]);
	}
	old_count += charPrinted;
	return (old_count);
}
