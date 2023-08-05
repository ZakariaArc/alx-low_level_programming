#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * is_number_positive - checks if a string is a positive number
 * @s: the string to check
 * Return: if the number is positive return 1, if not return 0
 */
int is_number_positive(char *s)
{
	if (*s == '\0')
	return (0);

	while (*s != '\0')
	{
		if (*s < '0' || *s > '9')
		return (0);
		s++;
	}
	return (1);
}

/**
  * main - program that adds positive numbers
  * @argc: the number of arguments
  * @argv: the array of arguments
  * Return: 0 (success)
  */

int main(int argc, char *argv[])
{
	int sum = 0;
	int i;

	if (argc == 1)
	{
		printf("0\n");
		return (0);
	}
	for (i = 1; i < argc; i++)
	{
		if (!is_number_positive(argv[i]))
		{
			printf("Error\n");
			return (1);
		}
	sum += atoi(argv[i]);
	}
	printf("%d\n", sum);
	return (0);
}
