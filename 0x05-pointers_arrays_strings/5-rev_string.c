#include "main.h"
/**
  * rev_string - reverses a string
  * @s: string input
  * Return: nothing
  */

void rev_string(char *s)
{
	int a, i;
	char ch;

	for (a = 0; s[a] != '\0'; ++a)
		;
	for (i = 0; i < a / 2; ++i)
	{
		ch = s[i];
		s[i] = s[a - 1 - i];
		s[a - 1 - i] = ch;
	}
}
