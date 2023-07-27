#include "main.h"
/**
  * _strcat - a function that concantenates two strings
  * @src: source input
  * @dest: destination input
  * @n: the number of bytes
  * Return: a pointer to the resulting @dest
  */

char *_strncat(char *dest, char *src, int n)
{
	int a, b;

	a = 0;
	b = 0;
	while (dest[a] != '\0')
		a++;
	while (src[b] != '\0' && n > b)
	{
		dest[a] = src[b];
		a++;
		b++;
	}
	dest[a] = '\0';
	return (dest);
}
