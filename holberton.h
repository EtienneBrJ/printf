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
        char *(*func)(va_list args, char *b);
} print_t;

int _printf(const char *format, ...);

char *(*get_cs_func(char c))(va_list, char *);

int _putchar(char c);

int _putnchar(char buffer[]);

char *_strcat(char *dest, char *src);

char *print_int(va_list args, char *flagstr);

char *flags_handler(char *flags, char *oristring, int is_negative);

int _atoi(char *s);

void rev_string(char *s);

char *rot13(char *s);

int _catbuf(char dest[], char *src);

#endif
