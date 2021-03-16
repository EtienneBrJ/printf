#include "holberton.h"

/**
 * handles_zeros - tells us how many zeros we need to put before our num
 * @itef: a static int, where we're at in the iteration
 * @flags: Our list of flags
 *
 * Return: The number of zeros
 */
int handles_zeros(int itef, char *flags)
{
	int ite2 = 0, int_return = 0;
	char number_of_zeros[10];

	while (flags[itef + 1] >= '0' && flags[itef + 1] <= '9')
	{
		number_of_zeros[ite2] = flags[itef + 1];
		itef++;
		ite2++;
	}
	number_of_zeros[ite2] = '\0';

	if (number_of_zeros[0] != '\0')
		int_return = _atoi(number_of_zeros);

	return (int_return);
}

/**
 * handles_padding - tells us how many spaces we need to put before our num
 * @itef: a static int, where we're at in the iteration
 * @flags: Our list of flags
 *
 * Return: The number of spaces
 */
int handles_padding(int itef, char *flags)
{
	int ite2 = 0, int_return = 0;
	char field_width[10];

	while (flags[itef] >= '0' && flags[itef] <= '9')
	{
		field_width[ite2] = flags[itef];
		itef++;
		ite2++;
	}
	field_width[ite2] = '\0';

	if (field_width[0] != '\0')
		int_return = _atoi(field_width);

	return (int_return);
}
