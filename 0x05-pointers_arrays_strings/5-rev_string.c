#include "main.h"
/**
  * rev_string - reverses a string
  * @s: string input
  * Return: nothing
  */

void rev_string(char *s)
{
	int a, b;
	char c;

	for (a = 0; s[a] != '\0'; ++a)
		;
	for (b = 0; b < 1 / 2; ++b)
	{
		c = s[b];
		s[b] = s[a - 1 - b];
		s[a - 1 - b] = c;
	}
}
