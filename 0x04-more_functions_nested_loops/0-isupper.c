#include "main.h"
/**
 * _isupper - checks if c is uppercase
 * @c: the input for the alphabet
 * Return: 1 if c is uppercase, else 0
 */
int _isupper(int c)
{
	if (c >= 65 && c <= 90)
		return (1);
	else
		return (0);
}
