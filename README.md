# _PRINTF

**Duration of the project: 4 days in duo.**
**Compile with Weverything**

_printf is a mimic of the function *printf* from the *<stdlib.h>*.
Our function uses a **buffer** in order to call *write* as little as possible.
The function also handles field-width and precision.

	     On success, _printf print a **string**,
       	     or Return -1 if the string **FORMAT** is empty or if any errors occurs.

## OPTIONS
       Format can contain conversion specifier. These starts with '%' and are followed by :

       - d : convert a decimal number

       - i : convert a decimal number

       - c : print a char

       - s : print a string

       - r : print a string in reverse

       - R : convert a string in ROT13 encryption

       - B : convert a decimal number in binary

### Exemple

_printf("%s School\n", "Holberton");
_printf("%r\n", "4days");
_printf("%R\n", "Cisfun?");
_printf("%b\n", 12);
_printf("%05d\n", 150);

will print

Holberton School
syad4
Pvfsha?
1100
00150

#### *with [Etienne](https://github.com/EtienneBrJ "GitHub") for Holberton.*
