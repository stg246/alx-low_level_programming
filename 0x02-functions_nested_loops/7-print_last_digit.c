#include "main.h"
/**
 * print_last_digit - a function that prints the last digit of a number
 * @n: number's last digit result
 * Return: value of the last digit
 */
int print_last_digit(int n)
{
	int pld;

	pld = (n % 10);

	if (pld < 0)
	{
		pld = (-1 * pld);
	}

	_putchar(pld + '0');
	return (pld);
}
