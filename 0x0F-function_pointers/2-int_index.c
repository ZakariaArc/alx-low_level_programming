#include "function_pointers.h"
/**
 * int_index - function that searches for an integer in an array
 * @array: the array of integers
 * @size: the size of the array
 * @cmp: a pointer to the function to compare values
 * Return: the index of the first element for which cmp function does
 *         not return 0, or -1 if no element matches or size <= 0
 */

int int_index(int *array, int size, int (*cmp)(int))
{
	int i;

	if (array != NULL && cmp != NULL && size > 0)
	{
		for (i = 0; i < size; i++)
		{
			if (cmp(array[i]) != 0)
			{
				return (i);
			}
		}
	}
	return (-1);
}
