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
	char *(*pfunc)(va_list, char *);
	int i;
	char tmpBuffer[20];
	char *buffer;
	char p[10];

	va_start(args, format);

	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%' && format[i + 1] == '%')
		{
			i++;
			p[0] = format[i];
       			p[1] = '\0';
			_strcat(tmpBuffer, p);
			i++;
		}
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			while(get_cs_func(format[i]) == NULL && format[i] != '\0')
			{
				p[0] = format[i];
				p[1] = '\0';
				_strcat(tmpBuffer, p);
				i++;
			}
			if (format[i] == '\0')
				_strcat(buffer, tmpBuffer);
			else if (get_cs_func(format[i]))
			{
				pfunc = get_cs_func(format[i]);
				p[0] = format[i];
				p[1] = '\0';
				_strcat(tmpBuffer, p);
				buffer = pfunc(args, tmpBuffer);
			}
		}
		else
		{
			p[0] = format[i];
			p[1] = '\0';
			_strcat(buffer, p);
		}
	}

	va_end(args);

	_putnchar(buffer); //print (strlen(buffer)) chars

	return (0);
}
