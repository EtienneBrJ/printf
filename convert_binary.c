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
	char *res;
	char s[1024];
	char result[1024];
	int ite, n, max;

	unsigned int i = 0;

	if (args == NULL)
		return (NULL);

	n = va_arg(args, int);

	while (n > 0)
	{
		s[i] = n % 2 + '0';
		n = n / 2;
		i++;
	}
	max = i - 1;

	res = _calloc(i + 1, sizeof(char));

	for (ite = 0; max > -1; ite++, max--, i--)
	{
		result[ite] = s[max];
	}
	result[ite] = '\0';

	_strcat(res, result);

	return (res);
}
