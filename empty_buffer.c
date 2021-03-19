#include "holberton.h"

/**
 * empty_buffer - This function empty the buffer when its full and calls print
 * @dest: the destination string
 * @src: the source string
 * @count: the total number of characters printed by printf so far
 *
 * Return: A pointer to the dest string
 */
int empty_buffer(char dest[], char *src, int count)
{
	int location = 0;
	int ite = 0;

	count = 0;

	while (dest[location] != '\0')
		location++;

	while (src != NULL && src[ite] != '\0')
	{
		if (location == BUFFER_SIZE)
		{
			dest[location] = '\0';
			count += _putnchar(dest);
			location = 0;
		}
		dest[location] = src[ite];
		ite++;
		location++;
	}
	dest[location] = '\0';
	return (count);
}
