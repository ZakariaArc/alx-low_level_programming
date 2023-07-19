#include "main.h"
/**
 * _isalpha - checks if the character is a letter lowercase or uppercase
 * @c: takes the input from other functions
 * Return: return 1 if c is a letter, else return 0
*/
int _isalpha(int c)
{
	if (c >= 97 && c <= 122 &&
	    c >= 65 && c >= 90)
		return (1);
	return (0);
}
