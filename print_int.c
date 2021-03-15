#include "holberton.h"

/**
 * _print_int - Adds integers to our buffer
 * @args: pointer to the current va_arg
 * @flagstr: This a string of our flags, which we will apply
 *
 * Return: Our temporary buffer
 */

char *print_int(va_list args, char *flagstr)
{
	int ite, rem = 0, len = 0, num, num_decoy, is_negative = 0;

	char tmpstring[50], *resultstring;

	if (args == NULL)
		return(NULL);

	num = va_arg(args, int);

	if (num < 0)
	{
		num = -num;
		is_negative = 1;
	}

	num_decoy = num;

	while (num_decoy != 0)
	{
		len++;
		num_decoy /= 10;
	}
	for (ite = 0; ite < len; ite++)
	{
		rem = num % 10;
		num = num / 10;
		tmpstring[len - (ite + 1)] = rem + '0';
	}
	tmpstring[len] = '\0';

	_putnchar(tmpstring);

	return (0);
}
/**
 * *_strcat - This function appends the src string to the dest string.
 * @dest: the destination string
 * @src: the source string
 *
 * Return: A pointer to the dest string
 */
char *_strcat(char *dest, char *src)
{
	char *pointer = dest;

	while (*dest != '\0')
		dest++;
	/* ^ iteration pour arriver au dernier charactère de la string dest */

	while (*src != '\0')
	{
		*dest = *src;
		/* on est au début de la string src, et à la fin de la string dest */
		/* ^l'index actuel de la string dest devient l'index actuel de la string src */
		src++;
		dest++;
	}
	*dest = '\0';
	return (pointer);
}
