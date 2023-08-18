#include "lists.h"

/**
 * dlistint_len - function that returns the number of elements in a linked
 * @h: a pointer to head node
 * Return: the number of element
 */

size_t dlistint_len(const dlistint_t *h)
{
	size_t len_count = 0;

	while (h != NULL)
	{
		h = h->next;
		len_count++;
	}

	return (len_count);
}
