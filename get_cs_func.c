#include "holberton.h"

/**
 * get_cs_func - returns a pointer to a function associated with the char
 * passed
 * @c: char to test
 * Return: if the char is in the array of structs return the
 * associated function else NULL
 **/
char *(*get_cs_func(char c))(va_list, char *)
{
	print_t array[] = {
		{"c", print_char},
		{"s", print_string},
		{"d", print_int},
		{"i", print_int},
		{"r", rev_string},
		{"R", rot13},
		{"b", convert_binary}
/*
 *		{"u", print_uns_int},
 *		{"o", print_octal},
 *		{"x", print_hexa},
 *		{"X", print_upper_hexa},
 *		{"S", print_string},
 *		{"p", print_pointer},
 *		{"R", pirnt_string_ROT13}
 */
	};

	int i;
	int size = 7;

	for (i = 0; i < size; i++)
		if (*array[i].m == c)
			return (array[i].func);
	return (NULL);
}
