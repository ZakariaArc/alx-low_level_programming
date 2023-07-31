#include "main.h"
/**
 * *_strspn - a function that gets the length of a prefix substring
 * @s: string input
 * @accept: contains the list of characters to match in @s
 * Return: the number of bytes in the initial segment of s
 *         which consist only of bytes from accept
 */

unsigned int _strspn(char *s, char *accept)
{
	int i, j, f;

	f = 0;

	for (i = 0; s[i] != '\0'; i++)
	{
		for (j = 0; accept[j] != '\0'; j++)
		{
			if (s[i] == accept[j])
			{
				f++;
				break;
			}
		}
		if (accept[j] == '\0')
			break;
	}

	return (f);
}
