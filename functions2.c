#include "main.h"
/**
 * handle_address - stdout function
 * @i: address to print
 * @old_count: number of chars printed
 * before calling this function
 * Return: the new count of chars printed
 */
int handle_address(void *i, int old_count)
{
	if (i == NULL)
	{
		old_count = handle_string("(nil)", old_count);
	}
	else
	{
		old_count = handle_string("0x", old_count);
		old_count = handle_int_to_hex((size_t)i, old_count, false);
	}
	return (old_count);
}
/**
 * handle_rev_string - stdout function
 * @s: string to print
 * @old_count: number of chars printed
 * before calling this
 *
 * handles the printing of a string
 *
 * Return: the new count of chars printed
 */
int handle_rev_string(char *s, int old_count)
{
	if (s == NULL)
	{
		s = "(null)";
	}
	if (*s != '\0')
	{
		old_count = handle_rev_string(s + 1, old_count);
		_putchar(*s);
		old_count++;
	}

	return (old_count);
}