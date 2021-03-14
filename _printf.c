#include "holberton.h"

/**
 * _printf - Produces output according to a format.
 * @format: Character string that tells us what to do
 *
 * Return: Either 0 or -1
 */

int _printf(const char *format, ...)
{
	va_list args;
	int (*pfunc)(va_list, char *);
	int i;
	char *tmpBuffer;
	char *buffer;

	va_start(args, format);

	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%' && format[i + 1] == '%')
		{
			i++;
			_strcat(tmpBuffer, format[i]);
			i++;
		}
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			while(get_cs_func(format[i]) == NULL && format[i] != '\0')
			{
				_strcat(tmpBuffer, format[i]);
				i++;
			}
			if (format[i] == '\0')
				_strcat(buffer, tmpBuffer);
			else if (get_cs_func(format[i]))
			{
				pfunc = get_cs_func(format[i]);
				_strcat(tmpBuffer, format[i]);
				buffer = pfunc(args, tmpBuffer);
			}
		}
		else if
			_strcat(buffer, format[i]);
	}

	va_end(args);

	_putnchar(buffer); //print (strlen(buffer)) chars

	return (0);
}
