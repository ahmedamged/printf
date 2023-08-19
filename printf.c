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

	va_start(args, format);
	if (format != NULL)
	{
		for (i = 0; format[i] != '\0'; i++)
		{
			if (format[i] == '%')
			{
				i++;
				/* format handlers: */
				switch (format[i])
				{
				case 'c':
					count = handle_char((char)va_arg(args, int), count);
					break;
				case 's':
					count = handle_string(va_arg(args, char *), count);
					break;
				}
			}
			else
			{
				count = handle_char(format[i], count);
			}
		}
	}
	va_end(args);
	return (count);
}
