#include "main.h"
/**
 * *_memcpy - a function that copies memory area
 * @n: the number of bytes to copy
 * @src: where to copy from
 * @dest: destination where to copy to
 * Return: pointer to dest (success)
 */

char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		dest[i] = src[i];

	return (dest);
}
