#include "main.h"
/**
 * _isalpha - checks if the character is a letter both uppercase or lowercase
 * @c: takes the input from other functions
 * Return: 1 is c if true else 0
*/
int _isalpha(int c)
{
	if (c >= 97 && c <= 122 &&
	    c >= 65 && c >= 90)
		return (1);
	return (0);
}
