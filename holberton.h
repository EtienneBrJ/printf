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

char *flags_handler(char *flags, char *oristring, int is_negative);

/* prints functions */

int _putchar(char c);
int _putnchar(char buffer[]);

/* return char * for buffer functions */

char *print_int(va_list args, char *flagstr);
char *print_string(va_list args, char *flagstr);
char *print_char(va_list args, char *flagstr);

/* Convert functions */

int _atoi(char *s);
char *rot13(char *s);
void rev_string(char *s);

/* cat functions */

int _catbuf(char dest[], char *src);
char *_strcat(char *dest, char *src);

#endif
