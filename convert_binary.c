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
	char s[20];
	char finals[20];
	int ite, n, max;
	unsigned int i = 0;

	n = va_arg(args, int);

	while (n > 0)
	{
		s[i] = n % 2;
		n = n / 2;
		i++;
	}
	res = _calloc(i + 1, sizeof(char));
	max = i - 1;
	printf("%d : s[0] - %d : s[1] - %d : s[2]\n", s[0], s[1], s[2]);
	for (ite = 0; max > -1; ite++, max--, i--)
	{
		finals[ite] = s[max];
	}
      	finals[ite] = '\0';
	printf("%d : s[0] - %d : s[1] - %d : s[2]\n", finals[0], finals[1], finals[2]);
	res = finals;
	return (res);
}
#include "holberton.h"
/**
 * _memcpy - copes memory area
 * @dest: copie destination
 * @src: memory area to copie
 * @n: bytes
 * Return: dest copied
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		dest[i] = src[i];
	}
	return (dest);
}
