#include "main.h"
#include <stdlib.h>
/**
 * _calloc - allocates memory for an array and initializes it to zero
 * @nmemb: number of elements in the array
 * @size: size of each element in bytes
 * Return: a pointer to the allocated memory, or NULL on failure
 */

void *_calloc(unsigned int nmemb, unsigned int size)
{
	unsigned int total_size = nmemb * size;
	char *ptr, *byte_ptr;
	unsigned int i;

	if (nmemb == 0 || size == 0)
		return (NULL);

	ptr = malloc(total_size);

	if (ptr == NULL)
		return (NULL);

	byte_ptr = ptr;
	for (i = 0; i < total_size; i++)
		byte_ptr[i] = 0;

	return (ptr);
}
