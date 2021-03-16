#include "holberton.h"
/**
 * _putnchar - print n char
 * @buffer: string to print
 * Return: count
 */
int _putnchar(char buffer[])

{

	int ite = 0;
	int count = 0;

	while (buffer[ite] != '\0')

	{

		count++;

		ite++;

	}

	write(1, buffer, count);

	return (count);

}
