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
	char *(*pfunc)(va_list, char *);
	int i;
	char *tmpBuffer;
	char *buffer;
	char finalBuffer[1024];
	char *p;

	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);

	va_start(args, format);

	p = malloc(sizeof(char) * 2);
	finalBuffer[0] = '\0';
/*	finalBuffer = malloc(sizeof(char) * 1024); */
/*	printf("test_%s_final_buffer", finalBuffer); */
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
				/*	printf("%s_tmpbuffer\n", tmpBuffer); */
				free(tmpBuffer);

				_catbuf(finalBuffer, buffer);
				free(buffer);
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

/*	printf("test_%s_p\n", p); */
/*	printf("test_%s_finalBuffer\n", finalBuffer); */
	_putnchar(finalBuffer); //print (strlen(buffer)) chars
/*	free(finalBuffer); */
	free(p);
	return (0);
}
