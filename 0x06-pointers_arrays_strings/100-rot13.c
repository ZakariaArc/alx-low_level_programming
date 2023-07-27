#include <stdio.h>
#include "main.h"
/**
 * rot13 - function that encodes a string using rot13
 * @c: input char
 * Return: the input char @c
 */

char *rot13(char *c)
{
	char a[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char b[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	for (int i = 0; c[i] != '\0'; i++)
	{
		char *ptr_a = a;
		char *ptr_b = b;
		char *ptr = NULL;

		while (*ptr_a != '\0')
		{
			if (*ptr_a == c[i])
			{
				ptr = ptr_b;
				break;
			}
			ptr_a++;
			ptr_b++;
		}
		if (ptr)
		{
			c[i] = *ptr;
		}
	}
	return (c);
}
