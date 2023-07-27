#include "main.h"
/**
 * string_toupper -  function that changes all lowercase
 * letters of a string to uppercase
 * @c: input char
 * Return: the input char @c
 */

char *string_toupper(char *c)
{
	int n;

	for (n = 0; c[n] != '\0'; n++)
	{
		if (c[n] >= 'a' && c[n] <= 'z')
			c[n] = c[n] - ('a' - 'A');
	}
	return (c);
}
