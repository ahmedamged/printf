#include "main.h"
#include <stdio.h>
/**
 * handle_chars_format - stdout function
 * @format: format to handle
 * @args: list of args
 * @old_count: count of chars printed
 * before calling this
 *
 * handles the printing of a format
 *
 * Return: the new count of chars printed
 */
int handle_chars_format(const char format,
						va_list args, int old_count)
{
	switch (format)
	{
	case '%':
		old_count = handle_char('%', old_count);
		break;
	case 'c':
		old_count = handle_char((char)va_arg(args, int), old_count);
		break;
	case 's':
		old_count = handle_string(va_arg(args, char *), old_count);
		break;
	case 'S':
		old_count = handle_custom_string(va_arg(args, char *), old_count);
		break;
	case 'r':
		old_count = handle_rev_string(va_arg(args, char *), old_count);
		break;
	case 'R':
		old_count = handle_rot13_string(va_arg(args, char *), old_count);
		break;
	}
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
int handle_format(unsigned int *i, const char *format,
				  va_list args, int old_count)
{
	(*i)++;
	switch (format[*i])
	{
	case '%':
	case 'c':
	case 's':
	case 'S':
	case 'r':
	case 'R':
		old_count = handle_chars_format(format[*i], args, old_count);
		break;
	case 'i':
	case 'd':
		old_count = handle_int(va_arg(args, int), old_count);
		break;
	case 'u':
		old_count = handle_unsigned_int(va_arg(args, unsigned int), old_count);
		break;
	case 'b':
		old_count = handle_int_to_binary(va_arg(args, unsigned int), old_count);
		break;
	case 'o':
		old_count = handle_int_to_octal(va_arg(args, unsigned int), old_count);
		break;
	case 'x':
	case 'X':
		old_count = handle_int_to_hex(va_arg(args, unsigned int),
									  old_count, format[*i] == 'X');
		break;
	case 'p':
		old_count = handle_address(va_arg(args, void *), old_count);
		break;
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
				if (format[i + 1] == '\0')
				{
					return (-1);
				}
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
