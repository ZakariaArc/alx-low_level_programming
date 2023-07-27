#include "main.h"
/**
  * _strncpy - a function that copies a string
  * @src: source input
  * @dest: destination input
  * @n: the number of byte
  * Return: a pointer to the resulting @dest
 */

char *_strncpy(char *dest, char *src, int n)
{
	int a;

	a = 0;
	while (src[a] != '\0' && n > a)
	{
		dest[a] = src[a];
		a++;
	}
	while (n > a)
	{
		dest[a] = '\0';
		a++;
	}
	return (dest);
}
