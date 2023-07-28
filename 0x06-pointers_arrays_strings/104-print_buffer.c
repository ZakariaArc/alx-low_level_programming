#include <stdio.h>
#include "main.h"
/**
 * print_buffer - prints the buffer
 * @b: the buffer
 * @size: the size
 * Return: 0 (success)
 */

void print_buffer(char *b, int size)
{
	int m, n, p;

	m = 0;
	if (size <= 0)
	{
		printf("\n");
		return;
	}
	while (m < size)
	{
		n = size - m < 10 ? size - m : 10;
		printf("%08x: ", m);
		for (p = 0; p < 10; p++)
		{
			if (p < n)
				printf("%02x", *(b + m + p));
			else
				printf("  ");
			if (p % 2)
			{
				printf(" ");
			}
		}
		for (p = 0; p < n; p++)
		{
			int c = *(b + m + p);

			if (c < 32 || c > 132)
			{
				c = '.';
			}
			printf("%c", c);
		}
		printf("\n");
		m += 10;
	}
}

