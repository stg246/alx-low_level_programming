#include "main.h"

/**
 * _puts - prints a string to stdout.
 * @st: The string to be printed.
 */
void _puts(char *st)
{
	while (*st)
		_putchar(*st++);

	_putchar('\n');
}
