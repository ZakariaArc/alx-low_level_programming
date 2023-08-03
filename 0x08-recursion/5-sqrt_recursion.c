#include "main.h"
/**
 * _sqrt_helper_function - Helper function to calculate
 *                         the square root recursively
 * @n: the number to find the square root of
 * @guess: the current guess for the square root
 * Return: If n does not have a natural square root, return -1
*/

int _sqrt_helper_function(int n, int guess)
{
	if (guess * guess == n)
		return (guess);
	else if (guess * guess > n)
		return (-1);
	else
		return (_sqrt_helper_function(n, guess + 1));
}

/**
 * _sqrt_recursion - a function that returns the natural
 *                   square root of a number
 * @n: the number to find the square root of
 * Return: If n does not have a natural square root, return -1
 */

int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);
	else
		return (_sqrt_helper_function(n, 1));
}
