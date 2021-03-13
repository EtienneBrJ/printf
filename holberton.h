#ifndef PRINT_H
#define PRINT_H

typedef struct print
{
	char *m;
	int (*func)(va_list);
} print_t

int _putchar(char c);
int _printf(const char *format, ...);
#endif
