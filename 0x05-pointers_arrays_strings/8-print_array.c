#include "main.h"
/**
  * print_array - prints n elements of an array
  * of integers
  * @a: string input
  * @n: elements to print
  * Return: nothing
  */

void print_array(int *a, int n)
{
	int b;

	for (b = 0; b < n; ++b)
	{
		if (b != (n - 1))
			printf("%d, ", a[b]);
		else
			printf("%d", a[b]);
	}
	printf("\n");
}
