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

	char *tmpstring, *resultstring;

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

	resultstring = flags_handler(flagstr, tmpstring, is_negative);

	return (resultstring);
}

/**
 * flags_handler - This abomination checks our flags and applies them
 * @flags: A string of the flags we need to apply
 * @oristring: The original string of numbers which we're going to modify
 * @is_negative: An int that indicates wether or not our int was negative
 *
 * Return: an integer
 */
char *flags_handler(char *flags, char *oristring, int is_negative)
{
	int ite1 = 0, ite2 = 0, ite3 = 0, plus_sign = 0, ignore_space = 0,
		space_sign = 0, zero_is_fieldwidth = 0, justify_left = 0,
		first_zero_seen = 0, zero_followers, signage_done = 0,
	        precison_done = 0, short_long_done = 0, zeros = 0, count = 0,
		maximum_chars_int = 0, number_of_zero_int = 0,
		field_width_int = 0, zeros_int = 0, spaces = 0,
		number_of_zeros_int = 0;

	char *tmpstring, *returnstring, *field_width, *number_of_zeros,
		*maximum_chars, *flags_percent, *flagstr, *resultstring;

	char flag;

	while (flags[ite1]!= '\0')
	{
		flags[ite1] = flag;

		if (flag == '+' && signage_done != 1)
		{
			plus_sign = 1;
			ignore_space = 1;
		}
		else if (flag == ' ' && signage_done != 1)
		{
			space_sign = 1;
		}
		else if (flag == '-' && signage_done != 1)
		{
			zero_is_fieldwidth = 1;
			justify_left = 1;
		}
		else if (flag == '0' && first_zero_seen != 1)
		{
			if (zero_is_fieldwidth = 1)
			{
				ite2 = 0;
				while (flagstr[ite1 + 1] >= '0' && flagstr[ite1 + 1] <= '9')
				{
					field_width[ite2] = flagstr[ite1];
					ite1++;
					ite2++;
				}
				field_width[ite2] = '\0';
				flag = flagstr[ite1];
			}
			zero_followers = 1;
			signage_done = 1;
			first_zero_seen = 1;
		}
		else if (flag >= '0' && flag <= '9')
		{
			if (zero_followers == 1)
			{
				ite2 = 0;
				while (flagstr[ite1 + 1] >= '0' && flagstr[ite1 + 1] <= '9')
				{
					number_of_zeros[ite2] = flagstr[ite1];
					ite1++;
					ite2++;
				}
				number_of_zeros[ite2] = '\0';
				zero_followers = 0;
			}
			ite2 = 0;
			while (flagstr[ite1 + 1] >= '0' && flagstr[ite1 + 1] <= '9')
			{
				field_width[ite2] = flagstr[ite1];
				ite1++;
				ite2++;
			}
			field_width[ite2] = '\0';
			signage_done = 1;
			flag = flagstr[ite1];
		}
		else if (flag == '.' && (flagstr[ite1 + 1] >= '0' && flagstr[ite1 + 1] <= '9') && precison_done != 1)
		{
			while (flagstr[ite1 + 1] >= '0' && flagstr[ite1 + 1] <= '9')
			{
				maximum_chars[ite2] = flagstr[ite1];
				ite1++;
				ite2++;
			}
			maximum_chars[ite2] = '\0';
			precison_done = 1;
			signage_done = 1;
			flag = flagstr[ite1];
		}
		else if ((flag == 'l' || flag == 'h') && short_long_done != 1)
			short_long_done = 1;

		else if (flag == 'd' || flag == 'i')
			break;

		else
		{
			flags_percent[0] = '%';
			flags_percent[1] = '\0';
			_strcat(flags_percent, flags);
			return (flags_percent);
		}

		ite1++;
	}


	while (oristring[count] != '\0')
	{
		count++;
	}

	if (maximum_chars != NULL)
	{
		maximum_chars_int = _atoi(maximum_chars);
		zeros = maximum_chars_int - count;

		while (zeros > 0)
		{
			tmpstring[ite3] = '0';
			zeros -= 1;
			ite3++;
			count++;
		}
	}

	if (plus_sign = 1 && is_negative != 1)
	{
		tmpstring[ite1] = '+';
		count++;
	}
	else if (space_sign = 1 && is_negative != 1)
	{
		tmpstring[ite1] = ' ';
		count++;
	}
	else if (is_negative == 1)
	{
		tmpstring[ite1] = '-';
		count++;
	}

	if (number_of_zeros != NULL)
	{
		number_of_zeros_int = _atoi(number_of_zeros);
		zeros = number_of_zeros_int - count;
		while (zeros_int > 0)
		{
			tmpstring[ite3] = '0';
			zeros -= 1;
			ite3++;
			count++;
		}

	}

	_strcat(tmpstring, oristring);
	ite3 = 0;

	if (field_width != NULL)
		field_width_int = _atoi(field_width);

	if (justify_left != 1 && field_width != NULL)
	{
		spaces = field_width_int - count;
		while (spaces > 0)
		{
			resultstring[count] = ' ';
			spaces -= 1;
			count++;
		}
	}

	_strcat(resultstring, tmpstring);

	if (justify_left == 1 && field_width != NULL)
	{
		spaces = field_width_int - count;
		while (spaces > 0)
		{
			resultstring[ite3] = ' ';
			spaces -= 1;
			ite3++;
			count++;
		}
	}

	resultstring[count] = '\0';

	return (resultstring);
}

/**
 * _atoi - convert a string to an integer
 * @s: a pointer
 *
 * Return: an integer
 */
int _atoi(char *s)
{
	int ite1 = 0, ite2, num = 0, sign = 1;

	while (s[ite1] != '\0' && (s[ite1] < '0' || s[ite1] > '9'))
	{
		if (s[ite1] == '-')
		{
			sign *= -1;
		}
		ite1++;
	}
	ite2 = ite1;
	while (s[ite2] >= '0' && s[ite2] <= '9')
	{
		num = (num * 10) + (s[ite2] - '0') * sign;
		ite2++;
	}
	return (num);
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
