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

	while (buffer[count] != '\0')
		count++;

	write(1, buffer, count);

	return (count);
}
