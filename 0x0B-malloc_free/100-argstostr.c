#include "main.h"
#include <stdlib.h>
/**
 * argstostr - concatenates all the arguments of the program
 * @ac: argument count
 * @av: array of pointers to the arguments
 * Return: a pointer to the concatenated string, or NULL if it fails
 */

char *argstostr(int ac, char **av)
{
	int i, j, len = 0, total_len = 0;
	char *str;

	if (ac <= 0 || av == NULL)
		return (NULL);

	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j] != '\0'; j++)
			len++;
		total_len += len;
		len = 0;
	}
	str = malloc(sizeof(char) * total_len);
	if (str == NULL)
		return (NULL);
	total_len = 0;
	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j] != '\0'; j++)
		{
			str[total_len] = av[i][j];
			total_len++;
		}
		str[total_len] = '\n';
		total_len++;
	}
	str[total_len] = '\0';
	return (str);
}
