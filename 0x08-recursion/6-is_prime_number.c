#include "main.h"
/**
 * is_prime_helper_function - helper function to check
 *                            if the number is prime
 * @n: the number to check if it's prime
 * @divisor: the current divisor to check for primality
 * Return: if number is prime return 1, if else return 0
 */

int is_prime_helper_function(int n, int divisor)
{
	if (n < 2)
		return (0);
	if (n == divisor)
		return (1);
	if (n % divisor == 0)
		return (0);
	else
		return (is_prime_helper_function(n, divisor + 1));
}

/**
 * is_prime_number -  a function that returns 1 if the
 *                    input integer is a prime number,
 *                    otherwise return 0.
 * @n: the number to check if it's prime
 * Return: if number is prime return 1, if else return 0
 */

int is_prime_number(int n)
{
	return (is_prime_helper_function(n, 2));
}
