#include "main.h"
/**
 * _isalpha - checks if the character is a letter both uppercase or lowercase
 * @c: takes the input from other functions
 * Return: 1 if c is a letter; else 0
*/
int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}
