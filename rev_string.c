#include "holberton.h"
/**
 * rev_string - function that reverses a string
 * @s: string to reverse in the function
 */
void rev_string(char *s)
{
	int i = 0;
	int max, min, temp;

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
