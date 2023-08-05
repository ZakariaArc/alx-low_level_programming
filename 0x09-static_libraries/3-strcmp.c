#include "main.h"
/**
  * _strcmp -  a function that compares two strings.
  * @strng1: 1st string
  * @strng2: 2nd string
  * Return: less than 0 if strng1 is less then strng2,
  * 0 if they are equal, more than 0 if strng1 is greater
  * than strng2
  */

int _strcmp(char *strng1, char *strng2)
{
	while (*strng1 == *strng2)
	{
		if (*strng1 == '\0')
		{
			return (0);
		}
		strng2++;
		strng1++;
	}
	return (*strng1 - *strng2);
}
