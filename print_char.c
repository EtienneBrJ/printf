#include "holberton.h"
/**
 * _print_char - Add char to our buffer
 * @args: pointer to the current va_arg
 * @flagstr: This a string of our flags, which we will apply
 *
 * Return: Our temporary buffer
 */
char *print_char(va_list args)
{
	char c = va_arg(args, int);

	if (c)
	{
		char *s;
		s[0] = c;
		s[1] = '\0';

		return (s);
	}

	return (NULL);

}
/**
 * _print_string - Add a string to our buffer
 * @args: pointer to the current va_arg
 * @flagstr: This a string of our flags, which we will apply
 *
 * Return: Our temporary buffer
 */
char *print_string(va_list args)
{
	char *s = va_arg(args, char *);

	if (s)
	{
		return (s);
	}

	return (NULL);
}
