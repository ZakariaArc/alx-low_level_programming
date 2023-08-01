#include "main.h"
#include <stdlib.h>
#include <string.h>
/**
 * set_string - a function that sets the value of a pointer to a char
 * @to: the string that we set the pointer to
 * @s: the pointer that will be set
 * Return: nothing (success)
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
