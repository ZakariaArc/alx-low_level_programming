#include "main.h"
/**
 * leet - function that encodes a string into 1337
 * @c: input char
 * Return: the input char @c
 */

char *leet(char *c)
{
	int a, b;

	char d[] = "aAeEoOtTlL";
	char e[] = "4433007711";

	for (a = 0; c[a] != '\0'; a++)
	{
		for (b = 0; b < 10; b++)
		{
			if (c[a] == d[b])
			{
				c[a] = e[b];
				break;
			}
		}
	}
	return (c);
}
