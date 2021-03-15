#include "holberton.h"
/**
 * *_strcat - This function appends the src string to the dest string.
 * @dest: the destination string
 * @src: the source string
 *
 * Return: A pointer to the dest string
 */
int _catbuf(char dest[], char *src)
{
	int location = 0;
	int ite = 0;

	while (dest[location] != '\0')
		location++;

/*	printf("this is bad\n"); */
	while (src != NULL && src[ite] != '\0')
	{
/*		printf("this is awful\n"); */
		dest[location] = src[ite];
		ite++;
		dest++;
	}
	dest[location] = '\0';
	return (location);
}
