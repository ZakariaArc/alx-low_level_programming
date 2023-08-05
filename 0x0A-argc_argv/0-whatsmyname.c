#include "main.h"
#include <stdio.h>

/**
  * main - program that prints its name, followed by a new line
  * @argc: the number of arguments
  * @argv: the array of arguments
  * Return: 0 (success)
  */

int main(int argc, char *argv[])
{
	(void)argc;

	printf("%s\n", argv[0]);
	return (0);
}
