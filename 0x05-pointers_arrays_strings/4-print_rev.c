#include "main.h"
/**
  * print_rev - prints a string in reverse
  *@s: the input string
  * Return: nothing
  */

void print_rev(char *s)
{
	if (s == NULL)
		return;

	int length = 0;
	int i;

	while (s[length] != '\0')
		length++;

	for (i = length - 1; i >= 0; i--)
		-putchar(s[i]);

	_putchar('\n');
}
