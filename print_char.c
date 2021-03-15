#include "holberton.h"
/**
 * _print_char - Add char to our buffer
 * @args: pointer to the current va_arg
 * @flagstr: This a string of our flags, which we will apply
 *
 * Return: Our temporary bufferr
 */
char *print_char(va_list args, char *flagstr)
{
	char c = va_arg(args, int);
	char *s = malloc(sizeof(char) * 2);
	*s = '\0';

	flagstr = flagstr;

	if (c)
	{
		s[0] = c;
		s[1] = '\0';

		return (s);
	}
	else
	{
		s[0] = '\0';
		s[1] = '\0';

		return (s);
	}
}
/**
 * _print_string - Add a string to our buffer
 * @args: pointer to the current va_arg
 * @flagstr: This a string of our flags, which we will apply
 *
 * Return: Our temporary buffer
 */
char *print_string(va_list args, char *flagstr)
{
	int ite = 0, count = 0;
	char *s = va_arg(args, char *);
	char *str;

	while (s[count] != '\0')
		count++;

	str = malloc(sizeof(char) * (count + 1));

	flagstr = flagstr;

	if (s[0])
	{
		while (s[ite] != '\0')
		{
			str[ite] = s[ite];
			ite++;
		}
		return (str);
	}

	return (NULL);
}

/*char *convert_char_to_str(va_list args, char *flagster)
{
	*/
