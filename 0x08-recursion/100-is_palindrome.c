#include "main.h"
#include <string.h>
/**
 * is_palindrome_helper_function - helper function to check
 *                                 if the string is a palindrome
 * @s: the string to check if it's a palindrome
 * @start: the starting index of the string
 * @end: the ending index of the string
 * Return: if the string is palindrome return 1, if else return 0
 */

int is_palindrome_helper_function(char *s, int start, int end)
{
	if (start >= end)
		return (1);

	if (s[start] != s[end])
		return (0);
	return (is_palindrome_helper_function(s, start + 1, end - 1));
}

/**
 * is_palindrome - a function that returns 1 if the string is a
 *                 palindrome, otherwise returns 0
 * @s: the string to check if it's a palindrome
 * Return: if the string is palindrome return 1, if else return 0
 */

int is_palindrome(char *s)
{
	int len = strlen(s);

	return (is_palindrome_helper_function(s, 0, len - 1));
}
