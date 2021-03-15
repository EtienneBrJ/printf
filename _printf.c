#include "holberton.h"
#include <stdlib.h>
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
<<<<<<< HEAD
	register int buffer;
	char *tmpBuffer;
	char *p;
=======
	char *tmpBuffer;
	char *buffer;
	char *finalBuffer;
	char p[2];
>>>>>>> 11b72a11bf3f6b20bb39246ab63261f9a5823762

	va_start(args, format);

	finalBuffer = malloc(sizeof(char) * 1024);

	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);

	for (i = 0; format[i] != '\0'; i++)
	{
		tmpBuffer = malloc(sizeof(char) * 20);
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
<<<<<<< HEAD
				_strcat(buffer, tmpBuffer);
			else if (get_cs_func(format[i]) != NULL)
			{
				*p = format[i];
				printf("%c", format[i]);
				pfunc = get_cs_func(format[i]);
				_strcat(tmpBuffer, p);
			        pfunc(args, tmpBuffer);
=======
			{
				_strcat(finalBuffer, tmpBuffer);
				free(tmpBuffer);
			}
			else if (get_cs_func(format[i]) != NULL)
			{
				pfunc = get_cs_func(format[i]);

				p[0] = format[i];
				p[1] = '\0';
				_strcat(tmpBuffer, p);

				buffer = malloc(sizeof(char) * 50);
				buffer = pfunc(args, tmpBuffer);
				free(tmpBuffer);
				_strcat(finalBuffer, buffer);
				free(buffer);
>>>>>>> 11b72a11bf3f6b20bb39246ab63261f9a5823762
			}
		}
		else
		{
			p[0] = format[i];
			p[1] = '\0';
			_strcat(finalBuffer, p);
		}
	}

	va_end(args);

<<<<<<< HEAD
=======
	_putnchar(finalBuffer); //print (strlen(buffer)) chars
/*	free(finalBuffer); */
>>>>>>> 11b72a11bf3f6b20bb39246ab63261f9a5823762
	return (0);
}
