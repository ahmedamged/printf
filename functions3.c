#include "main.h"
/**
 * handle_string - stdout function
 * @s: string to print
 * @old_count: number of chars printed
 * before calling this
 *
 * handles the printing of a string
 *
 * Return: the new count of chars printed
 */
int handle_string(char *s, int old_count)
{
	if (s == NULL)
	{
		s = "(null)";
	}
	while (*s != '\0')
	{
		_putchar(*s);
		s++;
		old_count++;
	}
	return (old_count);
}
/**
 * handle_char - stdout function
 * @c: char to print
 * @old_count: number of chars printed
 * before calling this
 *
 * handles the printing of a char
 *
 * Return: the new count of chars printed
 */
int handle_char(char c, int old_count)
{
	_putchar(c);
	old_count++;
	return (old_count);
}
