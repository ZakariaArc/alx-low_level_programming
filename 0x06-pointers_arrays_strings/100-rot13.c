#include "main.h"
/**
 * rot13 - function that encodes a string using rot13
 * @c: input char
 * Return: the input char @c
 */

char *rot13(char *c)
{
	int a;

	char a[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char b[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	for (a = 0; c[a] != '\0'; a++)
	{
		for (int j = 0; a[j] != '\0'; j++)
		{
			if (c[a] == a[j])
			{
				c[a] = b[j];
				break;
			}
		}
	}
	return (c);
}
