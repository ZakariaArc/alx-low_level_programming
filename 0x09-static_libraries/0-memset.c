#include "main.h"
/**
 * *_memset - a function that fills memory with a constant byte
 * @n: the number of times to copy b
 * @b: the char to copy
 * @s: the memory area to be filled
 * Return: pointer to the memory area @s
 */

char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = b;

	return (s);
}
