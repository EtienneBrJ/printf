#include "holberton.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * convert_binary - convert a decimal number to binary
 *
 * @args: pointer to the current argument
 * @flagstr: tmp buffer
 *
 * Return: string to print
 **/
char *convert_binary(va_list args, __attribute__((unused))char *flagstr)
{
	char *res = "Holberton";
	char s[20];
	int ite, n, max;
	unsigned int i = 0;

	n = va_arg(args, int);

	while (n > 0)
	{
		s[i] = n % 2;
		n = n / 2;
		i++;
	}
	res = _calloc(9 + 1, sizeof(char));
	max = i - 1;
	printf("%d : s[0] - %d : s[1] - %d : s[2]\n", s[0], s[1], s[2]);
	for (ite = 0; max > -1; ite++, max--, i--)
	{
		res[ite] = s[max];
	}
	return (res);
}
