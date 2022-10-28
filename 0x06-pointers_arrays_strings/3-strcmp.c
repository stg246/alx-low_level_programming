#include "main.h"

/**
 * _strcmp - compares two strings.
 * @s1: Afirst string to be compared.
 * @s2: second string to be compared.
 *
 * Return: If str1 < str2, the negative difference of the first characters
 *         If str1 == str2, 0.
 *         If str1 > str2, the positive difference of the first characters
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}

	return (*s1 - *s2);
}
