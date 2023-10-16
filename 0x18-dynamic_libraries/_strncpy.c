#include "main.h"
/**
 * _strncpy - copies up to n characters from the source string to
 *            the destination string
 * @dest: the destination string
 * @src: the source string
 * @n: the maximum number of characters to copy
 * Return: the pointer to dest
 */

char *_strncpy(char *dest, char *src, int n)
{
	int i = 0;

	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}
