About _PRINTF
_printf is a variadic function thats prints a string according to a format.  This function can take many arguments.

       On success, _printf prints a string,
       or returns -1 if the string FORMAT is empty or if any errors occurs.

OPTIONS
       Format can contain conversion specifier. These starts with '%' and are followed by :

       - d : convert a decimal number

       - i : convert a decimal number

       - c : print a char

       - s : print a string

       - r : print a string in reverse

       - R : convert a string in ROT13 encryption

NOTES
       _printf use a character printing function called _putnchar, that use the system write function.

BUGS
       Many bugs for the moment. Function not working as we want. Also valgrind memory leak issues.

AUTHOR
       Octave Collombel and Etienne Brun for HolbertonSchool project.
