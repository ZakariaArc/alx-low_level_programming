#include "main.h"
#include <stdlib.h>
/**
 * string_nconcat - concatenates 2 strings up to n bytes of the second string
 * @s1: first string
 * @s2: second string
 * @n: the maximum number of bytes from s2 to concatenate
 * Return: a pointer to the concatenated string, or NULL on failure
 */

char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	unsigned int len1 = 0, len2 = 0, i = 0;
	char *concatenated;

	if (s1 != NULL)
	{
		while (s1[len1] != '\0')
			len1++;
	}

	if (s2 != NULL)
	{
		while (s2[len2] != '\0')
			len2++;
	}

	if (n >= len2)
		n = len2;

	concatenated = malloc(sizeof(char) * (len1 + n + 1));

	if (concatenated == NULL)
		return (NULL);

	for (i = 0; i < len1; i++)
		concatenated[i] = s1[i];

	for (i = 0; i < n; i++)
		concatenated[len1 + i] = s2[i];

	concatenated[len1 + n] = '\0';

	return (concatenated);
}
