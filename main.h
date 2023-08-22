#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stddef.h>
#include <stdbool.h>
int _putchar(char c);
int _printf(const char *format, ...);
int handle_format(unsigned int *i, const char *format,
				  va_list args, int old_count);
int handle_char(char c, int old_count);
int handle_string(char *s, int old_count);
int handle_int(int i, int old_count);
int handle_unsigned_int(unsigned int i, int old_count);
int handle_int_to_binary(unsigned int i, int old_count);
int handle_int_to_octal(unsigned int i, int old_count);
int handle_int_to_hex(unsigned int i, int old_count, bool isCapital);
int handle_custom_string(char *s, int old_count);
#endif
