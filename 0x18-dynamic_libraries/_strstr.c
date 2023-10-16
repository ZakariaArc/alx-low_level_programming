#include "main.h"
#include <stddef.h>
/**
 * _strstr - locates a substring
 * @haystack: the string to be searched
 * @needle: the substring to be located
 * Return: the pointer to the beginning of the located substring,
 *         or NULL if the substring is not found
 */

char *_strstr(char *haystack, char *needle)
{
	while (*haystack != '\0')
	{
		char *start = haystack;
		char *pattern = needle;

		while (*pattern == *haystack && *pattern != '\0' && *haystack != '\0')
		{
			pattern++;
			haystack++;
		}
		if (*pattern == '\0')
			return (start);
		haystack = start + 1;
	}
	return (NULL);
}
