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
		if (format[i] == '%')
		{
			i++;
			while(get_cs_func(format[i]) == NULL && format[i])
			{
				_strcat(tmpBuffer, format[i]);
				i++;
			}
			pfunc = get_cs_func(format[i]);
			buffer = pfunc(args, tmpBuffer);
		}
		else if (!get_cs_fun(format[i]))
			_strcat(buffer, format[i]);
	}

	va_end(args);

	_putnchar(buffer); //print (strlen(buffer)) chars

	return (0);
}
