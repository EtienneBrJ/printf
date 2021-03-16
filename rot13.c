#include "holberton.h"
#include <stdlib.h>
/**
 * rot13 - encode a string into rot13
 * @s: string to convert
 * Return: s converted
 */
char *rot13(va_list args, __attribute__((unused))char *flagstr)
{
	int i = 0, j;

	char a[52] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char b[52] = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";
	char *s = va_arg(args, char *);

	while (s[i])
		i++;
	s = malloc(sizeof(char) * (i + 1));
	for (i = 0; s[i] != '\0'; i++)
	{
		for (j = 0; j < 52; j++)
		{
			if (s[i] == a[j])
			{
				s[i] = b[j];
				break;
			}
		}
	}
	return (s);
}
