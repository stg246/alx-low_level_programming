#include <stdlib.h>
#include "function_pointers.h"

/**
 * print_name - Prints a name.
 * @name: name to be printed.
 * @f: pointer to a function that prints a name.
 */
void print_name(char *name, void (*f)(char *))
{
	if (!name || !f)
		return;
	f(name);
}
