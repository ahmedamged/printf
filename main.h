#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stddef.h>
int _putchar(char c);
int _printf(const char *format, ...);
int handle_switch(const char *format, va_list args, int old_count, unsigned int *i);
int handle_char(char c, int old_count);
int handle_string(char *s, int old_count);
#endif
