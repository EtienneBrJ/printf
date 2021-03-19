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
	int total = 0, itep = 0;
	char *buffer;
	char finalBuffer[BUFFER_SIZE], p[2];

	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);
	va_start(args, format);
	finalBuffer[0] = '\0';
	while (format[itep] != '\0')
	{
		if (format[itep] == '%' && format[itep + 1] == '%')
		{
			itep++, p[0] = format[itep], p[1] = '\0';
			total += empty_buffer(finalBuffer, p, total);
		}
		else if (format[itep] == '%' && format[itep + 1] != '\0')
		{
			itep++;
			buffer = format_handler(p, format, args, &itep);
			total += empty_buffer(finalBuffer, buffer, total);
			free(buffer);
			if (format[itep] == '\0')
				itep--;
		}
		else
		{
			p[0] = format[itep], p[1] = '\0';
			total += empty_buffer(finalBuffer, p, total);
		}
		itep++;
	}
	va_end(args);
	total += _putnchar(finalBuffer);
	return (total);
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
char *format_handler(char p[], const char *format, va_list args, int *itep)
{
	char *tmpBuffer, *buffer, *per_string, *temp;
	char *(*pfunc)(va_list, char *);

	per_string = _calloc(20, sizeof(char));
	per_string[0] = '%';

	tmpBuffer = _calloc(20, sizeof(char));
	if (tmpBuffer == NULL)
		return (NULL);

	buffer = _calloc(50, sizeof(char));
	if (buffer == NULL)
		return (NULL);

	while (get_cs_func(format[*itep]) == NULL && format[*itep] != '\0')
	{
		p[0] = format[(*itep)];
		p[1] = '\0';
		_strcat(tmpBuffer, p);
		(*itep)++;
	}
	if (format[*itep] == '\0')
	{
		_strcat(per_string, tmpBuffer);
		_strcat(buffer, per_string);
		free(tmpBuffer);
	}
	else if (get_cs_func(format[(*itep)]) != NULL)
	{
		pfunc = get_cs_func(format[(*itep)]);
		p[0] = format[(*itep)];
		p[1] = '\0';
		_strcat(tmpBuffer, p);
		temp = pfunc(args, tmpBuffer);
		_catbuf(buffer, temp);
		free(temp);
		free(tmpBuffer);
	}
	free(per_string);
	return (buffer);
}
