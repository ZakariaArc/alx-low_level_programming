#include "function_pointers.h"
#include <stdio.h>
/**
 * print_name - function that prints a name using a specified function
 * @name: name to be printed
 * @f: a pointer to the function used to print the name
 * Return: nothing
 */

void print_name(char *name, void (*f)(char *))
{
	if (name != NULL && f != NULL)
	{
		f(name);
	}
}
