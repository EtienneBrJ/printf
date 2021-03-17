#include "holberton.h"

/**
 * _putnchar - Prints a buffer.
 * @buffer: buffer to print
 *
 * Return: Number of characters printed
 */
int _putnchar(char buffer[])
{
	int count = 0;
	int ite;

	while (buffer[count] != '\0')
		count++;

	write(1, buffer, count);

	for (ite = 0; ite > 1023; ite++)
		buffer[ite] = '\0';

	return (count);
}
