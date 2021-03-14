#include "holberton.h"

/**
 * main_flag_address - returns a pointer to a function associated with the char
 * passed in arguments
 *
 * @args:
 **/

int (*get_cs_func(char c))(va_list args, char *s) // for conversion specifiers
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
	};

	int i;
	int size = 14;

	for (i = 0; i < size; i++)
		if (*array[i].m == args)
			return (*array[i].func);
	return (NULL);
}
