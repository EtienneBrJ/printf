#include "holberton.h"

/**
 * _print_int - Adds integers to our buffer
 * @args: pointer to the current va_arg
 *
 * Return: Our temporary buffer
 */

char *_print_int(va_list args, char *flagstr)
{
	int ite1, rem, len = 0, n;

	char tmpbuffer[20], *tmpstring;

	if (args == NULL)
		return(NULL);

	flags_handler(flagstr);
	num = va_arg(args, int);
	if (num == 0)
	{
	}
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	for (i = 0; i < len; i++)
	{
		rem = num % 10;
		num = num / 10;
		str[len - (i + 1)] = rem + '0';
	}
	str[len] = '\0';
}

char *flags_handler(char *flags, va_list args)
{
	int ite1 = 0;
	char *tmpstring, *returnstring;

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
		{
			short_long_done = 1;
		}
		else
		{
			return (flags);
		}
		ite1++;
	}


	while (args[count] != '\0')
	{
		count++;
	}

	if (maxium_chars != NULL)
	{
		maxium_chars_int = _atoi(maxium_chars);
		zeros = maximum_chars_int - count;

		while (zeros > 0)
		{
			tmpstring[ite3] = '0';
			zeros -= 1;
			ite3++;
			count++;
		}
	}

	if (plus_sign = 1)
	{
		tmpstring[ite1] = '+';
		count++;
	}
	else if (space_sign = 1)
	{
		tmpstring[ite1] = ' ';
		count++
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

	_strcpy(tmpstring, args);
	ite3 = 0;

	if (field_width != NULL)
		field_width_int = _atoi(field_width);

	if (justify_left == 1 && field_width != NULL)
	{
		spaces = field_width_int - count;
		while (spaces > 0)
		{
			resultstring[count] = ' ';
			spaces -= 1;
			count++;
		}
	}

	_strcpy(resultstring, tmpstring);

	if (field_width != NULL)
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
 * _strcpy - copy a string to another string
 * @dest: a pointer
 * @src: another pointer
 *
 * Return: Nothing
 */
char *_strcpy(char *dest, char *src)
{
	int t;

	for (t = 0; src[t] != '\0'; t++)
	{
		dest[t] = src[t];
	}
	dest[t] = '\0';
	return (dest);
}
