#include "main.h"
/**
 * print_sign - prints the sign of the number
 * @n: the int to check
 * Return: if + return 1, if 0 return 0, if - return -1
*/
int print_sign(int n)
{
	if (n > 0)
	{
		_putchar('+');
		return (1);
	} else if (n == 0)
	{
		_putchar(48);
		return (0);
	} else if (n < 0)
	{
		_putchar('-');
	}
		return (-1);
}
