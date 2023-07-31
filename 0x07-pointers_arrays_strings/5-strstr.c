#include "main.h"
/**
 * *_strstr - a function that locates a substring
 * @needle: the substring to search for
 * @haystack: the string to search in
 * Return: pointer to the beginning of the located substring,
 *         or NULL if the substring is not found
 */

char *_strstr(char *haystack, char *needle)
{
	char *h, *n;

	while (*haystack != '\0')
	{
		h = haystack;
		n = needle;
		while (*n != '\0' && *haystack == *n)
		{
			haystack++;
			n++;
		}
		if (*n == '\0')
			return (h);
		haystack++;
	}
	return (NULL);
}
