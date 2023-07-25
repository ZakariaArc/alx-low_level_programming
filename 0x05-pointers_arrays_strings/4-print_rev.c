#include "main.h"
/**
  * print_rev - prints a string in reverse
  * @s: the input string
  * Return: nothing
  */

void print_rev(char *s)
{
	int alpha;

	for (alpha = 0; s[alpha] != '\0'; ++alpha)
		;
	for (--alpha; alpha >= 0; --alpha)
		_putchar(s[alpha]);
	_putchar('\n');
}
