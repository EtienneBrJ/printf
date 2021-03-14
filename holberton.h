#ifndef PRINT_H
#define PRINT_H

#include <stdarg.h>
#include <unistd.h>

/**
 * struct print - struct containing flag and a pointer
 * to the corresponding function
 *
 * @m: main_flag (format specifier)
 *
 * @func: pointer to the function
 */

typedef struct print
{
	char *m;
	int (*func)(va_list args, char *b);
} print_t;


int _printf(const char *format, ...);

int (*get_cs_func(char c))(va_list args, char *b);

int _putchar(char c);

char *_strcat(char *dest, char *src);
#endif
