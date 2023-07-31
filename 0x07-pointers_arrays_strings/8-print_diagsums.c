#include "main.h"
#include <stdio.h>
/**
 * print_diagsums - function that prints the sum of the two
 *                  diagonals of a square matrix of integers
 * @size: the size of the matrix
 * @a: the input pointer
 * Return: nothing (success)
 */

void print_diagsums(int *a, int size)
{
	int i, sum_primary = 0, sum_secondary = 0;

	for (i = 0; i < size; i++)
	{
		sum_primary += a[i * size + i];
		sum_secondary += a[(i + 1) * (size - 1)];
	}

	printf("%d, %d\n", sum_primary, sum_secondary);
}
