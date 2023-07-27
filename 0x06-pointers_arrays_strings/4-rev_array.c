#include "main.h"
/**
  * reverse_array - function that reverses the content of an array of integers
  * @a: the array to be reversed
  * @n: the numbers of elements in the array
  * Return: nothing (success)
  */

void reverse_array(int *a, int n)
{
	int start, end, temp;

	for (start = 0, end = n - 1; start < n / 2; start++, end--)
	{
		temp = a[start];
		a[start] = a[end];
		a[end] = temp;
	}
}
