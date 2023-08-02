#include "main.h"
#include <stdio.h>
/**
 * _puts_recursion - a function that prints a new line
 * @s: the string to print
 * Return: nothing (success)
*/

void _puts_recursion(char *s)
{
	if (*s == '\0')
	{
		putchar('\n');
		return;
	}
	_putchar(*s);
	_puts_recursion(s + 1);
}
