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

#define BUFFER_SIZE 1024

typedef struct print
{
	char *m;
	char *(*func)(va_list args, char *b);
} print_t;

int _printf(const char *format, ...);

char *(*get_cs_func(char c))(va_list, char *);

char *flags_handler(char *flags, char *oristring, int is_negative);
char *_addchar(char *dest, char c);
char *_calloc(unsigned int nmemb, unsigned int size);

/* prints functions */

int _putchar(char c);
int _putnchar(char buffer[]);
char *format_handler(char p[], const char *format, va_list args, int itep);

/* return char * for buffer functions */

char *print_int(va_list args, char *flagstr);
char *print_string(va_list args, char *flagstr);
char *print_char(va_list args, char *flagstr);

/* special flags handlers */
int handles_zeros(int itef, char *flags);
int handles_padding(int itef, char *flags);
char *final_string_generator(char *oristring, int flagstr[], int is_negative);

/* Convert functions */

int _atoi(char *s);

char *rot13(va_list args, __attribute__((unused))char *flagstr);
char *rev_string(va_list args, __attribute__((unused))char *flagstr);


/* cat functions */

int _catbuf(char dest[], char *src);
char *_strcat(char *dest, char *src);

#endif
