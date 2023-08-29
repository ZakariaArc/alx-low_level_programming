#ifndef _LISTS
#define _LISTS
#include <stddef.h>
/**
 * struct listint_s - the singly linked list
 * @n: an integer
 * @next: the points to the next node
 * Description: the singly linked list node structure
 */

typedef struct listint_s
{
	int n;
	struct listint_s *next;
} listint_t;

size_t print_listint(const listint_t *h);
size_t listint_len(const listint_t *h);

#endif
