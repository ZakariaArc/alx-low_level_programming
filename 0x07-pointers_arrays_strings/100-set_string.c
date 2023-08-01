#include "main.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
/**
 * set_string - a function that sets the value of a pointer to a char
 * @to: the string that we set the pointer to
 * @s: the pointer that will be set
 * Return: 1 if successful, 0 if memory allocation failed
 */

void set_string(char **s, char *to)
{
	*s = (char *)malloc(strlen(to) + 1);

	if (*s != NULL)
	{
		strcpy(*s, to);
	}
	else
	{
		return (0);
	}
}
