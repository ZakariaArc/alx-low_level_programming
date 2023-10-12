#include "lists.h"
#include <stdlib.h>
/**
 * free_dlistint - frees a dlistint_t list
 * @head: the pointer to the head of the linked list
 */

void free_dlistint(dlistint_t *head)
{
	dlistint_t *current, *next;

	current = head;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
}
