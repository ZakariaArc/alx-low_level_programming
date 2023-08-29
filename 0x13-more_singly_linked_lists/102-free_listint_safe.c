#include "lists.h"
#include <stdlib.h>
/**
 * free_listint_safe - frees a linked list, handling loops
 * @h: a pointer to the head of the list
 * Return: the size of the list that was freed
 */

size_t free_listint_safe(listint_t **h)
{
	size_t count = 0;
	listint_t *current = *h, *next;

	while (current != NULL)
	{
		next = current->next;
		free(current);
		count++;
		if (next >= current)
		{
			*h = NULL;
			break;
		}
		current = next;
	}
	*h = NULL;
	return (count);
}
