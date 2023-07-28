#include "main.h"
/**
 * print_number - function that prints an integer
 * @n: the printed integer
 */

void print_number(int n)
{
	unsigned int n1;

	if (n < 0)
	{
		_putchar('-');
		n1 = -n;
	}
	else
	{
		n1 = n;
	}

	{
		unsigned int divisor = 1;
		unsigned int temp = n1;

		while (temp / 10 != 0)
		{
			divisor *= 10;
			temp /= 10;
		}
		while (divisor != 0)
		{
			int digit = n1 / divisor;
			_putchar(digit + '0');
			n1 -= (digit * divisor);
			divisor /= 10;
		}
	}
}
