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
/**
 * handle_rot13_string - stdout function
 * @s: string to print
 * @old_count: number of chars printed
 * before calling this
 *
 * handles the printing of a string
 *
 * Return: the new count of chars printed
 */
int handle_rot13_string(char *s, int old_count)
{
	if (s == NULL)
	{
		s = "(null)";
	}
	s = rot13(s);
	while (*s != '\0')
	{
		_putchar(*s);
		s++;
		old_count++;
	}

	return (old_count);
}
/**
 * rot13 - string function
 * @str: pointer to string to encode
 *
 * encodes a string using rot13
 *
 * Return: the pointer to encoded string
 */

char *rot13(char *str)
{
	int i, isUpper, oldCharIndex, newCharIndex;

	char *base = str;
	char *lower = "aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxXyYzZ";

	while (*str != '\0')
	{
		for (i = 0; i < 52; i++)
		{
			if (*str == lower[i])
			{
				isUpper = i % 2;
				oldCharIndex = i / 2;
				newCharIndex = (oldCharIndex + 13) % 26;
				newCharIndex = (newCharIndex * 2) + isUpper;
				*str = lower[newCharIndex];
				break;
			}
		}
		str++;
	}
	return (base);
}
