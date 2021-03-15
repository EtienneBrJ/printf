#include "holberton.h"
/**
 * rev_string - function that reverses a string
 * @s: string to reverse in the function
 */
void rev_string(va_list args,__attribute__((unused))char *flagstr)
{
	int i = 0;
	int max, min, temp;
	char *s;

	s = va_arg(args, char *)

	min = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	max = i - 1;

	for (min = 0; min < max; min++, max--)
	{
		temp = s[max];
		s[max] = s[min];
		s[min] = temp;
	}
}
