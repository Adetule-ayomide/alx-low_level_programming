#include "lists.h"

/**
 * list_len - The length
 * @h: Pointer
 * Return: num_el
 */

size_t list_len(const list_t *h)
{
	size_t num_el = 0;

	while (h != NULL)
	{
		h = h->next;
		num_el++;
	}

	return (num_el);
}
