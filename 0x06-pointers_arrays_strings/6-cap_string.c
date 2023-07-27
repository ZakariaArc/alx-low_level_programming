#include "main.h"
/**
 * cap_string - function that capitalizes all words of a string
 * @c: input char
 * Return: the input char @c
 */

char *cap_string(char *c)
{
	int b;

	if (c[0] >= 'a' && c[0] <= 'z')
		c[0] -= 32;
	for (b = 1; c[b] != '\0'; b++)
	{
		if (c[b] == ' ' || c[b] == '\t' || c[b] == '\n' || c[b] == ',' ||
				c[b] == ';' || c[b] == '.' || c[b] == '!' ||
				c[b] == '?' || c[b] == '"' || c[b] == '(' ||
				c[b] == ')' || c[b] == '{' || c[b] == '}')
		{
			if (c[b + 1] >= 'a' && c[b + 1] <= 'z')
				c[b + 1] -= 32;
		}
	}
	return (c);
}
