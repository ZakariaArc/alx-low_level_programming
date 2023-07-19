#include "main.h"

/**
* Description: print_alphabet - putchar function to the alphabets
*/
void print_alphabet(void)
{
	int ch;

	for (ch = 'a'; ch <= 'z'; ++ch)
		_putchar(ch);
	_putchar('\n');
}
