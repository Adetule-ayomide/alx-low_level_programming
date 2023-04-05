#include "lists.h"

/**
* listint_len - Struct node variable in the prototype
* @h: Pointer the next node
* Return: numOfElement
*/

size_t listint_len(const listint_t *h)
{
	size_t num_el;

	num_el = 0;

	while (h != NULL)
	{
		h = h->next;
		num_el++;
	}

	return (num_el);
}
