#include "main.h"
/**
 * _strspn - gets the length of a prefix substring
 * @s: the initial segment
 * @accept: the string containing the characters to match
 * Return: the number of bytes in the initial segment of s which consist
 *         only of bytes from accept
 */

unsigned int _strspn(char *s, char *accept)
{
	unsigned int i = 0;
	int j;
	int found;

	while (s[i] != '\0')
	{
		j = 0;
		found = 0;
		while (accept[j] != '\0')
		{
			if (accept[j] == s[i])
			{
				found = 1;
				break;
			}
			j++;
		}
		if (found == 0)
			break;
		i++;
	}
	return (i);
}
