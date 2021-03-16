#include "holberton.h"
#include <stdlib.h>

/**
 * _printf - Produces output according to a format.
 * @format: Character string that tells us what to do
 *
 * Return: Either 0 or a count of the number of characers printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int itep = 0, count = 0;
	char *buffer;
	char finalBuffer[1024], p[2];

	if (format == NULL || (format[0] == '%' && format[1] == '\0') ||
	    format[0] == '\0')
		return (-1);
	va_start(args, format);
	finalBuffer[0] = '\0';
	for (itep = 0; format[itep] != '\0'; itep++)
	{
		if (format[itep] == '%' && format[itep + 1] == '%')
		{
			itep++;
			p[0] = format[itep], p[1] = '\0';
			_strcat(finalBuffer, p);
			itep++;
		}
		if (format[itep] == '%' && format[itep + 1] != '\0')
		{
			itep++;
			buffer = format_handler(p, format, args, itep);
			if (buffer == NULL)
				return (-1);
			while (get_cs_func(format[itep]) == NULL && format[itep] != '\0')
				itep++;
			_catbuf(finalBuffer, buffer);
			free(buffer);
		}
		else
		{
			p[0] = format[itep];
			p[1] = '\0';
			_strcat(finalBuffer, p);
		}
	}
	va_end(args);
	count = _putnchar(finalBuffer);
	return (count);
}

/**
 * format_handler - handles the format
 * @p: current character of format
 * @format: Character string that tells us what to do
 * @args: current va_list
 * @itep: current spot in our iteration
 *
 * Return: Either 0 or -1
 */
char *format_handler(char p[], const char *format, va_list args, int itep)
{
	char *tmpBuffer, *buffer;
	char *(*pfunc)(va_list, char *);

	tmpBuffer = _calloc(20, sizeof(char));
	if (tmpBuffer == NULL)
		return (NULL);

	buffer = _calloc(50, sizeof(char));
	if (buffer == NULL)
		return (NULL);

	while (get_cs_func(format[itep]) == NULL && format[itep] != '\0')
	{
		p[0] = format[itep];
		p[1] = '\0';
		_strcat(tmpBuffer, p);
		itep++;
	}
	if (format[itep] == '\0')
	{
		_strcat(buffer, tmpBuffer);
		free(tmpBuffer);
	}
	else if (get_cs_func(format[itep]) != NULL)
	{
		pfunc = get_cs_func(format[itep]);

		p[0] = format[itep];
		p[1] = '\0';
		_strcat(tmpBuffer, p);
		buffer = pfunc(args, tmpBuffer);
		free(tmpBuffer);

	}
	return (buffer);
}
