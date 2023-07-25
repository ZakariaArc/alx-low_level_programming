#include "main.h"
/**
  * puts2 - prints every other charater of a string
  * @str: string input
  * Return: nothing
  */

void puts2(char *str)
{
	int a;

	for (a = 0; str[a] != '\0'; ++a)
	{
		if (a % 2 == 0)
			_putchar(str[a]);
	}
	_putchar('\n');
}
