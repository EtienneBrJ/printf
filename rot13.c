#include "holberton.h"
#include <stdlib.h>
#include <stdio.h>
/**
 * rot13 - encode a string into rot13
 * @args: pointer to the current arg
 * @flagstr: temporary buffer
 * Return: string encoded
 */
char *rot13(va_list args, __attribute__((unused))char *flagstr)
{
	int i, j, len;
	char *ROT13 = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char *rot13 = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";
	char *s;
	char *r13 = va_arg(args, char *);

	len = 0;

	if (!r13)
		return (NULL);

	while (r13[len] != '\0')
		len++;

	s = _calloc(len + 1, sizeof(char));
	_strcat(s, r13);

	for (i = 0; s[i]; i++)
		for (j = 0; ROT13[j]; j++)
			if (s[i] == ROT13[j])
			{
				s[i] = rot13[j];
				break;
			}
	return (s);

}
