#include "holberton.h"
#include <stdlib.h>
#include <stdio.h>
/**
 * rev_string - function that reverses a string
 * @s: string to reverse
 * Return: reversed string
 */
char *rev_string(va_list args,__attribute__((unused))char *flagstr)
{
	int i = 0;
	int max, min, temp;
	char *s = va_arg(args, char *);
	char *str;
	if (!s)
		return (NULL);

	min = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	str = malloc(sizeof(char) * (i + 1));
	*str = 0;
	max = i - 1;

	for (min = 0; min < max; min++, max--)
	{
		temp = s[max];
		str[max] = s[min];
		str[min] = temp;
	}

	return (str);
}
