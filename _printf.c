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
	int i, count = 0;
	char *buffer;
	char finalBuffer[1024], p[2];

	if (format == NULL || (format[0] == '%' && format[1] == '\0') || format[0] == '\0')
		return (-1);

	va_start(args, format);

	finalBuffer[0] = '\0';

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%' && format[i + 1] == '%')
		{
			i++;
			p[0] = format[i];
			p[1] = '\0';
			_strcat(finalBuffer, p);
			i++;
		}
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			i++;
			buffer = format_handler(p, format, args, i);
			_catbuf(finalBuffer, buffer);
			free(buffer);
		}
		else
		{
			p[0] = format[i];
			p[1] = '\0';
			_strcat(finalBuffer, p);
		}
	}
	va_end(args);
	count = _putnchar(finalBuffer); /*print (strlen(buffer)) chars*/
	return (count);
}

/**
 * format_handler - handles the format
 * @format: Character string that tells us what to do
 *
 * Return: Either 0 or -1
 */
char *format_handler(char p[], const char *format, va_list args, int i)
{
	char *tmpBuffer, *buffer;
	char *(*pfunc)(va_list, char *);

	tmpBuffer = malloc(sizeof(char) * 20);
	if (tmpBuffer == NULL)
		return (NULL);

	buffer = malloc(sizeof(char) * 50);
	if (buffer == NULL)
		return (NULL);

	while (get_cs_func(format[i]) == NULL && format[i] != '\0')
	{
		p[0] = format[i];
		p[1] = '\0';
		_strcat(tmpBuffer, p);
		i++;
	}
	if (format[i] == '\0')
	{
		_strcat(buffer, tmpBuffer);
		free(tmpBuffer);
	}
	else if (get_cs_func(format[i]) != NULL)
	{
		pfunc = get_cs_func(format[i]);

		p[0] = format[i];
		p[1] = '\0';
		_strcat(tmpBuffer, p);
/*		buffer = malloc(sizeof(char) * 50);
		if (buffer == NULL)
		return (-1); */

		buffer = pfunc(args, tmpBuffer);
		free(tmpBuffer);

	}
	return (buffer);
}
