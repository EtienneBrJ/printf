#include "holberton.h"
#include <stdio.h>
/**
 * main_flag_address - returns a pointer to a function associated with the char
 * passed in arguments
 *
 * @args:
 **/

char *(*get_cs_func(char c))(va_list, char *)
{
	print_t array[] = {
//		{"c", print_char},
//		{"s", print_string},
		{"d", print_int},
		{"i", print_int}
//		{"b", convert_binary},
//		{"u", print_uns_int},
//		{"o", print_octal},
//		{"x", print_hexa},
//		{"X", print_upper_hexa},
//		{"S", print_string},
//		{"p", print_pointer},
//		{"r", print_rev_string},
//		{"R", pirnt_string_ROT13}
	};

	int i;
	int size = 2;

	printf("test13");
	for (i = 0; i < size; i++)
		if (*array[i].m == c)
		{
			printf("test12");
			return (array[i].func);
		}
	return (NULL);
}
