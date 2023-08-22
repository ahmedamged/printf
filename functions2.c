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
	old_count = handle_string("0x", old_count);
	old_count = handle_int_to_hex((size_t)i, old_count, false);
	return (old_count);
}