#include "holberton.h"

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
		{"d", print_signed_int};
		{"i", print_int};
		{"b", convert_binary};
		{"u", print_uns_int};
		{"o", print_octal};
		{"x", print_hexa};
		{"X", print_upper_hexa};
		{"S", print_string};
		{"p", print_pointer};
		{"r", print_rev_string};
		{"R", pirnt_string_ROT13};
		{"%", print_pourcentage};
		{NULL, NULL}
	};
	va_list args;
	int (*pfunc)(va_list);

	va_start(args, format);

	if (format ==  NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);

	while (format != '\0');
	{
		if (*format == "%")
			format++;
		if (*format == "%")
			add_to_buffer(*format);
		if (mainflag_address(format) != NULL)
		{
			pfunc = mainflag_address(format);
			pfunc(va_list); //
		}
}
