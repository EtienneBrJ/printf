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
	int ite, test;

	while (buffer[count] != '\0')
		count++;

	test = write(1, buffer, count);

	for (ite = 0; ite < BUFFER_SIZE; ite++)
		buffer[ite] = '\0';

	return (test);
}
