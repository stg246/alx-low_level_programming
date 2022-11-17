#include "function_pointers.h"

/**
 * int_index - Searches for an integer
 * @array: array of integers.
 * @size: size of the array.
 * @cmp: pointer to the function to be used to compare values.
 *
 * Return: If no element matches or size <= 0 - -1.
 * Otherwise - The index of the first element for which
 * the cmp function does not return 0.
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int i;

	if (array && cmp)
	{
		for (i = 0; i < size; i++)
		{
			if (cmp(array[i] != 0)
				return (i);
		}
	}
	return (-1);
}
