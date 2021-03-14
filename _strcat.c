#include "holberton.h"
/**
 * _strcat - concatenates two strings
 * @src: add this chain of characters to the string dest, overwriting the
 * terminating null byte (\0) at the end of the dest
 * @dest : result string
 * Return: @dest
 */
char *_strcat(char *dest, char *src)
{
	int lenght = 0;
	int i;

	while (dest[lenght] != '\0')
	{
		lenght++;
	}
	for (i = 0; src[i] != '\0'; i++, lenght++)
	{
		dest[lenght] = src[i];
	}
	dest[lenght] = '\0';
	return (dest);
}
