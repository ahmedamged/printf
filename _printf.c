#include "main.h"
#include <stdio.h>
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
/**
 * handle_format - stdout function
 * @i: index of format
 * @format: format to handle
 * @args: list of args
 * @old_count: count of chars printed
 * before calling this
 *
 * handles the printing of a format
 *
 * Return: the new count of chars printed
 */
int handle_format(unsigned int *i, const char *format, va_list args, int old_count)
{
	(*i)++;
	switch (format[*i])
	{
	case 'c':
		old_count = handle_char((char)va_arg(args, int), old_count);
		break;
	case 's':
		old_count = handle_string(va_arg(args, char *), old_count);
		break;
	case '%':
		old_count = handle_char('%', old_count);
		break;
	case '\0':
		printf("reached the one %% case\n");
		return (-1);
	default:
		(*i)--;
		old_count = handle_char(format[*i], old_count);
		break;
	}
	return (old_count);
}
/**
 * _printf - stdout function
 * @format: the format string
 *
 * prints the string to stdout
 *
 * Return: number of chars printed
 * (except the null char)
 */
int _printf(const char *format, ...)
{
	unsigned int i, count = 0;
	va_list args;

	if (format != NULL)
	{
		va_start(args, format);
		for (i = 0; format[i] != '\0'; i++)
		{
			if (format[i] == '%')
			{
				count = handle_format(&i, format, args, count);
			}
			else
			{
				count = handle_char(format[i], count);
			}
		}
		va_end(args);
		return (count);
	}
	return (-1);
}
