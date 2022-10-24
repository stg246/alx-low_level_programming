#include "main.h"

/**
 * puts2 - prints one char out of two of a string.
 * @s: string containing characters.
 */
void puts2(char *s)
{
	int i = 0, len = 0;

	while (s[i++])
		len++;

	for (i = 0; i < len; i += 2)
		_putchar(s[i]);

	_putchar('\n');
}
