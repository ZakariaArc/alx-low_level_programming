#include "main.h"
#include <stdlib.h>
/**
 * str_concat - concatenates two strings
 * @s1: 1st string
 * @s2: 2nd string
 * Return: on success, a pointer to the concatenated string,
 *         NULL, on failure
 */

char *str_concat(char *s1, char *s2)
{
	char *concatenated;
	unsigned int len1 = 0, len2 = 0, i, j;

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
	concatenated = (char *)malloc((len1 + len2 + 1) * sizeof(char));
	if (concatenated == NULL)
	return (NULL);

	for (i = 0; i < len1; i++)
		concatenated[i] = s1[i];

	for (j = 0; j < len2; j++)
		concatenated[i + j] = s2[j];

	concatenated[i + j] = '\0';

	return (concatenated);
}
