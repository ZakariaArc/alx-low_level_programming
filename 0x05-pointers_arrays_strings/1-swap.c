#include "main.h"
/**
  * swap_int - swapes the values of two integers
  * @a: first value
  * @b: second value
  * Return: nothing
  */

void swap_int(int *a, int *b)
{
	int s;

	s = *a;
	*a = *b;
	*b = s;
}
