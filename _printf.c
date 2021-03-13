#include "holberton.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

/**
 * _printf - Produces output according to a format.
 * @format: Character string that tells us what to do
 *
 * Return: Either 0 or -1
 */

int _printf(const char *format, ...)
{
	print_t array[] = {
		{"c", print_char},
		{"s", print_string},
		{NULL, NULL}
	};
	va_list args;

	va_start(args, format);
}
