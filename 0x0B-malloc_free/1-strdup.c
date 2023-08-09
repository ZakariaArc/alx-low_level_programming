#include "main.h"
#include <stdlib.h>
/**
 * _strdup - returns a pointer to a newly allocated space in memory,
 *           containing a copy of the string given as a parameter
 * @str: the input string to be duplicated.
 * Return: on success, a pointer to the duplicated string,
 *         NULL on failure
 */

char *_strdup(char *str)
{
	char *duplicate;
	unsigned int length = 0, i;

	if (str == NULL)
		return (NULL);

	while (str[length] != '\0')
	length++;

	duplicate = (char *)malloc((length + 1) * sizeof(char));
	if (duplicate == NULL)
		return (NULL);

	for (i = 0; i <= length; i++)
	duplicate[i] = str[i];

	return (duplicate);
}
