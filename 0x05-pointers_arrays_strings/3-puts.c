#include "main.h"
/**
  * _puts - prints a string followed by a newline
  * @str: pointer to the string to print
  * Return: nothing
  */

void _puts(char *str)
{
	char *current = str;

	while (*current != '\0')
	{
		_putchar(*current);
		current++;
	}
	_putchar('\n');
}
