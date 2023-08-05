#include <stdio.h>
#include "main.h"
/**
 * *_strchr - a function that locates a character in a string
 * @s: the string to search
 * @c: the char to locate
 * Return: pointer to the first occurrence of the character c,
 *         NULL if the character is not found
 */

char *_strchr(char *s, char c)
{
	while (*s != '\0')
	{
		if (*s == c)
			return (s);
		s++;
	}
	{
		if (*s == c)
			return (s);
	}
	return (NULL);
}
